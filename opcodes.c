#include "monty.h"

/**
 *push- Pushes data onto a stack
 *
 *@head: Head of stack
 *@line: Line containing data
 *
 *Return: 0 if successful else -1
 */

int push(stack_t **head, char *line)
{
  stack_t *new_head;
  int data, i = 0;

  new_head = malloc(sizeof(stack_t));
  if (new_head == NULL)
    {
      fprintf(stderr, "Error: malloc failed\n");
      exit(EXIT_FAILURE);
    }

  while (line[i])
    {
      if (isdigit(line[i]))
	{
	  data = atoi(line[i]);
	}
    }

  new_head->n = data;
  new_head->prev = NULL;
  new_head->next = *head;

  (*head)->prev = new_head;
  *head = new_head;

  return (0);
}

/**
 *pall- Displays all elements in stack
 *
 *@head: Head of stack
 *
 *Return: 0(Hopefully always successfull)
 */

int pall(stack_t **head)
{
  stack_t *h;

  if (head == NULL || *head == NULL)
    {
      exit(EXIT_FAILURE);
    }
  
  h = *head;
  while (h != NULL)
    {
      printf("%d\n", h->n);

      h = h->next;
    }

  return (0);
}

    
