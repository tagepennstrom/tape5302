#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"

int main(void)
{  
    int buf_siz = 255;
    char buf[buf_siz];
    int tal = random () % 1001;
    int spel = 1;
    char namn;
    while (spel == 1)
    {
        namn = ask_question_string("Skriv in ditt namn", buf, buf_siz);
    }
    return 0;
}
