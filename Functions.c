#include "monty.h"

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
