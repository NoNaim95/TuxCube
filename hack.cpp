#include "hack.h"
#include "entity.h"
#include <unistd.h>


hack::hack(){
    this->entitynum = *(int*)findDMAAddy(0x400000, {offsets::entitynum});
    Entity::entnum = this->entitynum;
    this->enttlist.push_back(new Entity(findDMAAddy(0x400000, {offsets::localplayerptr, 0x0})));
    for(int i=1; i < entitynum;i++){
        this->enttlist.push_back(new Entity(findDMAAddy(0x400000, {offsets::enttlistptr, (uintptr_t)i*8,0x0 })));
    }
}
hack::~hack(){
    for(int i=0;i<this->entitynum;i++){
        delete this->enttlist[i];
    }
}

void hack::update_enttlist(){
    this->entitynum = *(int*)findDMAAddy(0x400000, {offsets::entitynum});
        Entity::entnum = this->entitynum;

        printf("%d players in Lobby rn!\n",this->entitynum);
        //push localplayer to in the enttlist
        this->enttlist.clear();
        this->enttlist.push_back(new Entity(findDMAAddy(0x400000, {offsets::localplayerptr, 0x0})));

        //for maxentitynum see if it is valid memory (due to leaves)
        for(int i=1; i < this->entitynum;i++){

            // checks if particular pointer is dead or not
                //push entity if valid 
            printf("gonna base is = 0x%x, gonna look at first 4 bytes (dereferencing)\n", (int*)findDMAAddy(0x400000, {offsets::enttlistptr, (uintptr_t)i*8,0x0 }));
            if((int*)findDMAAddy(0x400000, {offsets::enttlistptr, (uintptr_t)i*8,0x0 }) && *(int*)findDMAAddy(0x400000, {offsets::enttlistptr, (uintptr_t)i*8,0x0 })){
                printf("pushed %d\n", i);
                this->enttlist.push_back(new Entity(findDMAAddy(0x400000, {offsets::enttlistptr, (uintptr_t)i*8,0x0 })));
            }    
        //}

    }
}


bool hack::isEnttlistCorrupted(){
    for(int i=1;i < this->entitynum;i++){
        if(!(int*)findDMAAddy(0x400000, {offsets::enttlistptr, (uintptr_t)i*8,0x0 }) || !*(int*)findDMAAddy(0x400000, {offsets::enttlistptr, (uintptr_t)i*8,0x0 }))
            return true;
        else
            return false;
    }

}
