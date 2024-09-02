#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
int i;
int j;
int n = 1;
int count = 0; 
int staplar = atoi(argv[1]);
int okning = atoi(argv[2]);
int okning2 = okning;

    for (i = 1; i <= staplar; i++)
    {
        for (j = 1; j <= okning; j++)
        { 
            printf("*");
        }
        printf("\n");           //Bryter raden
        count += okning;             //räknar
        okning += okning2;            //ökar n
    }
printf("Totalt; %d\n", count);    
return 0;
}