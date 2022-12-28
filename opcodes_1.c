#include "monty.h"

/**
 *pint- Prints first integer in stack
 *
 *@head: head of stack
 *@line_number: Line number
 *
 *Return: void
 */

void pint(stack_t **head, unsigned int line_number)
{
  if (head == NULL || *head == NULL)
    {
      fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
      exit(EXIT_FAILURE);
    }

  printf("%d\n", (*head)->n);
}
