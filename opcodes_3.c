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

/**
 *pstr- Prints string sotred in stack
 *
 *@head: Stack head
 *@line_number: Line number
 *
 */

void pstr(stack_t **head, unsigned int line_number)
{
  stack_t *h = *head;

  while (h != NULL)
    {
      if (h->n <= 0 || h->n > 127)
	{
	  printf("\n");
	  return;
	}
      
      printf("%c", h->n);
      h = h->next;
    }

  printf("\n");
  free(h);

  if (line_number)
    {
      return;
    }
}
