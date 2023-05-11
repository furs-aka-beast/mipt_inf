#include"BehaviourStarvation.h"
#include"SimConfig.h"
#include "Animal.h"

BehaviourApplicationResult BehaviourStarvation::Apply() {
    animal->satiety-= satiety_per_tick;
    if (animal->satiety < 0) {
        animal->Kill();
        return BehaviourApplicationResult::R_FINISH;
    }
    return BehaviourApplicationResult::R_CONTINUE;
}