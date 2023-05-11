#pragma once
class Cell;
class SimManager;
enum struct EntityState {
	S_ALIVE,
	S_DEAD
};

class Entity {
public:
	Entity(SimManager *man, Cell* cur_cell);
	virtual void Tick() = 0;
	virtual void Render() = 0;
	Cell* GetCell();
	void SetCell(Cell* new_cell);
	virtual ~Entity() = default;
	virtual void Kill();
	EntityState GetState() const;
	SimManager * GetManager();
protected:
	Cell* current_cell;
	EntityState state;
	SimManager * manager;
};