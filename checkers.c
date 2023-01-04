#include "smart_calc.h"

int my_strcmp(const char *str, const char *str2){
	int i = 0;

	while (str[i]){
		if (str[i] == str2[i]){
			i++;
		}
		else
			return (0);
		if (str2[i] == '\0'){
			break;
		}
	}
	return (1);
}

int check_input(const char *str){
	while (*str){
		if ((*str >= '0' && *str <= '9') || *str == '.'
            || *str == '*' || *str == '/' || *str == '-' || *str == '+'
			|| *str == '(' || *str == ')' || *str == '^' || *str == ' '){
			str++;
		}
		else if (my_strcmp(str, "ln")){
			str+=2;
		}
		else if (my_strcmp(str, "mod") || my_strcmp(str, "cos") || my_strcmp(str, "sin")
		|| my_strcmp(str, "tan") || my_strcmp(str, "log")){
			str+=3;
		}
		else if (my_strcmp(str, "acos") || my_strcmp(str, "asin")
		|| my_strcmp(str, "atan") || my_strcmp(str, "sqrt")){
			str+=4;
		}
		else{
			return (0);
		}
	}
	return (1);
}

char	*remove_spaces(const char *str){
	char	*res;
	int i = 0;
	int k = 0;

	res = malloc(sizeof(char) * strlen(str) + 1);
	while (str[i]){
		if (str[i] == ' ' || str[i] == '\n')
			i++;
		else{
			res[k++] = str[i++];
		}
	}
	return (res);
}