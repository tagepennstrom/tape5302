#include <stdio.h>

void clear_input_buffer(void)
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
    putchar('\n');
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
    }
    while (conversions < 1);
    return result;
}

int read_string(char *buf, int buf_siz)
{
    int counter = 0;
    int c;
    while (counter < buf_siz)
    {
        
    }
    
}
    

int main(void)
{
    int buf_siz = 255;
    int read = 0;
    char buf[buf_siz];

    puts("Läs in en sträng:");
    read = read_string(buf, buf_siz);
    printf("'%s' (%d tecken)\n", buf, read);

    puts("Läs in en sträng till:");
    read = read_string(buf, buf_siz);
    printf("'%s' (%d tecken)\n", buf, read);

    return 0;
}
