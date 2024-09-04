#include <stdio.h>
#include <stdlib.h>

void print_number(int num)
{
    if(num % 5 == 0 && num % 3 == 0)
    {
        printf("Fizz Buzz, ");
    }
    else if (num % 3 == 0)
    {
        printf("Fizz, ");
    }
    else if (num % 5 == 0)
    {
        printf("Buzz, ");
    }
    else
    {
        printf("%d, ", num);
    }
    return;
}

int i;
int T;
int main(int argc, char *argv[])
{
int T = atoi(argv[1]);
for(i = 1; i <= T; i++ )
    {
        print_number(i);
    }
return 0;
}