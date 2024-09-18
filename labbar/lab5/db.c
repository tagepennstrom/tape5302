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

int add_item_to_db(item_t *databas, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (databas[i].name == NULL)
        {
            databas[i] = input_item();
            printf("Item added at index %d\n", i + 1);
            return 0;
        }
    }
return 0;
}

int main(int argc, char *argv[])
{
    int db_siz = 16;
    item_t *db = calloc(db_siz, sizeof(item_t));
    bool running = true;
    while (running)
    {
        char input = ask_question_menu("Please enter your choice: ");
        
        if (input == 'L')
        {
            add_item_to_db(db, db_siz);
        }else if (input == 'T')
        {
            printf("not implemented yet\n");
        }else if (input == 'R')
        {
            for (int i = 0; i < db_siz; ++i)
            {
                if (db[i].name != NULL)
                {
                    list_db(&db[i], i);
                }
            }
            edit_db(db);
        }else if (input == 'G')
        {
            printf("not implemented yet\n");
        }else if (input == 'A')
        {
            running = false;
        }else if (input == 'h')
        {
            // Skriv ut innehållet
            for (int i = 0; i < db_siz; ++i)
            {   
                if (db[i].name != NULL)
                {
                list_db(&db[i], i);
                }
            }
        }
    }
    return 0;
}



