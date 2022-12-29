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
				  {"pall", pall},
				  {"pint", pint},
				  {"pop", pop},
				  {"swap", swap},
				  {"add", add},
				  {"nop", nop},
				  {"sub", sub},
				  {"div", _div}
  };
  
  while ((read = getline(&line, &len, file)) != -1)
    {
      token = strtok(line, " ");
      if (read > 2 && strcmp(token, "\n") != 0)
	{
	  remove_newline(token);
	  for (i = 0; i <= 9; i++)
	    {
	      if (i == 9)
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
