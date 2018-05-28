#include "Xml.h"

#include <iostream>
namespace Loader
{
	Xml::Xml()
	{
		Joints.clear();
	}


	Xml::~Xml()
	{
	}

	void Xml::addJoint(std::string type, std::string name, std::string parent_name,
		float xSize, float ySize, float zSize, float mass,
		Offset Body, Offset Joint,
		float lowerLimit, float upperLimit)
	{
		Joints.push_back(Loader::XmlJoint(type, name, parent_name, xSize, ySize, zSize, mass, Body, Joint, lowerLimit, upperLimit));
	}

	void Xml::print() {
		using namespace std;
		cout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
		cout << "<Skeleton name = \"" << name << "\">" << endl;

		for (auto &joint : Joints)
			joint.print();

		cout << "</Skeleton>";
	}

}