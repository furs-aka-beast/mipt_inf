#include "Utils.h"
#include <iostream>
#include <stdexcept>

void PrintToDo(const char* file, int line, const char* msg) {
    std::cerr << "[ ToDo ] " << msg << " @ " << file << ":" << line << "\n";
}

void PrintError(const char* file, int line, const char* msg) {
    std::cerr << "[ERROR!] " << msg << " @ " << file << ":" << line << "\n";
}