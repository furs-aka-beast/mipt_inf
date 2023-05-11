#include "Field.h"
#include "SimConfig.h"
#include "Utils.h"
#include "SimManager.h"
#include <thread>
#include <chrono>

int main() {
    using namespace std::chrono_literals;
    SimManager mgr;

    while (true) {
        mgr.Step();
        std::this_thread::sleep_for(150ms);
    }
}