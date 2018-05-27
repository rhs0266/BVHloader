#pragma once
#include "XmlJoint.h"
#include <string>
#include <vector>
namespace Loader
{
	class Xml
	{
	public:
		Xml();
		~Xml();

		void addJoint(std::string type, std::string name, std::string parent_name,
			float xSize, float ySize, float zSize, float mass,
			Offset Body, Offset Joint,
			float lowerLimit, float upperLimit);


		void print();

		std::string name = "Humanoid";
		std::vector<Loader::XmlJoint> Joints;

	};

}