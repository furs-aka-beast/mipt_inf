#pragma once
#include "Behaviour.h"

class BehaviourRandomWalk : public Behaviour {
public:
    using Behaviour::Behaviour;
    BehaviourApplicationResult Apply() override;
};