#include "smart_calc.h"

double	procces(char *str){
	Node		*ft_double = NULL;
	Node_str	*operator = NULL;
	char		*prev = str;

	while (*str){
		if (*str >= '0' && *str <= '9'){
			push(&ft_double, atof(str));
			str+=double_size(str);
		}
		else{
			str++;
		}
	}
	while (ft_double){
		printf("%f\n", ft_double->value);
		ft_double = ft_double->next;
	}
	return 1.1;
}

int main()
{
	Node		*stack;
	const char	*str = "1.1+2*3+4";
	char		*string;
	double		res;

	if (!check_input(str))
		return printf("INPUT ERROR\n");
	string = remove_spaces(str);
	res = procces(string);
	printf("%s\n", string);
	return 0;
}