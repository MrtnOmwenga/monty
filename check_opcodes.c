#include "monty.h"

/**
 *check-opcodes- Checks opcodes and calls required functions
 *
 *@line: Line to be checked for opcodes
 *@head: Head of doubly_linked_list(stack)
 *
 *Return: 0 if successful
 */

int check_opcodes(stack_t **head, char *line)
{
  int i = 0;
  instruction_t instructions[] = {
				  {"push", push},
				  {"pall", pall}
  };

    while (i < 2)
      {
       if (strstr(line, instructions[i].opcode)
	 {
	   instructions[i].(head, line);
	   return (0);
	 }
	 else
	   {
	     return (1);
	   }
      }
}
