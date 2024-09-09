#include <string.h>
#include <stdio.h>
#include "utils.h"
#include <stdlib.h>
#include <stdbool.h>


typedef int int_fold_func(int, int);

int foldl_int_int(int numbers[], int numbers_siz, int_fold_func *f)
{
int result = 0;
// Loopa över arrayen och för varje element e utför result = f(result, e)
for (int i = 0; i < numbers_siz; ++i)
{
    result = f(result, numbers[i]);
}
return result;
}

int add(int a, int b)
{
    return a + b;
}
long sum(int numbers[], int numbers_siz)
{
    return foldl_int_int(numbers, numbers_siz, add);
}



int main()
{
    int nummer[5] = {5, 1, 2, 3, 6};
    int summa = sum(nummer, 5);
    printf("Summa %d\n", summa);

    float siffra = 5000;
    if (is_int(siffra))
    {
        printf("%f är ett heltal", siffra);
    }
    else
    {
        printf("%f är inte ett heltal", siffra);
    }
    return 0;
}

