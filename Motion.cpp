#include "Motion.h"

namespace BVH
{
	Motion::Motion()
	{
		num_frames = 0;				// number of frames
		num_motion_channels = 0;	// number of motion channels 
		data = NULL;				// motion float data array
	}


	Motion::~Motion()
	{
	}
}