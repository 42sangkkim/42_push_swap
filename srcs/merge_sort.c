/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:47:22 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/20 17:19:36 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "operation.h"

int	ft_pow(int a, int b)
{
	int	pow;

	pow = 1;
	while (b-- > 0)
		pow *= a;
	return (a);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int		depth;
	size_t	n;

	n = a->len;
	depth = get_depth(n);
	init_depth(a, b, n, depth);
	merge_depth(a, b, n, depth - 1);
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
