#include "BehaviourHerbivorousEat.h"
#include "SimConfig.h"
#include "Cell.h"
#include "Animal.h"

BehaviourApplicationResult BehaviourHerbivorousEat::Apply() {
    if (animal->satiety >= satiety_hungry) return BehaviourApplicationResult::R_CONTINUE;
    if (animal->GetCell()->GetGrass() < min_grass_for_herbivorous) return BehaviourApplicationResult::R_CONTINUE;
    i16 dif = animal->GetCell()->ConsumeGrass(satiety_max - animal->satiety);
    animal->satiety += dif;
    return BehaviourApplicationResult::R_FINISH;
}