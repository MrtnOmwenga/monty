#define _GNU_SOURCE
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
 *@line_number: Line number
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
      exit(EXIT_FAILURE);
    }

  return (data);
}

/**
 *read_line- reads specific line
 *
 *@line_number: line number
 *
 *Return: Line
 */

char *read_line(unsigned int line_number)
{
  unsigned int count = 1;
  FILE *file;
  size_t len = 0;
  char *line = NULL;

  file = fopen(filename, "r");
  if (file == NULL)
    {
      fprintf(stderr, "Error: Can't open file %s\n", filename);
      fclose(file);
      exit(EXIT_FAILURE);
    }

  while (count <= line_number)
    {
      getline(&line, &len, file);
      count = count + 1;
    }

  fclose(file);
  return (line);
}
