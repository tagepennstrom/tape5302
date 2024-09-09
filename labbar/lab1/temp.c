#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_number(char *str)
{
    int length = strlen(str);
    bool decimal = false;

    if (length == 0) 
    {
        return false;
    }
    if ((str[0] == '-' || !isdigit(str[0])) && length == 1)
    {
        return false;
    }
    for(int i = 1; i < length; i++)
    {
        if (!isdigit(str[i]))
        {
            if (str[i] == '.' && !decimal)
            {
                decimal = true;
            }
            else
            {
                return false;
            }
        }

    }
    return true;
}




int main(int argc, char *argv[])
{
    if (argc > 1 && is_number(argv[1]))
{
  printf("%s is a number\n", argv[1]);
}
else
{
  if (argc > 1)
  {
    printf("%s is not a number\n", argv[1]);
  }
  else
  {
    printf("Please provide a command line argument!\n");
  }
}
    return 0;
}