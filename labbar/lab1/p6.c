#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_number(char *str)
{
  int length = strlen(str);
  int i;
  for(i = 0; i < length; i++)
  {
    if (!isdigit(str[i]) && (str[0]) != '-')
        {
            return false;
        }

  }

  return true;
}


int main(int argc, char *argv[])
{
int input_a = atoi(argv[1]);
int input_b = atoi(argv[2]);
int a = input_a;
int b = input_b;
if (!is_number(argv[1]) || a <= 0 || !is_number(argv[2]) || b <= 0)    
    {
        puts("Inget positivt heltal!");
        return 0;
    }
    while (a != b)
    {
        if (a > b)
        {
            (a -= b); 
        }
        else
        {
            (b -= a);
        }
    }
printf("gcd(%d, %d) = %d\n", input_a, input_b, a);
return 0;
}