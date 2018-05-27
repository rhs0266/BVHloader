#pragma once
#include "Offset.h"
#include <vector>
#include <Eigen/Dense>

namespace BVH
{
	class Joint
	{
	public:
		EIGEN_MAKE_ALIGNED_OPERATOR_NEW
		Joint();
		~Joint();

		const char* name = NULL;        // joint name
		Joint* parent = NULL;           // joint parent
		Offset offset;                  // offset data
		Offset size;					// volume size
		unsigned int num_channels = 0;  // num of channels joint has
		short* channels_order = NULL;   // ordered list of channels
		std::vector<Joint*> children;   // joint's children
		Eigen::Matrix4f matrix;         // local transofrmation matrix (premultiplied with parents')
		unsigned int channel_start = 0; // index of joint's channel data in motion array

		Offset rotation;				// rotation information for x, y, z-axis

	};

}