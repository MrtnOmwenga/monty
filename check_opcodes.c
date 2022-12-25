#include "monty.h"

/**
 *check-opcodes- Checks opcodes and calls required functions
 *
 *@line: Line to be checked for opcodes
 *@head: Head of doubly_linked_list(stack)
 *
 *Return: 0 if successful
 */

int check_opcodes(stack_t **head, char *line, unsigned int line_number)
{
  int i = 0;
  char *token;
  const char s[2] = " ";
  instruction_t instructions[] = {
				  {"push", push},
				  {"pall", pall}
  };

  printf("Before checking\n");

  while (i < 2)
    {
      if (strstr(line, instructions[i].opcode))
	{
	   instructions[i].f(head, line_number);
	   return (0);
	 }
      i++;
    }
  token = strtok(line, s);
  fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
  exit(EXIT_FAILURE);
  return (1);
}
