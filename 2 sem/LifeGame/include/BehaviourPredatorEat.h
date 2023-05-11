
#pragma once
#include "Behaviour.h"

class BehaviourPredatorEat : public Behaviour {
public:
    using Behaviour::Behaviour;
    BehaviourApplicationResult Apply() override;
};