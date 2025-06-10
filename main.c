#include <stdio.h>
#include <string.h>

#define SIZE 5

typedef struct {
    char street[50];
    int building;
    int flatNumber;
    char owner[50];
    char windowsDirection[20];
} Apartment;

int main() {
    Apartment flats[SIZE] = {
        {"Shevchenka", 10, 1, "Ivanov", "north"},
        {"Shevchenka", 10, 2, "Petrenko", "south"},
        {"Franko", 5, 3, "Tkachenko", "west"},
        {"Shevchenka", 12, 4, "Bondarenko", "north"},
        {"Franko", 5, 5, "Kovalenko", "east"}
    };

    char inputDirection[20];
    char inputStreet[50];

    printf("Введіть сторону світу (напр. north, south, east, west): ");
    scanf("%s", inputDirection);

    printf("Введіть назву вулиці: ");
    scanf("%s", inputStreet);

    FILE *out = fopen("selected_apartments.txt", "w");
    if (!out) {
        printf("Помилка при відкритті файлу!\n");
        return 1;
    }

    int found = 0;
    for (int i = 0; i < SIZE; i++) {
        if (strcmp(flats[i].windowsDirection, inputDirection) == 0 &&
            strcmp(flats[i].street, inputStreet) == 0) {
            fprintf(out, "Вулиця: %s, Будинок: %d, Квартира: %d, Власник: %s, Вікна: %s\n",
                    flats[i].street, flats[i].building, flats[i].flatNumber,
                    flats[i].owner, flats[i].windowsDirection);
            found = 1;
        }
    }

    if (!found) {
        fprintf(out, "Квартир за вказаними умовами не знайдено.\n");
    }

    fclose(out);
    printf("Результати записано в файл selected_apartments.txt\n");

    return 0;
}
