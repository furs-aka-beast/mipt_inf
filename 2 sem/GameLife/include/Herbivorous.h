#pragma once
#include"Animal.h"
#include"Behaviour.h"

class Cell;

class Herbivorous : public Animal {
public:
	Herbivorous(SimManager* mgr, Cell* cell, i16 satiety);
	Herbivorous(SimManager* mgr, Cell* cell);
	void Clone(Coords) override;
	void Render() override;
};