#include "House.h"
using namespace std;

void addApartment(Floor& floor, Apartment& apartment)
{
	Apartment* apartments = new Apartment[floor.count + 1];

	for (size_t i = 0; i < floor.count; i++)
	{
		apartments[i] = floor.apartments[i];
	}

	apartments[floor.count] = apartment;

	delete[] floor.apartments;
	floor.apartments = apartments;

	floor.count++;
}

void removeApartment(Floor& floor, size_t index)
{
	if (index >= floor.count) return;

	Apartment* apartments = new Apartment[floor.count - 1];

	size_t j = 0;

	for (size_t i = 0; i < floor.count; i++)
	{
		if (i == index) continue;
		apartments[j++] = floor.apartments[i];
	}

	delete[] floor.apartments;
	floor.apartments = apartments;

	floor.count--;
}


void addFloor(House& house, Floor& floor)
{
	Floor* floors = new Floor[house.count + 1];

	for (size_t i = 0; i < house.count; i++)
	{
		floors[i] = house.floors[i];
	}

	floors[house.count] = floor;

	delete[] house.floors;
	house.floors = floors;

	house.count++;
}
