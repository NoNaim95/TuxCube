#include "entity.h"
#include "offsets.h"

Entity::Entity(uintptr_t base){
    this->base = (int*)base;
    this->health = (int*)(base + offsets::ihealth);
    this->team = (int*)(base + offsets::team);
    this->name = (char*) (base + offsets::name);
    this->rifleammo = (int*) (base + offsets::rifleammo);
    this->coords = (Vec3*) (base + offsets::coordVec);
    this->viewangles = (Vec2*) (base + offsets::viewAngleVec);
}

void Entity::aimToEntity(Entity* ent) {
	float pitch = this->coords->GetPitchAngle(ent->coords);
	float yaw = this->coords->GetYawAngle(ent->coords);
	Vec2 en = { yaw, pitch };
    *this->viewangles = en;
}


Entity* Entity::getNearestEnt(std::vector<Entity*> enttlist, bool bMustBeEnemy) {
	int ii = 1;
	float mindist = 100000000.f;
	for (int i = 1; i < enttlist.size() ; i++) {

        printf("i = %d\n",i);
        //printf("0x%x\n",enttlist[i]);
		if (*enttlist[i]->health < 0 || (bMustBeEnemy && (*enttlist[i]->team == *this->team)))
			continue;
        puts("checking i");

		float x = this->coords->DistanceFrom(enttlist[i]->coords);
		if (x < mindist) {
			mindist = x;
			ii = i;
		}
	}
	printf("nearest ent is %s and he has %d Health\n", enttlist[ii]->name,*enttlist[ii]->health);

	return enttlist[ii];
}

