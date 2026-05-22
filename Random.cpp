#include "Random.h"
#include <iostream>

const char* names[] = {
	"Alex", "Ivan", "Max", "Oleg", "Dima", "Artem",
	"Philip", "Yarik", "Zakhar"
};

const char* randName()
{
	return names[rand() % 9];
}

void fillHouseRandom(House& house, size_t floorsCount, size_t maxApartments, size_t maxResidents)
{
	clearHouse(house);
	house.count = floorsCount;
	house.floors = new Floor[floorsCount];

	for (size_t i = 0; i < floorsCount; i++)
	{
		Floor& floor = house.floors[i];

		floor.count = 1 + rand() % maxApartments;
		floor.apartments = new Apartment[floor.count];

		for (size_t j = 0; j < floor.count; j++)
		{
			Apartment& ap = floor.apartments[j];

			ap.count = 1 + rand() % maxResidents;
			ap.residents = new Resident[ap.count];

			for (size_t k = 0; k < ap.count; k++)
			{
				Resident& r = ap.residents[k];

				r.name = create(randName());
				r.age = 10 + rand() % 70; // min: 10, max: 80
			}
		}
	}
}