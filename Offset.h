#pragma once
namespace BVH
{
	class Offset
	{
	public:
		Offset();
		Offset(float _x, float _y, float _z);
		virtual ~Offset();

		float x, y, z;
	};

}