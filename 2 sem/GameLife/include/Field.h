#pragma once
#include"Cell.h"

class Field {
public:
	Field() = delete;
	Field(i16 n, i16 m);
	void Tick();
	void Render();
	Cell** cells;
	~Field();
	Field(const Field& rfk) = delete;
	Field& operator=(const Field& rfk) = delete;
	Field(Field&& rfk) = delete;
	Field& operator=(Field&& rfk) noexcept = delete;
	Cell* GetCellByCoord(Coords crd);
protected:
    i16 height;
    i16 width;
};