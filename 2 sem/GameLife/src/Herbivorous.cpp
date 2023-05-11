#include"Herbivorous.h"
#include"BehaviourHerbivorousEat.h"
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
#include<iostream>

Herbivorous::Herbivorous(SimManager* mgr, Cell* cell, i16 sat): Animal(mgr, cell, sat) {
    behaviours = {
        new BehaviourStarvation(this), 
        new BehaviourMitosis(this), 
        new BehaviourHerbivorousEat(this),
        new BehaviourRandomWalk(this),
        new BehaviourIdle(this)
        };
} 

Herbivorous::Herbivorous(SimManager * mgr, Cell * cell) : Herbivorous(mgr, cell, satiety_default) {}

void Herbivorous::Render() {
    std::cout << render_strings::herbivorous;
}

void Herbivorous::Clone(Coords target) {
    GetManager()->Spawn<Herbivorous, i16>(target, satiety / 2);
    satiety /= 2;
}