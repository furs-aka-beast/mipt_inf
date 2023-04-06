#pragma once
#include"Animal.h"
#include"Strategy.h"

class Predator : public Animal {
	void Tick();
	Strategy* GetStrategies();
	Animal* Clone() override;
};