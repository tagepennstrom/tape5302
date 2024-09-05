#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"

int main(void)
{  
    int buf_siz = 255;
    char buf[buf_siz];
    int tal = random () % 1001;
    int spel = 1;
    int tries = 0;
    int guess;
    char *namn;


    while (spel == 1)
    {
        namn = ask_question_string("Skriv in ditt namn", buf, buf_siz);
        printf("Du %s, jag tänker på ett tal ... " , namn);
        guess = ask_question_int("kan du gissa vilket?");
        while (tries <= 13 && guess != tal)
        {
            if (guess < tal)
            {
            guess = ask_question_int("Högre");
            tries += 1;
            }
            else
            {
            guess = ask_question_int("Lägre");
            tries += 1;
            }

        }
        if (tal == guess)
        {
            spel = 0;
            printf("Bingo!\nDet tog %s %d gissningar att komma fram till %d", namn, tries, tal);
        }
        else
        {
            spel = 0;
            printf("Ajdå!\nNu har du slut på gissningar! Jag tänkte på %d!", tal);
        }
    }
    return 0;
}
