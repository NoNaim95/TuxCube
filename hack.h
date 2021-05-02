#include "entity.h"
#include "offsets.h"
#include "vector"
#include "memutils.h"


struct hack{
    hack();
    ~hack();
    void update_enttlist();
    bool isEnttlistCorrupted();
    int entitynum;
    std::vector<Entity*> enttlist;
};
