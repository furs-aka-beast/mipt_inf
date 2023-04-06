#pragma once
#include"Entity.h"
#include"Types.h"

class Animal : public Entity {
public:
	i16 satiety;
	virtual Animal* Clone();
	virtual void Tick();
};