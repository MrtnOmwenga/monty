#include "monty.h"

/**
 *destroy- Deletes the stack
 *
 *@head: Head of stack
 *
 *Return: void
 */

void destroy(stack_t **head)
{
  stack_t *curr, *h;

  curr = *head;
  while (curr != NULL)
    {
      h = curr->next;
      free(curr);
      curr = h;
    }

  *head = NULL;
}
