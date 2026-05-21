#pragma once
#include "Apartment.h"

struct floor
{
	Apartment* apartments;
	size_t count;
	size_t capacity;
};

void addApartment(floor& floor, Apartment& apartment);
void removeApartment(floor& floor, size_t index);


struct house
{
	floor* floors;
	size_t count;
};

void addFloor(house& house, floor& floor);