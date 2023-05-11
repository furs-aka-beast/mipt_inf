#pragma once
#include"Animal.h"
#include"Behaviour.h"

class Cell;

class Predator : public Animal {
	public:
	Predator(SimManager* mgr, Cell* cell, i16 satiety);
	Predator(SimManager* mgr, Cell* cell);
	void Clone(Coords) override;
	void Render() override;
};