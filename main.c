#define _GNU_SOURCE
#include "monty.h"

/**
 *main- Reads input file
 *
 *Return: Always 0 success
 */

int main(int argc, char *argv[])
{
  stack_t *head;
  FILE *file;
  
  head = NULL;
  
  if (argc != 2)
    {
      fprintf(stderr, "USAGE: monty file\n");
      free(head);
      exit(EXIT_FAILURE);
    }

  filename = argv[1];
  file = fopen(filename, "r");
  if (file == NULL)
    {
      fprintf(stderr, "Error: Can't open file %s\n", filename);
      free(head);
      exit(EXIT_FAILURE);
    }

  check_opcodes(&head, file);

  fclose(file);
  destroy(&head);
  return (0);
}
