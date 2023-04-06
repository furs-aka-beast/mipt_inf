#pragma once
#include"Entity.h"
#include"Types.h"

class Field;

class Cell {
public:
	Entity* GetEntity();
	i16& GetGrass();
	void Tick();
	void Render();
private:
	Field* field;
	Entity* entity;
	int16_t n_grass;
};