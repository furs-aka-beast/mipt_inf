#pragma once
#include "Behaviour.h"

class BehaviourHerbivorousEat : public Behaviour {
public:
    using Behaviour::Behaviour;
    BehaviourApplicationResult Apply() override;
};