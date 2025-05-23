/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:36:57 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/03 15:12:28 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	first_part(t_stack **a, t_stack **b, int chunk)
{
	int	mid;
	int	ra_uses;

	while ((*a) != NULL && is_sorted_asc(*a, chunk) == 0)
	{
		mid = find_mid(*a, chunk);
		ra_uses = scan_through_a(a, b, mid, chunk);
		while (ra_uses > 0 && chunk != 0)
		{
			rra(a);
			ra_uses--;
		}
		if (count_elements(*a, chunk) == 3)
			sort_three(a);
		if (count_elements(*a, chunk) == 2 && !is_sorted_asc(*a, chunk))
			sa(a);
	}
}

void	second_part(t_stack **a, t_stack **b, int chunk)
{
	int	mid;
	int	rb_uses;

	while (is_sorted_desc(*b, chunk) == 0 && is_sorted_asc(*a, -1) == 1)
	{
		mid = find_mid(*b, chunk);
		rb_uses = scan_through_b(a, b, mid, chunk);
		while (rb_uses > 0 && chunk != 0)
		{
			rrb(b);
			rb_uses--;
		}
		if (count_elements(*b, chunk) == 2)
		{
			(*b)->chunk = peek_chunk(*a) + 1;
			(*b)->next->chunk = peek_chunk(*a) + 1;
			pa(a, b);
			pa(a, b);
			if ((*a)->n > (*a)->next->n)
				sa(a);
		}
	}
}

void	sort(t_stack **a, t_stack **b)
{
	int	chunk;

	while (is_sorted_asc(*a, 0) == 0 || *b != NULL)
	{
		chunk = peek_chunk(*a);
		first_part(a, b, chunk);
		chunk = peek_chunk(*b);
		second_part(a, b, chunk);
		while (is_sorted_desc(*b, chunk) && (*b) != NULL
			&& is_sorted_asc(*a, -1) && peek_chunk(*b) == chunk)
		{
			(*b)->chunk = peek_chunk(*a) + 1;
			pa(a, b);
		}
	}
}
