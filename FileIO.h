#pragma once
#include "House.h"

void saveHouse(const House& house, const char* filename);
void loadHouse(House& house, const char* filename);