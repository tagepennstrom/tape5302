#include <stdio.h>

int main(void)
{
int i;
int j;
int n = 1;
int count = 0; 
    for (i = 1; i <= 10; i++)
    {
        for (j = 1; j <= n; j++)
        { 
            printf("%s", "*");
        }
        printf("\n");           //Bryter raden
        count += n;             //räknar
        n++;                    //ökar n
    }
printf("Totalt; %d\n", count);    
return 0;
}