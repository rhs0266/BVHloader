#pragma once
#include "BvhJoint.h"

namespace Loader
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