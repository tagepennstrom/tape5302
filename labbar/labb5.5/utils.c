#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

extern char *strdup(const char*);

bool is_number(char *str)
{
    int length = strlen(str);
    bool decimal = false;

    if (length == 0) 
    {
        return false;
    }
    if (str[0] == '-' && length == 1)
    {
        return false;
    }
    if (str[0] != '-' && !isdigit(str[0]))
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

bool is_shelf(char *str)
{
    int length = strlen(str);
    
    if (length < 2) 
    {
        return false;
    }
    if (!isupper(str[0]))
    {
        return false;
    }
    
    for(int i = 1; i < length; i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

bool is_float(char *str)
{
    float num = atof(str);
    if (!is_number(str))
    {
        return false;
    }
    return floor(num) != num;
}

bool not_empty(char *str)
{
    return strlen(str) > 0;
}

void clear_input_buffer(void)
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

answer_t make_float(char *str)
{
  answer_t a;                // skapa ett oinitierat answer_t-värde
  a.float_value = atof(str); // gör det till en float, via atof
  return a;                  // returnera värdet
}

answer_t ask_question(char *question, check_func *check, convert_func *convert)
{
    int buf_siz = 255;
    char buf[buf_siz];
    do
    {
        printf("%s", question);
        read_string(buf, buf_siz);
    } while (!check(buf));

    return convert(buf);
}

int ask_question_int(char *question) // från studium
{
  answer_t answer = ask_question(question, is_number, (convert_func *) atoi);
  return answer.int_value; // svaret som ett heltal
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

char *ask_question_string(char *question)
{
  return ask_question(question, not_empty, (convert_func *) strdup).string_value;
}

void print(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        putchar(str[i]);
    return;
}

char* ask_question_shelf(char *question)
{
    return ask_question(question, is_shelf, (convert_func *) strdup).string_value;
}


void println(char *str)
{
    char radbrytning = '\n';
    print(str);
    putchar(radbrytning);
}


