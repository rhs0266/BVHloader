#include "BvhJoint.h"

namespace Loader
{

	Joint::Joint()
	{
		name = NULL;        // joint name
		parent = NULL;           // joint parent
		offset = Offset();                  // offset data
		size = Offset();					// volume size
		num_channels = 0;  // num of channels joint has
		channels_order = NULL;   // ordered list of channels
		children.clear();   // joint's children
		matrix = Eigen::Matrix4f::Identity(4, 4);         // local transofrmation matrix (premultiplied with parents')
		channel_start = 0; // index of joint's channel data in motion array
	}


	Joint::~Joint()
	{
	}

}