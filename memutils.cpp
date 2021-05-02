#include <iostream>
#include "memutils.h"
#include <vector>

uintptr_t findDMAAddy(uintptr_t base,const std::vector<uintptr_t>& offsets){

    uintptr_t addr = base;
    int i;
    for(i=0;i<offsets.size()-1;i++){
        addr = *(uintptr_t*)(addr + offsets[i]);
    }
    addr += offsets[i];
    return addr;
}
