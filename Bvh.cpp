#include "Bvh.h"

#define trim(a) remove(a.begin(), a.end(), ' ')

namespace Loader
{
	using namespace std;
	Bvh::Bvh()
	{
		rootJoint = NULL; 
		motionData = Motion();
	}


	Bvh::~Bvh()
	{
	}

	Joint* Bvh::loadJoint(istream& stream, Joint* parent) {
		Joint* joint = new Joint;
		joint->parent = parent;

		// load joint name
		string* name = new string;
		stream >> *name;
		joint->name = name->c_str();

		string tmp;
		//setting local matrix to identity
		joint->matrix = Eigen::Matrix4f::Identity(4, 4);

		static int _channel_start = 0;
		unsigned channel_order_index = 0;

		while (stream.good()) {
			stream >> tmp;
			trim(tmp);

			//loading channels
			char c = tmp.at(0);
			if (c == 'X' || c == 'Y' || c == 'Z') {
				if (tmp == "Xposition")
					joint->channels_order[channel_order_index++] = Xposition;
				if (tmp == "Yposition")
					joint->channels_order[channel_order_index++] = Yposition;
				if (tmp == "Zposition")
					joint->channels_order[channel_order_index++] = Zposition;

				if (tmp == "Xrotation")
					joint->channels_order[channel_order_index++] = Xrotation;
				if (tmp == "Yrotation")
					joint->channels_order[channel_order_index++] = Yrotation;
				if (tmp == "Zrotation")
					joint->channels_order[channel_order_index++] = Zrotation;
			}

			if (tmp == "OFFSET") {
				stream >> joint->offset.x >> joint->offset.y >> joint->offset.z;
			}
			else if (tmp == "CHANNELS") {
				stream >> joint->num_channels;
				motionData.num_motion_channels += joint->num_channels;

				joint->channel_start = _channel_start;
				_channel_start += joint->num_channels;

				joint->channels_order = new short[joint->num_channels];

			}
			else if (tmp == "Joint") {
				Joint* tmp_joint = loadJoint(stream, joint);

				tmp_joint->parent = joint;
				joint->children.push_back(tmp_joint);
			}
			else if (tmp == "End") {
				stream >> tmp >> tmp; // Site{

				Joint* tmp_joint = new Joint;

				tmp_joint->parent = joint;
				tmp_joint->num_channels = 0;
				tmp_joint->name = "EndSite";
				joint->children.push_back(tmp_joint);
				stream >> tmp;
				if (tmp == "OFFSET")
					stream >> tmp_joint->offset.x >> tmp_joint->offset.y >> tmp_joint->offset.z;
				stream >> tmp;
			}
			else if (tmp == "}")
				return joint;
		}
	}
	void Bvh::loadHierarchy(istream& stream) {
		string tmp;
		while (stream.good()) {
			stream >> tmp;
			trim(tmp);
			if (tmp == "ROOT")
				rootJoint = loadJoint(stream);
			else if (tmp == "MOTION")
				loadMotion(stream);
		}
	}
	void Bvh::loadMotion(istream& stream) {
		string tmp;
		while (stream.good()) {
			stream >> tmp;
			trim(tmp);
			if (tmp == "Frames:")
				stream >> motionData.num_frames;
			else if (tmp == "Frame") {
				float frame_time;
				stream >> tmp >> frame_time;

				int num_frames = motionData.num_frames;
				int num_channels = motionData.num_motion_channels;

				//creating motion data array
				motionData.data = new float[num_frames * num_channels];

				cout << num_frames * num_channels << endl;

				for (int frame = 0; frame<num_frames; frame++) {
					for (int channel = 0; channel<num_channels; channel++) {
						float x;
						stringstream ss;
						stream >> tmp; ss << tmp; ss >> x;
						int index = frame * num_channels + channel;
						motionData.data[index] = x;
					}
				}
			}
		}
	}

	void Bvh::load(const string& filename) {
		fstream file;
		file.open(filename.c_str(), ios_base::in);
		if (file.is_open()) {
			string line;
			while (file.good()) {
				file >> line;
				trim(line);
				if (line == string("HIERARCHY"))
					loadHierarchy(file);
				break;
			}
			file.close();
		}
	}

	void Bvh::initCoord() {
		
	}

	void Bvh::moveTo(unsigned frame) {

	}

	Offset rotatePoint(Offset point, Eigen::Quaternionf q) {
		Eigen::Quaternionf p = Eigen::Quaternionf(0, point.x, point.y, point.z);
		p = (q * p) * q.inverse();
		return Offset(p.vec()[0], p.vec()[1], p.vec()[2]);
	}

	void Bvh::reCalculateCoord(Joint* joint, Eigen::Quaternionf q, Joint* from) {
		Eigen::Quaternionf q2;
		if (from != NULL) {
			q2 = joint->q;
			q2 = q2 * q;
			Offset afterRot = rotatePoint(joint->offset, q);
			joint->coord = from->coord + afterRot;
		}

		if (joint->parent != from && joint->parent != NULL) reCalculateCoord(joint->parent, q2, joint);
		for (auto &child : joint->children) {
			if (child != from) reCalculateCoord(child, q2, joint);
		}
	}

	void Bvh::jointRecursiveCall(Joint *joint)
	{
		joint->q = Eigen::Quaternionf();
		if (joint == getRootJoint()) {
			joint->origin_coord = joint->coord = Offset();
		}
		else {
			joint->origin_coord = joint->coord = joint->parent->coord + joint->offset;
		}
		for (auto& child : joint->children)
			jointRecursiveCall(child);
	}
}