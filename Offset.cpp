#include "Offset.h"


namespace Loader
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

	Offset Offset::operator+(const Offset& rhs) {
		return Offset(x + rhs.x, y + rhs.y, z + rhs.z);
	}

	Offset Offset::operator-(const Offset& rhs) {
		return Offset(x - rhs.x, y - rhs.y, z - rhs.z);
	}

	Offset Offset::operator/(const float& rhs){
		return Offset(x/rhs, y/rhs, z/rhs);
	}
}