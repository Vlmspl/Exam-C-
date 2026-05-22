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
        printf("9. Print apartment\n");
        printf("10. Clear house\n");
        printf("0. Exit\n");

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
            size_t floor_index;
            printf("Floor index: ");
            cin >> floor_index;

            if (floor_index < house.count)
            {
                Apartment ap{};
                ap.residents = nullptr;
                ap.count = 0;

                addApartment(house.floors[floor_index], ap);
            }
        }

        else if (choice == 4)
        {
            size_t floor_index, apartment_index;
            printf("Floor index: ");
            cin >> floor_index;
            printf("Apartment index: ");
            cin >> apartment_index;

            if (floor_index < house.count && apartment_index < house.floors[floor_index].count)
            {
                char temp[128];
                int age;

                printf("Name: ");
                cin >> temp;

                printf("Age: ");
                cin >> age;

                Text text = create(temp);

                addResident(house.floors[floor_index].apartments[apartment_index], text, age);
            }
        }

        else if (choice == 5)
        {
            size_t floor_index, apartment_index, resident_index;
            printf("Floor / apartment / resident index: ");
            cin >> floor_index >> apartment_index >> resident_index ;

            if (floor_index < house.count &&
                apartment_index < house.floors[floor_index].count)
            {
                removeResident(house.floors[floor_index].apartments[apartment_index], resident_index);
            }
        }

        else if (choice == 6)
        {
            size_t floor_index, apartment_index;
            printf("Floor / apartment index: ");
            cin >> floor_index >> apartment_index;

            if (floor_index < house.count)
            {
                removeApartment(house.floors[floor_index], apartment_index);
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
            size_t floor_index, apartment_index;
            printf("Floor / apartment index: ");
            cin >> floor_index >> apartment_index;

            if (floor_index < house.count &&
                apartment_index < house.floors[floor_index].count)
            {
                printApartment(house.floors[floor_index].apartments[apartment_index]);
            }
        }

        else if (choice == 10)
        {
            clearHouse(house);
            printf("House cleared.\n");
        }
    }

    clearHouse(house);

    return 0;
}