#include "BehaviourPredatorEat.h"
#include "SimConfig.h"
#include "Cell.h"
#include "Field.h"
#include "Types.h"
#include "Animal.h"
#include "Utils.h"

BehaviourApplicationResult BehaviourPredatorEat::Apply() {
    if (animal->satiety >= satiety_hungry) return BehaviourApplicationResult::R_CONTINUE;
    Coords crd = animal->GetCell()->GetCoords();
    Coords target_crd;
    for (i16 i = 0; i < 4; i++){
    	target_crd = crd;
    	switch(i){
    	    case 0: target_crd.x++; break;
    	    case 1: target_crd.x--; break;
    	    case 2: target_crd.y++; break;
    	    case 3: target_crd.y--; break;
    	}
    	Cell* target = animal->GetCell()->GetField()->GetCellByCoord(target_crd);
        if (target->GetEntity() != nullptr){
            target->GetEntity()->Kill();
            
            animal->GetCell()->SetEntity(nullptr);
            animal->SetCell(target);
            target->SetEntity(animal);
        
            animal->satiety = satiety_max;
            
            return BehaviourApplicationResult::R_FINISH;
        }
    }
    return BehaviourApplicationResult::R_CONTINUE;
}
