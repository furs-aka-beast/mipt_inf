#include"Entity.h"
#include "Cell.h"
#include "SimManager.h"

Entity::Entity(SimManager* man, Cell* cur_cell)
: manager(man), current_cell(cur_cell), state(EntityState::S_ALIVE) {}

SimManager * Entity::GetManager() { 
    return manager;
 }

Cell* Entity::GetCell() {
    return current_cell;
}

void Entity::SetCell(Cell* cell) {
    current_cell = cell;
}

EntityState Entity::GetState() const {
    return state;
}

void Entity::Kill() {
		state = EntityState::S_DEAD;
		if (current_cell != nullptr) {
			current_cell->SetEntity(nullptr);
			current_cell = nullptr;
		}
	}