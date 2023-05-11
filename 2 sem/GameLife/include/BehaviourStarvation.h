#pragma once
#include "Behaviour.h"

class BehaviourStarvation : public Behaviour {
public:
    using Behaviour::Behaviour;
    BehaviourApplicationResult Apply() override;
};