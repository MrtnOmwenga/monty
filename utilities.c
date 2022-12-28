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

/**
 *get_data- Gets data from line
 *
 *@line: Line with data
 *
 *Return: data
 */

int get_data(char *line, unsigned int line_number)
{
  char *ptr;
  int data = -1;

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
      /**free(*new_head);
	 free(*head);**/
      exit(EXIT_FAILURE);
    }

  return (data);
}
