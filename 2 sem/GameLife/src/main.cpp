#include "Field.h"
#include "SimConfig.h"
#include "Utils.h"
#include "SimManager.h"
#include <thread>
#include <chrono>

int main() {
    SimManager mgr;

    while (true) {
        mgr.Step();
        std::this_thread::sleep_for(time_between_ticks);
    }
}