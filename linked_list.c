#include "smart_calc.h"

void push(Node **head, double data)
{
	Node	*tmp;

	tmp = (Node*)malloc(sizeof(Node));
	tmp->value = data;
	tmp->next = (*head);
	(*head) = tmp;
}

void	pop(Node **head)
{
	Node*	prev;

	prev = NULL;
	if (head == NULL) 
	{
		exit(-1);
	}
	prev = (*head);
	(*head) = (*head)->next;
	free(prev);
}

void	push_str(Node_str **head, char *data)
{
	Node_str	*tmp;

	tmp = malloc(sizeof(Node_str));
	tmp->value = malloc(sizeof(char) * 10);
	tmp->value = strcpy(tmp->value, data);
	tmp->next = (*head);
	(*head) = tmp;
}

void	pop_str(Node_str **head)
{
	Node_str	*prev;

	prev = NULL;
	if (head == NULL) 
	{
		exit(-1);
	}
	prev = (*head);
	(*head) = (*head)->next;
	free(prev->value);
	free(prev);
}