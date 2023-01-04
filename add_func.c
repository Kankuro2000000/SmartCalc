#include "smart_calc.h"

int	double_size(char *str)
{
	int	negative;
	int i;
	int flag = 0;

	i = 0;
	negative = 0;
	if (*str == '-')
	{
		negative = 1;
		str++;
	}
	while ((*str && *str >= '0' && *str <= '9' || *str == '.') && flag !=1)
	{
		if (*str == '.'){
			flag = 1;
		}
		str++;
		i++;
	}
	return (i + 1 + negative);
}