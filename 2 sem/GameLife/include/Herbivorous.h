#pragma once
#include"Animal.h"
#include"Strategy.h"

class Herbivorous : public Animal {
	void Tick();
	Strategy* GetStrategies();
	Animal* Clone() override;
};