#include "monty.h"

/**
 *sub- subtracts the first 2 elements of a stack
 *
 *@head: Stack head
 *@line_number: Line number
 *
 */

void sub(stack_t **head, unsigned int line_number)
{

  if (head == NULL || *head == NULL || (*head)->next == NULL)
    {
      fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }

  (*head)->next->n = (*head)->next->n - (*head)->n;
  pop(head, line_number);
}

/**
 *_div- Divides the first 2 elements of stack
 *
 *@head: Head of stack
 *@line_number: Line number
 *
 */

void _div(stack_t **head, unsigned int line_number)
{
  if (head == NULL || *head == NULL || (*head)->next == NULL)
    {
      fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }

  if ((*head)->n == 0)
    {
      fprintf(stderr, "L%d: division by zero\n", line_number);
      exit(EXIT_FAILURE);
    }

  (*head)->next->n = (*head)->next->n / (*head)->n;
  pop(head, line_number);
}

/**
 *_mul- Multiplies first 2 elements
 *
 *@head: Head of stack
 *@line_number: Line number
 *
 */

void _mul(stack_t **head, unsigned int line_number)
{
  if (head == NULL || *head == NULL || (*head)->next == NULL)
    {
      fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }

  (*head)->next->n = (*head)->next->n * (*head)->n;
  pop(head, line_number);
}
