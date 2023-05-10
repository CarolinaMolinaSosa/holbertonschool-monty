#include "monty.h"

/*Global variable*/
stack_t **call;

/**
 *push - The opcode push pushes an element to the stack.
 *@src: the the int to push
 */
void push(int src)
{
stack_t *list, *res;

list = malloc(sizeof(stack_t));
if (list == NULL)
{
free(list);
return (NULL);
}
res = *call;
list->n = src;
list->next = NULL;
	list->prev = NULL;
	if (*call == NULL)
	{
		*call = list;
        list->prev = NULL;
		return (*call);
	}
	else
	{
        while(res->next != NULL)
		res=res->next;
	}
    res->next = list;
    list->prev = res;
}
/**
 * pall - a funtion to print the global variable
 * 
 */

void pall(void)
{
int i = 0;
stack_t *list;

list = *call;
if (list == 0)
{
return (0);
}
while (list != NULL)
{
i++;
list = list->next;
}
while (i != 0)
{
printf("%d\n", list->n);
list = list->prev;
}
}
/**
 * nop - a function that does absolutly nothing
 */
void nop(void)
{
}
/**
 * pint - a function that prints the top of the stack
 */
void pint(void)
{
int i = 0;
stack_t * list;

list = *call;
if (list = NULL)
{
fprintf(stderr,"L<line_number>: can't pint, stack empty\n");
exit(EXIT_FAILURE);	
}
while (list->next != NULL)
{
list = list->next;
}
printf("%d\n", list->n);
}
/**
 *pop - a function that removes the top element fo the stack
 */
void pop (void)
{
	stack_t *list;

	list = *call;
	if (list == NULL)
	{
		fprintf(stderr,"L<line_number>: can't pop an empty stack");
		exit(EXIT_FAILURE);
	}
	while (list->next != NULL)
	{
		list = list->next;
	}
	list->prev->next = list->next;
	free(list);	
}