#pragma once
//#include "Animal.h"

class Animal;

enum struct BehaviourApplicationResult {
    R_CONTINUE, R_FINISH
};

class Behaviour {
public:
    virtual BehaviourApplicationResult Apply() = 0;
    Behaviour(Animal * an) : animal(an) {}
protected:
    Animal * animal;
};
