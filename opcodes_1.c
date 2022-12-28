#include "monty.h"

/**
 *swap- Swaps first 2 elements of stack
 *
 *@head: Head of stck
 *@line_number: Line number
 *
 */

void swap(stack_t **head, unsigned int line_number)
{
  int first;
  int second;
  
  if (head == NULL || *head == NULL || (*head)->next == NULL)
    {
      fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }

  first = (*head)->n;
  second = (*head)->next->n;

  (*head)->n = second;
  (*head)->next->n = first;
}

/**
 *pint- Prints first integer in stack
 *
 *@head: head of stack
 *@line_number: Line number
 *
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

/**
 *pop- Removes forst element from stack
 *
 *@head: Head of stack
 *@line_number: Line number
 *
 */

void pop(stack_t **head, unsigned int line_number)
{
  stack_t *h;

  if (head == NULL || *head == NULL)
    {
      fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
      exit(EXIT_FAILURE);
    }
  
  h = *head;
  *head = (*head)->next;
  free(h);
}
