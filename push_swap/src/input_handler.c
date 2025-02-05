/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:14:01 by david             #+#    #+#             */
/*   Updated: 2023/10/31 17:51:07 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
	{
		ft_putendl_fd("Error", 2);
		exit (0);
	}
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

int	len_and_error(char **argv)
{
	int		j;

	j = 0;
	if (argv[j] == 0)
	{
		ft_putendl_fd("Error", 2);
		exit (0);
	}
	while (argv[j] != 0)
		j++;
	return (j);
}

int	*check_inputs_aux(char **argv, int i, int *size)
{
	long	number;
	int		*nbr;

	nbr = (int *)malloc(sizeof(int) * len_and_error(argv));
	if (!nbr)
		exit (0);
	while (argv[i] != 0)
	{
		if (check_num(argv[i]) == 0)
		{
			ft_putendl_fd("Error", 2);
			free(nbr);
			exit (0);
		}
		number = ft_atoi(argv[i]);
		if (number > 2147483647 || number < -2147483648)
		{
			ft_putendl_fd("Error", 2);
			free(nbr);
			exit (0);
		}
		nbr[(*size)++] = (int)number;
		i++;
	}
	return (nbr);
}

void	check_duplicates(int *number, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (number[i] == number[j])
			{
				ft_putendl_fd("Error", 2);
				free(number);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

int	*check_inputs(int argc, char **argv, int *size)
{
	int	*nbr;

	if (argc < 2)
		exit (0);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		nbr = check_inputs_aux(argv, 0, size);
		free_memory(argv);
	}
	else
	{
		nbr = check_inputs_aux(argv, 1, size);
	}
	check_duplicates(nbr, *size);
	return (nbr);
}
