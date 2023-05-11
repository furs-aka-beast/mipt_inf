#pragma once
#include <iostream>

void PrintToDo(const char* file, int line, const char* msg);
void PrintError(const char* file, int line, const char* msg);

#define TODO(msg) PrintToDo(__FILE__, __LINE__, #msg)
#define ASSERT(stmt) do {\
                        if (!(stmt)) {\
                            PrintError(__FILE__, __LINE__, "Assertion failed: " #stmt);\
                            throw std::runtime_error("Assertion failed"); \
                            }\
                        } while (0)
