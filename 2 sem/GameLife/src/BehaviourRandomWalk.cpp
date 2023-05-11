#include "BehaviourRandomWalk.h"
#include "SimConfig.h"
#include "Cell.h"
#include "Types.h"
#include "Field.h"
#include "Animal.h"
#include "Utils.h"
#include <string>
#include <algorithm>

BehaviourApplicationResult BehaviourRandomWalk::Apply() {
    Coords crd = animal->GetCell()->GetCoords();
    Coords target_crd = crd;
    std::string direction = "lrud";
    //shuffle
    for (i16 i = 0; i < 4; i++){
        std::swap(direction[random() % 4], direction[random() % 4]);
    }
    for (i16 i = 0; i < 4; i++){
        target_crd = crd;
        switch(direction[i]){
            case 'l': target_crd.x--; break;
            case 'r': target_crd.x++; break;
            case 'u': target_crd.y--; break;
            case 'd': target_crd.y++; break;
            default: ASSERT(false); break;
        }
        Cell* target = animal->GetCell()->GetField()->GetCellByCoord(target_crd);
        if (target->GetEntity()) continue;
        animal->GetCell()->SetEntity(nullptr);
        animal->SetCell(target);
        target->SetEntity(animal);
        return BehaviourApplicationResult::R_FINISH;
    }
    return BehaviourApplicationResult::R_CONTINUE;
}