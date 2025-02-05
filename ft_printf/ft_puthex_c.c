/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:02:00 by dyanez-m          #+#    #+#             */
/*   Updated: 2024/09/26 13:31:47 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	ft_puthex_c(unsigned int n, int up)
{
	int		len;

	len = ft_ulllen_base((unsigned long long)n, 16);
	if (up == 1)
		ft_write_ull((unsigned long long)n, 16, HEX_UP);
	else
		ft_write_ull((unsigned long long)n, 16, HEX_LOW);
	return (len);
}
