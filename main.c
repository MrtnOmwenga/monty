#define _GNU_SOURCE
#include "monty.h"

/**
 *main- Reads input file
 *
 *Return: Always 0 success
 */

int main(int argc, char *argv[])
{
  char *line = NULL;
  size_t len = 0;
  unsigned int line_number = 1;
  stack_t *head;

  head = malloc(sizeof(stack_t));
  if (head == NULL)
    {
      fprintf(stderr, "Error: malloc failed\n");
      free(head);
      exit(EXIT_FAILURE);
    }
  head->n = 0;
  head->prev = NULL;
  head->next = NULL;
  
  if (argc != 2)
    {
      fprintf(stderr, "USAGE: monty file\n");
      exit(EXIT_FAILURE);
    }

  file = fopen(argv[1], "r");
  if (file == NULL)
    {
      fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
      exit(EXIT_FAILURE);
    }

  while ((getline(&line, &len, file)) != -1)
    {
      check_opcodes(&head, line, line_number);
      line_number++;
    }

  return (0);
}
