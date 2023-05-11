#include "Field.h"
#include <iostream>

Field::Field(i16 n, i16 m) {
    height = n;
    width = m;
    cells = new Cell*[n];
    for (int i=0; i < n; ++i) {
        cells[i] = new Cell[m];
    }
    for (int i=0; i < n; ++i){
        for(int j=0; j < m; ++j) {
            cells[i][j].Init({j, i} , this);
        }
    }

}

Field::~Field() {
    for (int i = 0; i < height; ++i) {
        delete[] cells[i];
    }
    delete[] cells;
}

void Field::Tick() {
    for (int i=0; i < height; ++i){
        for(int j=0; j < width; ++j) {
            cells[i][j].Tick();
        }
    }
}

void Field::Render() {
    std::cout << "==================== BEGIN FIELD ====================\n";
    for (int i=0; i < height; ++i){
        for(int j=0; j < width; ++j) {
            cells[i][j].Render();
        }
        std::cout << "\n";
    }
    std::cout << "====================  END  FIELD ====================\n";
}

Cell* Field::GetCellByCoord(Coords crd){
    crd.x = (crd.x + width) % width;
    crd.y = (crd.y + height) % height;
    return &cells[crd.y][crd.x];
}