

#include "../headers/philo.h"

static int	check_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		return (0);
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (i == (int)ft_strlen(str))
		return (1);
	return (0);
}

int	input_handler(char **inputs)
{
	int	i;

	i = 1;
	while(inputs[i])
	{
		if(check_num(inputs[i]) == 0)
		{
			printf("Not a valid number\n");
			return (1);
		}
		i++;
	}
	if (ft_atoi(inputs[1]) < 2)
	{
		printf("At least 2 philos\n");
		return (1);
	}
	if (ft_atoi(inputs[1]) > 200)
	{
		printf("Not more than 200 philo\n");
		return (1);
	}
	return (0);
}
