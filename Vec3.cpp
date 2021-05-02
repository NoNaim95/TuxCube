#include "Vec3.h"

#define PI 3.141592653589793238463

Vec3::Vec3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vec3::DistanceFrom(Vec3* target)
{
	return sqrtf(powf(target->x - x, 2) + powf(target->y - y, 2) + powf(target->z - z, 2));
}

float Vec3::GetYawAngle(Vec3* target)
{
	return atan2f(target->y - y, target->x - x) * (180 / PI) + 90;
}

float Vec3::GetPitchAngle(Vec3* target)
{
	return asin((target->z - z) / DistanceFrom(target)) * (180 / PI);
}
