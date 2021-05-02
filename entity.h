#pragma once
#include <iostream>
#include <vector>
#include "Vec3.h"


struct Entity{
    Entity(uintptr_t base);
    static inline int entnum;
    void aimToEntity(Entity* ent);
    Entity* getNearestEnt(std::vector<Entity*> enttlist, bool bMustBeEnemy = true);
    int* base;
    int* health;
    int* rifleammo;
    int* team;
    char* name;
    
    Vec2* viewangles;
    Vec3* coords;
    Vec3* cameracoords;
};
