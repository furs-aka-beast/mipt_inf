#pragma once
#include"Entity.h"
#include"Types.h"
#include"Coords.h"

class Field;

class Cell {
public:
    Cell() = default;
    void Init(Coords pos, Field * area);
	Entity* GetEntity();
	void SetEntity(Entity* ent);
	i16 GetGrass();
	i16 ConsumeGrass(i16 max);
	void Tick();
	void Render();
	Coords GetCoords();
	Field* GetField();
private:
	Field* field;
	Coords coordinates;
	Entity* entity;
	int16_t n_grass;
};