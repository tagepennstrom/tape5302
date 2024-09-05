#include <string.h>
#include <stdio.h>
#include "utils.h"
#include <stdlib.h>

int string_length(char *str)
{
    int result = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        result += 1;
    } 
    return result;

}

// int main(int argc, char *argv[])
// {
//     if (argc < 2)
//     {
//         printf("Usage: %s words or string", argv[0]);
//     }
//     else
//     {
//         for (int i = 1; i < argc; ++i)
//         {
//             int expected = strlen(argv[i]);
//             int actual   = string_length(argv[i]);
//             printf("strlen(\"%s\")=%d\t\tstring_length(\"%s\")=%d\n", 
//             argv[i], expected, argv[i], actual);
//         }
//     }
//     println(argv[1]);
//     return 0;
// }

/// Den intressanta delen av programmet
int fib(int num)
{
  int a = 0; // the two given fib values
  int b  = 1;

  if (num == 0 || 1)
  {
    return 1;
  }
  else
  {
    return fib(num - 1) + fib(num - 2);
  }
}

/// Den ointressanta main()-funktionen
int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s number\n", argv[0]);
  }
  else
  {
    int n = atoi(argv[1]);
    if (n < 2)
    {
      printf("fib(%d) = %d\n", n, n);
    }
    else
    {
      printf("fib(%s) = %d\n", argv[1], fib(n));
    }
  }
  return 0;
}