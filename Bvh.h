#pragma once

#include "Motion.h"
#include "Joint.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>


#define Xposition 0x01
#define Yposition 0x02
#define Zposition 0x04
#define Zrotation 0x10
#define Xrotation 0x20
#define Yrotation 0x40


namespace BVH
{
	class Bvh
	{
	public:
		EIGEN_MAKE_ALIGNED_OPERATOR_NEW
		Bvh();
		~Bvh();

		Joint* loadJoint(std::istream& stream, Joint* parent = NULL);
		void loadHierarchy(std::istream& stream);
		void loadMotion(std::istream& stream);

		///loading
		void load(const std::string& filename);

		/// Loads motion data from a frame into local matrices
		void moveTo(unsigned frame);

		const Joint* getRootJoint() const { return rootJoint; }
		unsigned getNumFrames() const { return motionData.num_frames; }
		
		Joint* rootJoint;
		Motion motionData;
	};

}