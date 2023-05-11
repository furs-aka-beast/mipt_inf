#include"Cell.h"
#include"RenderConfig.h"
#include<iostream>
#include "SimConfig.h"


void Cell::Init(Coords pos, Field * area) {
    coordinates = pos;
    entity = nullptr;
    n_grass = 0;
    field = area;
}

void Cell::SetEntity(Entity* ent){
    entity = ent;
}


Entity* Cell::GetEntity() {
    return entity;
}

i16 Cell::GetGrass() {
    return n_grass;
}

i16 Cell::ConsumeGrass(i16 max) {
    if (max > n_grass) {
        max = n_grass;
    }
    n_grass -= max;
    return max;
}

void Cell::Tick(){
    if (entity == nullptr) {
        n_grass += grass_inc;
        if (n_grass > grass_max) {
            n_grass = grass_max;
        }
    }
}

void Cell::Render() {
    if (entity == nullptr) {
        std::cout << render_strings::empty_space;
    } else {
        entity->Render();
    }
}

Coords Cell::GetCoords() {
    return coordinates;
}

Field* Cell::GetField() {
    return field;
}