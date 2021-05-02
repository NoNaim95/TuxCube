#include <math.h>

typedef struct Vec2{
    float yaw,pitch = 0.f;
}Vec2;

typedef struct Vec3{
    float x,y,z = 0.f;
	Vec3(float x = 0.f, float y = 0.f, float z = 0.f);
	float DistanceFrom(Vec3*);
	float GetYawAngle(Vec3*);
	float GetPitchAngle(Vec3*);
}Vec3;
