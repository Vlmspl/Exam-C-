#pragma once
#include "Apartment.h"

struct Floor
{
	Apartment* apartments;
	size_t count;
	size_t capacity;
};

void addApartment(Floor& floor, Apartment& apartment);
void removeApartment(Floor& floor, size_t index);


struct House
{
	Floor* floors;
	size_t count;
};

void addFloor(House& house, Floor& floor);