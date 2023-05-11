#include "BehaviourMitosis.h"
#include "SimConfig.h"
#include "Cell.h"
#include "Types.h"
#include "Field.h"
#include "Animal.h"
#include "Utils.h"
#include <string>
#include <algorithm>
#include "SimManager.h"


BehaviourApplicationResult BehaviourMitosis::Apply() {
    if (animal->satiety < satiety_mitosis) return BehaviourApplicationResult::R_CONTINUE;
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
        animal->Clone(target_crd);
        
        return BehaviourApplicationResult::R_FINISH;
    }
    return BehaviourApplicationResult::R_CONTINUE;
}