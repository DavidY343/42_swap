/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:41:22 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/09/19 20:01:32 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_base(int n, int base_len)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

int	ft_putnbr_c(int n)
{
	char	digit;
	int		len;

	len = ft_len_base(n, 10);
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n > 9)
	{
		ft_putnbr_c(n / 10);
		ft_putnbr_c(n % 10);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		ft_putnbr_c(n);
	}
	else
	{
		digit = '0' + n;
		write(1, &digit, 1);
	}
	return (len);
}