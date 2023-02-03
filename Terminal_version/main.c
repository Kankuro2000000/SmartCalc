#include "smart_calc.h"

int	ft_strlcpy(char *dest, char *src, int size)
{
	int	count;
	int	i;

	count = 0;
	while (src[count] != '\0')
		count++;
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (count);
}

int	is_operator(char *str) {
		if (*str == '*' || *str == '/' || *str == '-' || *str == '+'
			|| *str == '^' ) {
			return 1;
		}
		if (my_strcmp(str, "ln")){
			return 2;
		}
		if (my_strcmp(str, "mod") || my_strcmp(str, "cos") || my_strcmp(str, "sin")
		|| my_strcmp(str, "tan") || my_strcmp(str, "log")){
			return 3;
		}
		if (my_strcmp(str, "acos") || my_strcmp(str, "asin")
		|| my_strcmp(str, "atan") || my_strcmp(str, "sqrt")){
			return 4;
		}
		return 0;
}

int priority(char *simb) {
	if (simb[0] == ' ')
		return (0);
	if (simb[0] == '-' || simb[0] == '+')
		return (1);
	if (simb[0] == '*' || simb[0] == '/' || strcmp(simb, "mod") == 0)
		return (2);
	if (simb[0] == '^')
		return (3);
	if ((strcmp(simb, "cos") == 0) || strcmp(simb, "sin") == 0 || strcmp(simb, "tan") == 0 
		|| strcmp(simb, "acos") == 0 || strcmp(simb, "asin") == 0 || strcmp(simb, "atan") == 0
		|| strcmp(simb, "sqrt") == 0 || strcmp(simb, "ln") == 0 || strcmp(simb, "log") == 0)
		return (4);
	return (0);

}

double	calculation(double one, double two, char *simb)
{
	
	if (simb[0] == '-')
		return (one - two);
	if (simb[0] == '+')
		return (one + two);
	if (simb[0] == '*')
		return (one * two);
	if (simb[0] == '/')
		return (one / two);
	if (strcmp(simb, "mod") == 0)
		return (fmod(one, two));
	if (simb[0] == '^')
		return (pow(one, two));
	if (strcmp(simb, "cos") == 0)
		return (cos(two));
	if (strcmp(simb, "sin") == 0)
		return (sin(two));
	if (strcmp(simb, "tan") == 0)
		return (tan(two));
	if (strcmp(simb, "acos") == 0)
		return (acos(two));
	if (strcmp(simb, "asin") == 0)
		return (asin(two));
	if (strcmp(simb, "atan") == 0)
		return (atan(two));
	if (strcmp(simb, "sqrt") == 0)
		return (sqrt(two));
	if (strcmp(simb, "ln") == 0)
		return (log(two));
	if (strcmp(simb, "log") == 0)
		return (log10(two));
	return (two);
}

int check_func(char *str)
{
	return (*str == '+' || *str == '-' || *str == '*' || *str == '/' || *str == '^'
		|| *str == 'm');
}

void	operation(Node_str **operator, Node **ft_double) {
	Node_str	*buff_operator = *operator;
	Node		*buff_double = *ft_double;
	double		result;
	if (buff_double->next == NULL) {
		result = calculation(0, buff_double->value, buff_operator->value);
	}
	else {
		result = calculation(buff_double->next->value, buff_double->value, buff_operator->value);
	}
	if (check_func(buff_operator->value)) {
		buff_double->next->value = result;
		pop(ft_double);
	}
	else
		buff_double->value = result;
	pop_str(operator);
}

void	add_operator(char *str, Node_str **operator, Node **ft_double) {
	char	tmp[10];
	Node_str	*buff_operator = *operator;

	ft_strlcpy(tmp, str, is_operator(str) + 1);
	if (buff_operator == NULL)
		push_str(operator, tmp);
	else if (priority(tmp) > priority(buff_operator->value))
		push_str(operator, tmp);
	else {
		while (buff_operator && priority(tmp) <= priority(buff_operator->value)) {
			operation(operator, ft_double);
			buff_operator = *operator;
		}
		push_str(operator, tmp);
	}
}

int	add_hooks(char *hook, Node_str **operator, Node **ft_double) {
	char		tmp[2];
	Node_str	*buff_operator = *operator;

	ft_strlcpy(tmp, hook, 2);
	if (tmp[0] == '(') {
		push_str(operator, tmp);
	}
	else if (tmp[0] == ')') {
		while (buff_operator->value[0] != '(') {
			operation(operator, ft_double);
			buff_operator = *operator;
		}
		if (buff_operator->value[0] == '(') {
			pop_str(operator);
		}
	}
	return (1);
}

double	procces(char *str) {
	Node		*ft_double = NULL;
	Node_str	*operator = NULL;
	int			flag = 0;
	double		result;

	while (*str){
		if (*str == '-' && flag == 1 || *str == '+' && flag == 1 ||
			((*str < '0' || *str > '9') && *str != '(' && *str != ')'
			&& *str != '+' && *str != '-') && *str != '.') {
			if ((*(str + 1) == '-' || *(str + 1) == '+') && (*str < '0' || *str > '9'))
				flag = 0;
			add_operator(str, &operator, &ft_double);
			str+=is_operator(str);
		}
		else if (*str == '-' || *str == '+' || (*str >= '0' && *str <= '9')){
			push(&ft_double, atof(str));
			str+=double_size(str);
			flag = 1;
		}
		else if (*str == '(' || *str == ')') {
			str+=add_hooks(str, &operator, &ft_double);
		}
		else {
			break;
		}
	}
	if (*str == '\0') {
		while(operator){
			operation(&operator, &ft_double);
		}	
	}
	if (*str != '\0' || ft_double->next != NULL) {
		return NAN;
	}
	result = ft_double->value;
	pop(&ft_double);

	return result;
}

void	print_stack(Node *ft_double, Node_str *operator) {
	while (ft_double){
		printf("%f\n", ft_double->value);
		ft_double = ft_double->next;
	}
	while (operator) {
		printf("%s\n", operator->value);
		operator = operator->next;
	}
}

int main(int argc, char **argv)
{
	Node		*stack;
	const char	*str = "1+1";
	char		*string;
	double		res;

	if (argc == 2) {
		str = argv[1];
	}
	if (!check_input(str))
		return printf("INPUT ERROR\n");
	string = remove_spaces(str);
	res = procces(string);
	printf("%s = %g\n", string, res);
	return 0;
}