#include <stdio.h>

void print(char *str)
{
    
    for (char *index = str; *index != '\0'; ++index) 
    {   
        putchar(*index); 
    }
    return;    
}

   
int main()
{
    print("haj!\n");
    return 0;
}