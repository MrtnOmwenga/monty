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
  int i;
  FILE *file;
  char *token;
  instruction_t instructions[] = {
				  {"push", push},
				  {"pall", pall}
  };
  
  head = NULL;
  
  if (argc != 2)
    {
      fprintf(stderr, "USAGE: monty file\n");
      exit(EXIT_FAILURE);
    }

  filename = argv[1];
  file = fopen(filename, "r");
  if (file == NULL)
    {
      fprintf(stderr, "Error: Can't open file %s\n", filename);
      exit(EXIT_FAILURE);
    }

  while (getline(&line, &len, file) != -1)
    {
      token = strtok(line, " ");
      if (strstr(line, "pall"))
	{
	  token = "pall";
	}
      
      for (i = 0; i <= 2; i++)
	{
	  if (i == 2)
	    {
	      fprintf(stderr, "l%d: unknown instruction %s\n", line_number, token);
	    }
	  if (strcmp(token, instructions[i].opcode) == 0)
	    {
	      instructions[i].f(&head, line_number);
	      break;
	    }
	}
      line_number++;
    }

  return (0);
}
