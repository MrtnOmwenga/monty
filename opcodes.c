#define _GNU_SOURCE
#include "monty.h"

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
  int data = -1;
  size_t len = 0;
  unsigned int count = 1;
  char *line = NULL;
  char *ptr;
  FILE *file;

  new_head = malloc(sizeof(stack_t));
  if (new_head == NULL)
    {
      fprintf(stderr, "Error: malloc failed\n");
      free(new_head);
      free(*head);
      exit(EXIT_FAILURE);
    }

  file = fopen(filename, "r");
  if (file == NULL)
    {
      fprintf(stderr, "Error: Can't open file %s\n", filename);
      free(new_head);
      free(*head);
      fclose(file);
    }
  
  while (count <= line_number)
    {
      getline(&line, &len, file);
      count = count + 1;
    }

  ptr = line;
  while (*ptr)
    {
      if (isdigit(*ptr) > 0)
	{
	  data = strtol(ptr, &ptr, 10);
	  break;
	}
      else
	{
	  ptr++;
	}
    }

  if (data == -1 || (*ptr != ' ' && *ptr != '\n'))
    {
      fprintf(stderr, "L%d: usage: push integer\n", line_number);
      free(new_head);
      free(*head);
      exit(EXIT_FAILURE);
    }
  
  new_head->n = data;
  new_head->prev = NULL;
  new_head->next = *head;

  if ((*head) != NULL)
    {
  (*head)->prev = new_head;
    }
  *head = new_head;

  fclose(file);
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
