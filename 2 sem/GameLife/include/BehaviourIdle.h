#pragma once
#include "Behaviour.h"

class BehaviourIdle : public Behaviour {
public:
    using Behaviour::Behaviour;
    BehaviourApplicationResult Apply() override;
};