#include "utils.h"
#include <stdio.h>

void clear_input_buffer(void)
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int ask_question_int(char *question)
{
    int result;
    int conversions;
    do
    {
        printf("%s\n", question);
        conversions = scanf("%d", &result);
        clear_input_buffer();
        putchar('\n');
    }
    while (conversions < 1);
    return result;
}

int read_string(char *buf, int buf_siz)
{
    int counter = 0;
    int c;
    int i;
    for (i = 0; i < buf_siz - 1; i++)
    {
        c = getchar();
        if (c != '\n' && c != EOF)
        {
            buf[i] = c;
            counter += 1;
        }
        else
        {
            buf[i] = '\0';
            return counter;
        }
    }
    return counter;
}

char *ask_question_string(char *question, char *buf, int buf_siz)
{
    int result = 0;
    while(result == 0)
    {
        printf("%s\n", question);
        result = read_string(buf, buf_siz);
    }
    return buf;  
}