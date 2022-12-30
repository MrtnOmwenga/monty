#include "monty.h"

/**
 *rotl- Rotates the stack to the top
 *
 *@head: Head of stack
 *@line_number: Line number
 *
 */

void rotl(stack_t **head, unsigned int line_number)
{
  stack_t *first;
  stack_t *last;
  
  if (head == NULL || *head == NULL || (*head)->next == NULL)
    {
      return;
    }

  first = *head;
  last = *head;
  while (last->next != NULL)
    {
      last = last->next;
    }

  *head = first->next;

  first->next = NULL;
  first->prev = last;
  last->next = first;

  if (line_number)
    {
      return;
    }
}

/**
 *rotr- Rotates the stack to the bottom
 *
 *@head: Head of stack
 *@line_number: Line number
 *
 */

void rotr(stack_t **head, unsigned int line_number)
{
  stack_t *first;
  stack_t *last;

  if (head == NULL || *head == NULL || (*head)->next == NULL)
    {
      return;
    }

  first = *head;
  last = *head;
  while (last->next != NULL)
    {
      last = last->next;
    }

  last->prev->next = NULL;
  last->prev = NULL;
  last->next = first;

  first->prev = last;
  *head = last;

  if (line_number)
    {
      return;
    }
}
