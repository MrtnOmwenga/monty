#define _GNU_SOURCE
#include "main.h"

/**
 *main- Reads input file
 *
 *Return: Always 0 success
 */

int main(int argc, char *argv[])
{
  FILE *file;
  char *line = NULL;
  size_t len = 0;
  int read;
  if (argc != 2)
    {
      printf("USAGE: monty file\n");
      exit(EXIT_FAILURE);
    }

  file = fopen(argv[1], "r");
  if (file == NULL)
    {
      printf("Error: Can't open file %s\n", argv[1]);
    }

  while ((read = getline(&line, &len, file)) != -1)
    {
      printf("%s\n", line);
    }

  return (0);
}
