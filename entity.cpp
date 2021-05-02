#include "entity.h"
#include "offsets.h"

Entity::Entity(uintptr_t base){
    this->base = (int*)base;
    this->health = (int*)(base + offsets::ihealth);
    this->team = (int*)(base + offsets::team);
    this->name = (char*) (base + offsets::name);
    this->rifleammo = (int*) (base + offsets::rifleammo);
    this->coords = (Vec3*) (base + offsets::coordVec);
    this->cameracoords = (Vec3*) (base + offsets::cameracoordVec);
    this->viewangles = (Vec2*) (base + offsets::viewAngleVec);
}

void Entity::aimToEntity(Entity* ent) {
	float pitch = this->cameracoords->GetPitchAngle(ent->cameracoords);
	float yaw = this->cameracoords->GetYawAngle(ent->cameracoords);
	Vec2 en = { yaw, pitch };
    *this->viewangles = en;
}


Entity* Entity::getNearestEnt(std::vector<Entity*> enttlist, bool bMustBeEnemy) {
	int ii = 1;
	float mindist = 100000000.f;
	for (int i = 1; i < enttlist.size() ; i++) {

        printf("First check if I need to consider %s\n",enttlist[i]->name);
        printf("So his health is %d\n",*enttlist[i]->health);
		if (*enttlist[i]->health < 0 || (bMustBeEnemy && (*enttlist[i]->team == *this->team)))
			continue;
        puts("checking i");

		float x = this->cameracoords->DistanceFrom(enttlist[i]->cameracoords);
		if (x < mindist) {
			mindist = x;
			ii = i;
		}
	}
	printf("nearest ent is %s and he has %d Health\n", enttlist[ii]->name,*enttlist[ii]->health);

	return enttlist[ii];
}

