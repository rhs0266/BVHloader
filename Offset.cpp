#include "Offset.h"


namespace BVH
{
	Offset::Offset() :x(0.), y(0.), z(0.)
	{
	}


	Offset::~Offset()
	{
	}

	Offset::Offset(float _x, float _y, float _z) :x(_x), y(_y), z(_z)
	{
	}
}