#pragma once
#include <stdio.h>
namespace Loader
{
	class Motion
	{
	public:
		Motion();
		~Motion();

		unsigned int num_frames;			// number of frames
		unsigned int num_motion_channels;	// number of motion channels 
		float* data;						// motion float data array
	};

}