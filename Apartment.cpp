#include <iostream>
#include "Apartment.h"

void addResident(Apartment& apartment, const Text& name, const int age)
{
	Resident resident;
	resident.name = name;
	resident.age = age;

	Resident* residents = new Resident[apartment.count+1];
	for (size_t i = 0; i < apartment.count; i++)
	{
		residents[i] = apartment.residents[i];
	}

	residents[apartment.count] = resident;

	delete[] apartment.residents;
	apartment.residents = residents;
	apartment.count++;
}

void printApartment(const Apartment& apartment)
{
	printf("Residents: %zu\n", apartment.count);

	for (size_t i = 0; i < apartment.count; i++)
	{
		const Resident& resident = apartment.residents[i];
		printf("Name: %s | Age: %d\n", resident.name.text, resident.age);
	}
}

void removeResident(Apartment& apartment, size_t index)
{
	if (index >= apartment.count || apartment.count == 0) return;
	Resident* residents = new Resident[apartment.count-1];
	size_t i = 0;

	for (size_t j = 0; j < apartment.count; j++)
	{
		if (j == index) continue;
		residents[i++] = apartment.residents[j];
	}

	delete[] apartment.residents;
	apartment.residents = residents;
	apartment.count--;
}

