#include"Predator.h"
#include"BehaviourPredatorEat.h"
#include"BehaviourRandomWalk.h"
#include"BehaviourStarvation.h"
#include"BehaviourIdle.h"
#include"BehaviourMitosis.h"
#include"RenderConfig.h"
#include "Utils.h"
#include "Cell.h"
#include "SimManager.h"
#include "SimConfig.h"
#include "Coords.h"
#include <iostream>

Predator::Predator(SimManager* mgr, Cell* cell, i16 sat): Animal(mgr, cell, sat) {
    behaviours = {
        new BehaviourStarvation(this), 
        new BehaviourMitosis(this), 
        new BehaviourPredatorEat(this),
        new BehaviourRandomWalk(this),
        new BehaviourIdle(this)
        };
} 

Predator::Predator(SimManager * mgr, Cell * cell) : Predator(mgr, cell, satiety_default) {}

void Predator::Render() {
    std::cout << render_strings::predator;
}

void Predator::Clone(Coords target) {
    GetManager()->Spawn<Predator, i16>(target, satiety / 2);
    satiety /= 2;
}
