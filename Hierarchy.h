#pragma once
#include "Joint.h"

namespace BVH
{
	class Hierarchy
	{
	public:
		EIGEN_MAKE_ALIGNED_OPERATOR_NEW
		Hierarchy();
		~Hierarchy();

		Joint* rootJoint;
		int num_channels;
	};

}