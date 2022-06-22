#pragma once

class Vector {
public:
	float x, y, z;
	__forceinline Vector operator*(float mult);
};

// TODO: What? Where did I copy this from?
__forceinline Vector Vector::operator*(float mult) {
	Vector res;
	res.x = x * mult;
	res.y = y * mult;
	res.z = z * mult;
	return res;
}