#pragma once
#include"Animal.h"
#include"Behaviour.h"

class Predator : public Animal {
	void Tick();
	Behaviour* GetStrategies();
	Animal* Clone() override;
};