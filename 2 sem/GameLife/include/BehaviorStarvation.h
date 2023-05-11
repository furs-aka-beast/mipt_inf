#pragma once
#include "Behaviour.h"

class BehaviourStarvation : public Behaviour {
    BehaviourStarvation(Animal * an);
    BehaviourApplicationResult Apply() override;
}