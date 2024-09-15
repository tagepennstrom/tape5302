#include <string.h>
#include <stdio.h>
#include "utils.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>



struct item
{
    char *name;
    char *desc;
    int price;
    char *shelf;
};

typedef struct item item_t;

void print_item(item_t* i)
{
    int price = i->price;
    int kornor = price / 100;
    int ore = price % 100;

    printf("Name:  %s\n", i->name);
    printf("Desc:  %s\n", i->desc);
    printf("Price: %d.%d\n", kornor, ore);
    printf("Shelf: %s\n", i->shelf);
    

}

item_t make_item(char *name, char *desc, int price, char *shelf)
{
    item_t new_item = { .name = name, .desc = desc, .price = price, .shelf = shelf };
    return new_item;
}

item_t input_item()
{
    char *input_name = ask_question_string("Name: ");
    char *input_desc = ask_question_string("Description: ");
    int input_price = ask_question_int("Price  in ore: ");
    char *input_shelf = ask_question_shelf("Shelf: ");
    
    item_t new_item = make_item(input_name, input_desc, input_price, input_shelf);
    return new_item;
}

char *magick(char *arr1[], char *arr2[], char *arr3[], int arrlen )
{
    char buf[255];
    int buf_index = 0;
    int random1 = random() % arrlen;
    int random2 = random() % arrlen;
    int random3 = random() % arrlen;

    for (int i = 0; i < strlen(arr1[random1]); i++)
    {
        buf[buf_index] = arr1[random1][i];
        buf_index += 1;
    }

    buf[buf_index] = '-';
    buf_index += 1;

    for (int k = 0; k < strlen(arr2[random2]); k++)
    {
        buf[buf_index] = arr2[random2][k];
        buf_index += 1;
    }

    buf[buf_index] = ' ';
    buf_index += 1;

    for (int j = 0; j < strlen(arr3[random3]); j++)
    {
        buf[buf_index] = arr3[random3][j];
        buf_index += 1;
    }

    buf[buf_index] = '\0';

    return strdup(buf);
}

void list_db(item_t *items, int no_items)
{
    char *name = items->name;
    printf("%d. %s\n", no_items + 1, name);
}

void edit_db(item_t *databas)
{
    
    int index = ask_question_int("Vilket ord vill du ersätta: ");
    while (index < 1 || index > 16)
    {
        index = ask_question_int("Vilket ord vill du ersätta: ");
    }
    databas[index - 1] = input_item();
    list_db(&databas[index - 1], index - 1);
}

int main(int argc, char *argv[])
{
char *array1[] = { "Laser",        "Polka",    "Extra" };
char *array2[] = { "förnicklad",   "smakande", "ordinär" };
char *array3[] = { "skruvdragare", "kola",     "uppgift" };

if (argc < 2)
{
    printf("Usage: %s number\n", argv[0]);
}
else
{
    item_t db[16]; // Array med plats för 16 varor
    int db_siz = 0; // Antalet varor i arrayen just nu

    int items = atoi(argv[1]); // Antalet varor som skall skapas

    if (items > 0 && items <= 16)
    {
    for (int i = 0; i < items; ++i)
    {
        // Läs in en vara, lägg till den i arrayen, öka storleksräknaren
        item_t item = input_item();
        db[db_siz] = item;
        ++db_siz;
    }
    }
    else
    {
    puts("Sorry, must have [1-16] items in database.");
    return 1; // Avslutar programmet!
    }

    for (int i = db_siz; i < 16; ++i)
    {
        char *name = magick(array1, array2, array3, 3); // TODO: Lägg till storlek
        char *desc = magick(array1, array2, array3, 3); // TODO: Lägg till storlek
        int price = random() % 200000;
        char shelf[] = { random() % ('Z'-'A') + 'A',
                        random() % 10 + '0',
                        random() % 10 + '0',
                        '\0' };
        item_t item = make_item(name, desc, price, shelf);

        db[db_siz] = item;
        ++db_siz;
    }

    // Skriv ut innehållet
    for (int i = 0; i < db_siz; ++i)
    {
    list_db(&db[i], i);
    }

edit_db(db);

    // Skriv ut innehållet
    for (int i = 0; i < db_siz; ++i)
    {
    list_db(&db[i], i);
    }

}
return 0;
}

