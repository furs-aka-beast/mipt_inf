#include"Animal.h"
#include"Utils.h"
#include"Behaviour.h"
#include "SimConfig.h"
#include "SimManager.h"


Animal::Animal(SimManager* man, Cell* cell, i16 sat) : Entity(man, cell), satiety(sat) {}
Animal::Animal(SimManager* man, Cell* cell) : Entity(man, cell), satiety(satiety_default) {}


void Animal::Tick() {
    for (auto i : behaviours) {
        if (i->Apply() == BehaviourApplicationResult::R_FINISH) {
            return;
        }
    }
    ASSERT(false);
}

Animal::~Animal() {
    for (auto behaviour : behaviours) {
        delete behaviour;
    }
}