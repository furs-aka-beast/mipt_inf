#pragma once
#include "Behaviour.h"

class BehaviourMitosis : public Behaviour {
public:
    using Behaviour::Behaviour;
    BehaviourApplicationResult Apply() override;
};