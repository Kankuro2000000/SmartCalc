#ifndef SMART_CALC_H
# define SMART_CALC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node {
	double			value;
	struct Node	*next;
} Node;

typedef struct Node_str {
	char	*value;
	struct	Node_str *next;
} Node_str;

/* linked_list.c*/

void	push(Node **head, double data);
void	pop(Node **head);
void	push_str(Node_str **head, char* data);
void	pop_str(Node_str **head);

/*checkers.c*/

int		my_strcmp(const char *str, const char *str2);
int 	check_input(const char *str);
char	*remove_spaces(const char *str);

/*add_func.c*/
int		double_size(char *str);

#endif