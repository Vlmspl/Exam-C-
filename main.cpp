#include <iostream>
#include "House.h"
#include "FileIO.h"
#include "Random.h"

using namespace std;

int main()
{
	srand(time(0));

	House house;
	house.floors = nullptr;
	house.count = 0;

	int choice;

	while (true)
    {
        printf("\n===== HOUSE MANAGER =====\n");

        printf("1. Fill random house\n");
        printf("2. Add floor\n");
        printf("3. Add apartment\n");
        printf("4. Add resident\n");
        printf("5. Remove resident\n");
        printf("6. Remove apartment\n");
        printf("7. Save to file\n");
        printf("8. Load from file\n");
        printf("9. Clear house\n");

	    printf("\n--- REPORTS ---\n");

	    printf("10. Print all residents\n");
	    printf("11. Print all apartments\n");
	    printf("12. Print apartment info\n");
	    printf("13. Print floor apartments\n");
	    printf("14. Print apartments by size\n");

        printf("\n0. Exit\n");

        printf("Choice: ");
        cin >> choice;

        if (choice == 0)
            break;

        if (choice == 1)
        {
            size_t floors_count, max_apartments, max_residents;
            printf("Floors / max apartments / max residents: ");
            cin >> floors_count >> max_apartments >> max_residents;

            clearHouse(house);
            fillHouseRandom(house, floors_count, max_apartments, max_residents);
        }

        else if (choice == 2)
        {
            Floor floor{};
            floor.apartments = nullptr;
            floor.count = 0;
            floor.capacity = 0;

            addFloor(house, floor);
        }

        else if (choice == 3)
        {
            int floor_index;
            printf("Floor index: ");
            cin >> floor_index;

            floor_index--;

            if (floor_index >= 0 && (size_t)floor_index < house.count)
            {
                Apartment ap{};
                ap.residents = nullptr;
                ap.count = 0;

                addApartment(house.floors[(size_t)floor_index], ap);
            }
        }

        else if (choice == 4)
        {
            int floor_index, apartment_index;
            printf("Floor index: ");
            cin >> floor_index;
            printf("Apartment index: ");
            cin >> apartment_index;

            floor_index--;
            apartment_index--;

            if (floor_index >= 0 && apartment_index >= 0 &&
                (size_t)floor_index < house.count &&
                (size_t)apartment_index < house.floors[(size_t)floor_index].count)
            {
                char temp[128];
                int age;

                printf("Name: ");
                cin >> temp;

                printf("Age: ");
                cin >> age;

                Text text = create(temp);

                addResident(house.floors[(size_t)floor_index].apartments[(size_t)apartment_index], text, age);
            }
        }

        else if (choice == 5)
        {
            int floor_index, apartment_index, resident_index;
            printf("Floor / apartment / resident index: ");
            cin >> floor_index >> apartment_index >> resident_index;

            floor_index--;
            apartment_index--;
            resident_index--;

            if (floor_index >= 0 && apartment_index >= 0 && resident_index >= 0 &&
                (size_t)floor_index < house.count &&
                (size_t)apartment_index < house.floors[(size_t)floor_index].count)
            {
                removeResident(
                    house.floors[(size_t)floor_index].apartments[(size_t)apartment_index],
                    (size_t)resident_index
                );
            }
        }

        else if (choice == 6)
        {
            int floor_index, apartment_index;
            printf("Floor / apartment index: ");
            cin >> floor_index >> apartment_index;

            floor_index--;
            apartment_index--;

            if (floor_index >= 0 && apartment_index >= 0 &&
                (size_t)floor_index < house.count &&
                (size_t)apartment_index < house.floors[(size_t)floor_index].count)
            {
                removeApartment(house.floors[(size_t)floor_index], (size_t)apartment_index);
            }
        }

        else if (choice == 7)
        {
            char filename[256];
            printf("File name to save: ");
            cin >> filename;

            saveHouse(house, filename);
        }

        else if (choice == 8)
        {
            char filename[256];
            printf("File name to load: ");
            cin >> filename;

            FILE* f = fopen(filename, "rb");
            if (!f)
            {
                printf("File not found.\n");
            }
            else
            {
                fclose(f);

                clearHouse(house);
                loadHouse(house, filename);

                printf("Loaded.\n");
            }
        }

        else if (choice == 9)
        {
            clearHouse(house);
            printf("House cleared.\n");
        }

        else if (choice == 10)
        {
            for (size_t i = 0; i < house.count; i++)
            {
                printf("Floor %zu\n", i + 1);

                for (size_t j = 0; j < house.floors[i].count; j++)
                {
                    printf(" - Apartment %zu\n", j + 1);

                    for (size_t k = 0; k < house.floors[i].apartments[j].count; k++)
                    {
                        Resident& resident = house.floors[i].apartments[j].residents[k];

                        printf("   * %s (%d)\n",
                            resident.name.text,
                            resident.age);
                    }

                    printf("\n");
                }

                printf("\n");
            }
        }

        else if (choice == 11)
        {
            for (size_t i = 0; i < house.count; i++)
            {
                printf("Floor %zu\n", i + 1);

                for (size_t j = 0; j < house.floors[i].count; j++)
                {
                    printf(" - Apartment %zu | Residents: %zu\n",
                        j + 1,
                        house.floors[i].apartments[j].count);
                }

                printf("\n");
            }
        }

        else if (choice == 12)
        {
            int floor_index, apartment_index;
            printf("Floor / apartment index: ");
            cin >> floor_index >> apartment_index;

            floor_index--;
            apartment_index--;

            if (floor_index >= 0 && apartment_index >= 0 &&
                (size_t)floor_index < house.count &&
                (size_t)apartment_index < house.floors[(size_t)floor_index].count)
            {
                printApartment(house.floors[(size_t)floor_index].apartments[(size_t)apartment_index]);
            }
        }

        else if (choice == 13)
        {
            int floor_index;
            printf("Floor: ");
            cin >> floor_index;

            floor_index--;

            if (floor_index >= 0 && (size_t)floor_index < house.count)
            {
                Floor& floor = house.floors[(size_t)floor_index];

                printf("Floor %d:\n", floor_index + 1);

                for (size_t i = 0; i < floor.count; i++)
                {
                    printf(" Apartment %zu | Residents: %zu\n",
                        i + 1,
                        floor.apartments[i].count);
                }
            }
        }

        else if (choice == 14)
        {
            size_t size;
            printf("Apartment size: ");
            cin >> size;

            bool found = false;

            for (size_t i = 0; i < house.count; i++)
            {
                bool floorPrinted = false;

                for (size_t j = 0; j < house.floors[i].count; j++)
                {
                    if (house.floors[i].apartments[j].count == size)
                    {
                        if (!floorPrinted)
                        {
                            printf("Floor %zu\n", i + 1);
                            floorPrinted = true;
                        }

                        printf(" - Apartment %zu\n", j + 1);
                        found = true;
                    }
                }

                if (floorPrinted)
                    printf("\n");
            }

            if (!found)
                printf("No apartments found with size %zu\n", size);
        }
    }

    clearHouse(house);

    return 0;
}