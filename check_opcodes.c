#define _GNU_SOURCE
#include "monty.h"

/**
 *check_opcodes- Check opcodes
 *
 *@head: Head of stack
 *@file: File being checked
 *
 *Return: void
 */

void check_opcodes(stack_t **head, FILE *file)
{
  size_t len = 0;
  unsigned int line_number = 1;
  char *token;
  __ssize_t read;
  char *line = 0;
  int i;

  instruction_t instructions[] = {
				  {"push", push},
				  {"push\n", push},
				  {"pall", pall},
				  {"pall\n", pall}
  };
  
  while ((read = getline(&line, &len, file)) != -1)
    {
      token = strtok(line, " ");
      if (read > 2 && strcmp(token, "\n") != 0)
	{
	  for (i = 0; i <= 4; i++)
	    {
	      if (i == 4)
		{
		  fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
		  free(*head);
		  exit(EXIT_FAILURE); 
		}
	      if (strcmp(token, instructions[i].opcode) == 0)
		{
		  instructions[i].f(head, line_number);
		  break;
		}
	    } 
	}
      line_number++;
    }

  free(line);
}
