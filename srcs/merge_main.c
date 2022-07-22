/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 22:14:31 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/22 00:06:16 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_depth(t_push_swap *push_swap, size_t n, int depth);

int		calc_depth(size_t n);

void	sort_stack(t_push_swap *push_swap)
{
	int		depth;
	size_t	n;

	n = push_swap->a.len;
	depth = get_depth(n);
	init_depth(push_swap, n, depth);
	while (depth--)
		merge_depth(push_swap, n, depth);
}

int	calc_depth(size_t n)
{
	int	depth;

	depth = 0;
	while (n > 4)
	{
		n = n / 3 + (n % 3 > 0);
		depth++;
	}
	return (depth);
}

int	calc_direction(size_t pow, size_t i)
{
	if (pow == 0)
		return (1);
	if (i < pow)
		return (calc_direction(pow / 3, i));
	else
		return (!calc_direction(pow / 3, pow - 1 - (i % pow)));
}

size_t	calc_amount(size_t pow, size_t i, size_t n)
{
	size_t	prev;

	if (pow == 0)
		return (n);
	if (i < pow)
	{
		prev = calc_amount(pow / 3, i, n);
		return (prev / 3 + (prev % 3 > 0));
	}
	else if (i < 2 * pow)
	{
		prev = calc_amount(pow / 3, pow - 1 - (i % pow), n);
		return (prev / 3 + (prev % 3 > 1));
	}
	else
	{
		prev = calc_amount(pow / 3, pow - 1 - (i % pow), n);
		return (prev / 3);
	}
}
