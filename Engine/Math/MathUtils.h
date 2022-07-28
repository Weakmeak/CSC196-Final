#pragma once

//#ifndef __MATHUTILS_H__
//#define __MATHUTILS_H__

namespace Math {
	int sqr(int v);
	inline int half(int v) {return v / 2;};

	inline float DegToRad(float degrees) { return (degrees / 180) * 3.1415926535; }
	inline float RadToDeg(float radians) { return (radians / 3.1415926535) * 180; }
}

//#endif