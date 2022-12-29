#define _GNU_SOURCE
#include "monty.h"

/**
 *nop- Does nothing
 *
 */

void nop()
{
  return;
}

/**
 *push- Pushes data onto a stack
 *
 *@head: Head of stack
 *@line_number: Line number
 *
 *Return: void
 */

void push(stack_t **head, unsigned int line_number)
{
  stack_t *new_head;
  char *line = NULL;
  int data;

  new_head = malloc(sizeof(stack_t));
  if (new_head == NULL)
    {
      fprintf(stderr, "Error: malloc failed\n");
      free(new_head);
      free(*head);
      exit(EXIT_FAILURE);
    }

  line = read_line(line_number);

  data = get_data(line, line_number);
  
  new_head->n = data;
  new_head->prev = NULL;
  new_head->next = *head;

  if ((*head) != NULL)
    {
  (*head)->prev = new_head;
    }
  *head = new_head;

  free(line);
  line = NULL;
}

/**
 *pall- Displays all elements in stack
 *
 *@head: Head of stack
 *@line_number: Line number
 *
 *Return: void
 */

void pall(stack_t **head, unsigned int line_number)
{
  stack_t *h;
  
  h = *head;

  while (h != NULL)
    {
      printf("%d\n", h->n);
      h = h->next;
    }

  if (line_number)
    {
      return;
    }

  free(h);
}
