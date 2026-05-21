#include "FileIO.h"
#include <iostream>
using namespace std;

void saveHouse(const House& house, const char* filename)
{
	FILE* file = fopen(filename, "wb");

	fwrite(&house.count, sizeof(house.count), 1, file);

	for (size_t i = 0; i < house.count; i++)
	{
		Floor& floor = house.floors[i];

		fwrite(&floor.count, sizeof(floor.count), 1, file);

		for (size_t j = 0; j < floor.count; j++)
		{
			Apartment& apartment = floor.apartments[j];

			fwrite(&apartment.count, sizeof(apartment.count), 1, file);

			for (size_t k = 0; k < apartment.count; k++)
			{
				Resident& resident = apartment.residents[k];

				fwrite(&resident.name.length, sizeof(resident.name.length), 1, file);
				fwrite(resident.name.text, sizeof(char), resident.name.length, file);
				fwrite(&resident.age, sizeof(resident.age), 1, file);
			}
		}
	}
	fclose(file);
}

void loadHouse(House& house, const char* filename)
{
	FILE* file = fopen(filename, "rb");

	fread(&house.count, sizeof(house.count), 1, file);
	house.floors = new Floor[house.count];

	for (size_t i = 0; i < house.count; i++)
	{
		Floor& floor = house.floors[i];

		fread(&floor.count, sizeof(floor.count), 1, file);
		floor.apartments = new Apartment[floor.count];

		for (size_t j = 0; j < floor.count; j++)
		{
			Apartment& apartment = floor.apartments[j];

			fread(&apartment.count, sizeof(apartment.count), 1, file);
			apartment.residents = new Resident[apartment.count];

			for (size_t k = 0; k < apartment.count; k++)
			{
				Resident& resident = apartment.residents[k];

				fread(&resident.name.length, sizeof(resident.name.length), 1, file);

				resident.name.text = new char[resident.name.length+1];
				fread(resident.name.text, sizeof(char), resident.name.length, file);
				resident.name.text[resident.name.length] = '\0';

				fread(&resident.age, sizeof(resident.age), 1, file);
			}
		}
	}

	fclose(file);
}