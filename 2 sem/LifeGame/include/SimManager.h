#pragma once

#include "Field.h"
#include "Entity.h"
#include "Coords.h"
#include <vector>
#include <iostream>
#include "Animal.h"


class SimManager {
public:
    SimManager();
    SimManager(const SimManager&) = delete;
    SimManager(SimManager&&) = delete;
    SimManager& operator=(const SimManager&) = delete;
    SimManager& operator=(SimManager&&) = delete;
    ~SimManager();

    void Step();

    template<class TEntity, class... Args>
    void Spawn(Coords coord, Args&&... args) {
        TEntity* ent = 
                new TEntity(this, 
                   field->GetCellByCoord(coord), 
                   std::forward<Args>(args)...);
        field->GetCellByCoord(coord)->SetEntity(ent);

        Animal * ani = ent;
        entities.push_back(ent);
    }

private:
    Field* field;
    std::vector<Entity*> entities;
};