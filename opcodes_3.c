#include "monty.h"

/**
 *pchar- Prints character at top of stack
 *
 *@head: Head of stack
 *@line_number: Line number
 *
 */

void pchar(stack_t **head, unsigned int line_number)
{
  if (head == NULL || *head == NULL)
    {
      fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
      exit(EXIT_FAILURE);
    }

  if ((*head)->n < 0 || (*head)->n > 127)
    {
      fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
      exit(EXIT_FAILURE);
    }

  printf("%c\n", (*head)->n);
}
