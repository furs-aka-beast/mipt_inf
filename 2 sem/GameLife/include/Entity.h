#pragma once
class Cell;

class Entity {
public:
	virtual void Tick() = 0;
	virtual void Render() = 0;
	Cell* GetCell();
	void SetCell(Cell* new_cell);
//TODO Type
protected:
	Cell* current_cell;
};