#pragma once
#include "Text.h"

struct Resident {
	Text name;
	int age;
};

struct Apartment
{
	Resident* residents;
	size_t count;
};

void addResident(Apartment& apartment, const Text& name, int age);
void printApartment(const Apartment& apartment);
void removeResident(Apartment& apartment, size_t index);