#pragma once
#include"Entity.h"
#include"Types.h"
#include"Behaviour.h"
#include "Coords.h"
#include<vector>

// class Behaviour;
class SimManager;
class Animal : public Entity {
public:
	Animal(SimManager* man, Cell* cell, i16 satiety);
	Animal(SimManager* man, Cell* cell);
    friend class Behaviour;
	i16 satiety;
	virtual void Clone(Coords) = 0;
	virtual void Tick() override;
	~Animal();
protected:
	std::vector<Behaviour*> behaviours;
};