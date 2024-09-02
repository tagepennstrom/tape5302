#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
int input = atoi(argv[1]);
int x;
int y;
int prime = 0;
float tmp = sqrt(input);
int limit = floor(tmp) + 1;
for(x = 2; x <= limit; x++)
    {
    for(y = 2; y <= input/2; y++)
        {
            if (x * y == input)
            {
                printf("%d är inte ett primtal\n", input);
                return 0;
            }
            else;
            {}
        }
    }
printf("%d är ett primtal\n", input);
return 0;
}