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
  stack_t *h;
  
  if (head == NULL || *head == NULL || (*head)->next == NULL)
    {
      return;
    }

  h = *head;
  while (h->next != NULL)
    {
      h = h->next;
    }

  (*head)->prev = h;
  (*head)->next = NULL;
  h->next = *head;
  pop(head, line_number);
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
  stack_t *h;

  if (head == NULL || *head == NULL || (*head)->next == NULL)
    {
      return;
    }

  h = *head;
  while (h->next != NULL)
    {
      h = h->next;
    }

  if (line_number)
    {
      return;
    }
}
