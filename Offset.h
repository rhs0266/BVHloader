#pragma once
namespace Loader
{
	class Offset
	{
	public:
		Offset();
		Offset(float _x, float _y, float _z);
		virtual ~Offset();

		Offset operator+(const Offset& rhs);
		Offset operator-(const Offset& rhs);
		Offset operator/(const float& rhs);

		float x, y, z;
	};

}