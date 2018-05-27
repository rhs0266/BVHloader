#pragma once
#include "Offset.h"
#include <string>
namespace Loader
{
	class XmlJoint
	{
	public:
		XmlJoint();
		XmlJoint(std::string type, std::string name, std::string parent_name,
			float xSize, float ySize, float zSize, float mass,
			Offset Body, Offset Joint,
			float lowerLimit, float upperLimit);
		~XmlJoint();
		
		void print();

		std::string type, name, parent_name;
		float xSize, ySize, zSize, mass, lowerLimit, upperLimit;
		
		Offset Body, Joint;
	};

}