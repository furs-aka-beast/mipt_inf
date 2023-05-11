project(LifeGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(sim
    src/Animal.cpp
    src/BehaviourHerbivorousEat.cpp
    src/BehaviourIdle.cpp
    src/BehaviourMitosis.cpp
    src/BehaviourRandomWalk.cpp
    src/BehaviourStarvation.cpp
    src/BehaviourPredatorEat.cpp
    src/Predator.cpp
    src/Cell.cpp
    src/Entity.cpp
    src/Field.cpp
    src/Herbivorous.cpp
    src/SimManager.cpp
    src/Utils.cpp
    src/main.cpp
	)

target_include_directories(sim PUBLIC include)
target_compile_options(sim PUBLIC -g)
