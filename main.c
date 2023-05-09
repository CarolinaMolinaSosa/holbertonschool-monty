#include "monty.h"

/**
 * main - entry point of the program
 * @argc: the amount of arguments
 * @argv: the arguments given by the user
 */

int main (int argc, char **argv)
{
char *s;
int f,r;
/*checking the arguments*/
if (argc < 2)
{
    printf("USAGE: monty file");
    exit(EXIT_FAILURE);
}
/*First we open the and read the file*/
s = malloc(sizeof(char)* argc);
if (s == NULL)
{
    free(s);
    return(NULL);   
}
f = open(argv[1], O_RDONLY);
if (f == -1)
{
fprintf(stderr,"Error: Can't open file <%s>", argv[1]);
exit(EXIT_FAILURE);
}
r = read(f, s, argc);
if(r = -1)
{
fprintf(stderr,"Error: Can't open file <%s>", argv[1]);
exit(EXIT_FAILURE);
}

close(f);
free(s);
return(0);
}