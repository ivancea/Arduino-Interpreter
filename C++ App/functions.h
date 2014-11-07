#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>

std::vector<std::string> split(std::string inicial, char busqueda = ' ', int maxc = -1);
bool equalIgnoreCase(std::string a, std::string b);
bool isDec(std::string num);
void thSleep(uint32_t ms);

#endif // FUNCTIONS_H
