#include <stdio.h>

void cat(char *filename)
{
int counter = 1;
FILE *f = fopen(filename, "r");
int c = fgetc(f);

printf("==== %s ==== \n \n", filename);
printf("%d  ", counter);
while (c != EOF)
{
    fputc(c, stdout);
    c = fgetc(f);
    if (c == '\n')
    {
        fputc(c, stdout);
        counter += 1;
        printf("%d  ", counter );
        c = fgetc(f);
    }
    
}
printf("\n");
fclose(f); 
}
int main(int argc, char *argv[])
{
if (argc < 2)
{
    fprintf(stdout, "Usage: %s fil1 ...\n", argv[0]);
}
else
{
    for (int i = 1; i < argc; ++i)
    {
    cat(argv[i]);
} }
return 0; }