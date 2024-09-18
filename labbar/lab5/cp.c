#include <stdio.h>
 void cp(char *source, char *dest)
 {
   FILE *sf = fopen(source, "r");
   FILE *df = fopen(dest, "w");
   int c = fgetc(sf);
   while (c != EOF)
   {
     fputc(c, df);
     c = fgetc(sf);
   }
fclose(sf);
fclose(df);
printf("Copied %s to %s \n", source, dest);
}
 int main(int argc, char *argv[])
{
if (argc < 3)
   {
    fprintf(stdout, "Usage: %s fil1 fil2 \n", argv[0]);
}
    else
    {
       cp(argv[1], argv[2]);
    }

return 0;
}