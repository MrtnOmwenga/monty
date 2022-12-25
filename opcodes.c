#define _GNU_SOURCE
#include "monty.h"

/**
 *push- Pushes data onto a stack
 *
 *@head: Head of stack
 *@line: Line containing data
 *
 *Return: void
 */

void push(stack_t **head, unsigned int line_number)
{
  stack_t *new_head;
  int data, i = 0;
  size_t len = 0;
  unsigned int count = 0;
  char *line;

  printf("Starting... \n");
  new_head = malloc(sizeof(stack_t));
  if (new_head == NULL)
    {
      fprintf(stderr, "Error: malloc failed\n");
      exit(EXIT_FAILURE);
    }

  while (count < line_number)
    {
      getline(&line, &len, file);
      count = count + 1;
    }

  printf("OK so far\n");
  while (line[i])
    {
      if (isdigit(line[i]))
	{
	  data = atoi(&line[i]);
	}
      i++;
    }

  printf("Checkpoint 1\n");
  new_head->n = data;
  new_head->prev = NULL;
  new_head->next = *head;

  printf("Checkpoint 2\n");
  if ((*head) != NULL)
    {
  (*head)->prev = new_head;
    }
  *head = new_head;
  printf("Checkpoint 3\n");
}

/**
 *pall- Displays all elements in stack
 *
 *@head: Head of stack
 *
 *Return: void
 */

void pall(stack_t **head, unsigned int line_number)
{
  stack_t *h;

  if (head == NULL || *head == NULL)
    {
      exit(EXIT_FAILURE);
    }
  
  h = *head;
  if (line_number)
    {
  while (h != NULL)
    {
      printf("%d\n", h->n);

      h = h->next;
    }
    }
}
