//#include <stdio.h>
//#include "Bvh.h"
//#include "Xml.h"
//using namespace Loader;
//using namespace std;
//
//Joint* findJointByName(string name,Joint *joint){
//    if (joint->name == name){
//        return joint;
//    }
//    for (auto &child : joint->children){
//        Joint* res = findJointByName(name, child);
//        if (res != NULL) return res;
//    }
//    return NULL;
//}
//
//Xml* bvhToXml(){
//    Bvh *bvh = new Bvh;
//    bvh->load("02_01_1.bvh");
//    bvh->jointRecursiveCall(bvh->getRootJoint());
///*
// * 		void addJoint(std::string type, std::string name, std::string parent_name,
//			float xSize, float ySize, float zSize, float mass,
//			Offset Body, Offset Joint,
//			float lowerLimit, float upperLimit);
// */
//
//    Xml *xml = new Xml;
//    Offset totalLen = Offset();
//    float padding = 0.03;
//
//    Joint* neck = findJointByName("Neck", bvh->getRootJoint());
//    Joint* leftUpLeg = findJointByName("LeftUpLeg", bvh->getRootJoint());
//    Joint* leftLeg = findJointByName("LeftLeg", bvh->getRootJoint());
//    Joint* leftFoot = findJointByName("LeftFoot", bvh->getRootJoint());
//    Joint* leftToeBase = findJointByName("LeftToeBase", bvh->getRootJoint());
//
//    Offset torsoOffset = neck->coord - leftUpLeg->coord;
//    Offset thighOffset = leftUpLeg->coord - leftLeg->coord;
//    Offset kneeOffset = leftLeg->coord - leftFoot->coord;
//    Offset footOffset = leftFoot->coord - leftToeBase->coord;
//
//    // Torso
//    xml->addJoint("FreeJoint", "Torso", "None",
//                  0.0, torsoOffset.y, torsoOffset.y/2, 70.0,
//                  Offset(0, totalLen.y - torsoOffset.y/2, 0),
//                  Offset(0, 0, 0),
//                  0, 0);
//
//    // ThighR
//    xml->addJoint("RevoluteJoint", "ThighR", "Torso",
//                  0, thighOffset.y, thighOffset.y/4, 5.0,
//                  Offset(0, totalLen.y - torsoOffset.y - thighOffset.y/2, 0),
//                  Offset(0, totalLen.y - torsoOffset.y, 0),
//                  -1.4, 2.6);
//
//    // KneeR
//    xml->addJoint("RevoluteJoint", "KneeR", "ThighR",
//                  0, kneeOffset.y, kneeOffset.y/4, 4.0,
//                  Offset(0, totalLen.y - torsoOffset.y - thighOffset.y - kneeOffset.y/2, 0),
//                  Offset(0, totalLen.y - torsoOffset.y - thighOffset.y, 0),
//                  -1.57, 0.2);
//
//
//    // FootR
//    xml->addJoint("RevoluteJoint", "FootR", "KneeR",
//                  0, footOffset.y, footOffset.y*3.2, 4.0,
//                  Offset(0, totalLen.y - torsoOffset.y - thighOffset.y - kneeOffset.y - footOffset.y/2, 0),
//                  Offset(0, totalLen.y - torsoOffset.y - thighOffset.y - kneeOffset.y, 0),
//                  -1.4, 0.5);
//
//    // ThighL
//    xml->addJoint("RevoluteJoint", "ThighL", "Torso",
//                  0, thighOffset.y, thighOffset.y/4, 5.0,
//                  Offset(0, totalLen.y - torsoOffset.y - thighOffset.y/2, 0),
//                  Offset(0, totalLen.y - torsoOffset.y, 0),
//                  -1.4, 2.6);
//
//    // KneeL
//    xml->addJoint("RevoluteJoint", "KneeL", "ThighL",
//                  0, kneeOffset.y, kneeOffset.y/4, 4.0,
//                  Offset(0, totalLen.y - torsoOffset.y - thighOffset.y - kneeOffset.y/2, 0),
//                  Offset(0, totalLen.y - torsoOffset.y - thighOffset.y, 0),
//                  -1.57, 0.2);
//
//    // FootL
//    xml->addJoint("RevoluteJoint", "FootL", "KneeL",
//                  0, footOffset.y, footOffset.y*3.2, 4.0,
//                  Offset(0, totalLen.y - torsoOffset.y - thighOffset.y - kneeOffset.y - footOffset.y/2, 0),
//                  Offset(0, totalLen.y - torsoOffset.y - thighOffset.y - kneeOffset.y, 0),
//                  -1.4, 0.5);
//
//    return xml;
//}