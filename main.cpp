#include <stdio.h>
#include "Bvh.h"
#pragma comment (linker,"/STACK:36777216")

using namespace BVH;


Bvh *bvh;

int main() {
	bvh = new Bvh;
	bvh->load("02_01_1.bvh");
	return 0;
}