#include <X11/keysym.h>
#include <X11/Xlib.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "memutils.h"
#include "entity.h"
#include "offsets.h"
#include "hack.h"




void* hackthread(void* args){
    getchar();
    hack myhack;

    while(1){
        myhack.update_enttlist();

        if(myhack.enttlist.size() > 1)
            myhack.enttlist[0]->aimToEntity(myhack.enttlist[0]->getNearestEnt(myhack.enttlist,false));

        printf("Number of players in Lobby according to hacknum: %d\n",myhack.entitynum);
        printf("enttlist.size() = %d\n",myhack.enttlist.size());
        for(auto& x : myhack.enttlist){
            printf("Player ingame: %s and his base is = 0x%x\n",x->name,x->base);
        }
        usleep(1000000*0.001);

        printf("\e[1;1H\e[2J");
    }
}


__attribute__((constructor))
    void test(){
        printf("Calling thread...\n");
        pthread_t tid;
        pthread_create(&tid,NULL,&hackthread,NULL);
        printf("Created thread!!!\n");
    }

