#include "XmlJoint.h"
#include <string>
#include <iostream>

namespace Loader
{
	using namespace std;
	XmlJoint::XmlJoint()
	{
		type = "FreeJoint", name = "", parent_name = "None";
		xSize = 0., ySize = 0., zSize = 0., mass = 0., lowerLimit = 0., upperLimit = 0.;

		Body = Offset(), Joint = Offset();
	}

	XmlJoint::XmlJoint(string type, string name, string parent_name,
		float xSize, float ySize, float zSize, float mass,
		Offset Body, Offset Joint,
		float lowerLimit, float upperLimit) :
		type(type), name(name), parent_name(parent_name),
		xSize(xSize), ySize(ySize), zSize(zSize), mass(mass),
		Body(Body), Joint(Joint),
		lowerLimit(lowerLimit), upperLimit(upperLimit)
	{

	}

	XmlJoint::~XmlJoint()
	{
	}

	void XmlJoint::print()
	{
		if (type == "FreeJoint")
			cout << "\t<Joint type=\"" << type << "\" name=\"" << name << "\" parent_name=\"" << parent_name << "\" size=\"" << xSize << " " << ySize << " " << zSize << "\" mass=\"" << mass << "\">" << endl;
		else if (type=="RevoluteJoint")
			cout << "\t<Joint type=\"" << type << "\" name=\"" << name << "\" parent_name=\"" << parent_name << "\" size=\"" << xSize << " " << ySize << " " << zSize << "\" mass=\"" << mass << "\" axis=\"1 0 0 \">" << endl;

		cout << "\t\t<BodyPosition linear=\"1 0 0 0 1 0 0 0 1\" translation=\"" << Body.x << " " << Body.y << " " << Body.z << "\"></BodyPosition>" << endl;
		cout << "\t\t<JointPosition linear=\"1 0 0 0 1 0 0 0 1\" translation=\"" << Joint.x << " " << Joint.y << " " << Joint.z << "\"></JointPosition>" << endl;
		
		if (type == "RevoluteJoint")
			cout << "\t\t<Limit lower=\"" << lowerLimit << "\" upper=\"" << upperLimit << "\"></Limit>" << endl;

		cout << "\t</Joint>" << endl;
	}
}