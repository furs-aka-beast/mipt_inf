#include "SimManager.h"
#include "SimConfig.h"
#include "Utils.h"
#include "Coords.h"
#include "Herbivorous.h"

SimManager::SimManager() {
    field = new Field(field_h, field_w);

    //Herbivorous * dolly = new Herbivorous(this, field->GetCellByCoord({5, 5}));
    Spawn<Herbivorous>({5, 5});
    //entities.push_back(dolly);
    //field->GetCellByCoord({5, 5})->SetEntity(dolly);
}

SimManager::~SimManager() {
    std::cout << "Good night, sweet prince\n";
    delete field;
}

void SimManager::Step() {
    // 1. Tick entites
    size_t index_max = entities.size();
    for (size_t index = 0; index < index_max; ++index) {
        auto& entptr = entities[index];
        //std::cerr << entptr << " [state=" << (entptr->GetState()==EntityState::S_ALIVE) << "  mgr= "<< entptr->GetManager() <<", cell= " << entptr->GetCell() <<"]\n";

        entptr->Tick();
    }

    // 2. Tick cells (let field do it)
    field->Tick();

    // 3. Render
    field->Render();

    // 4. Bury dead entities
    {
        size_t read_ix = 0, write_ix = 0;
        while (read_ix < entities.size()) {
            if (entities[read_ix]->GetState() == EntityState::S_ALIVE) {
                entities[write_ix] = entities[read_ix];
                ++write_ix;
            } else {
                delete entities[read_ix];
            }
            ++read_ix;
        }
        entities.resize(write_ix);
        std::cerr << "Done with funerals. Processed " << read_ix 
                  << " entities, alive: " << write_ix << "; buried: " 
                  << (read_ix - write_ix) << "\n";
    }

}
