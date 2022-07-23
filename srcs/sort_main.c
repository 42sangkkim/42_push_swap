/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 22:14:31 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/23 21:01:44 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

int		sort_tiny(t_stack *a, t_stack *b);
void	sort_init(t_stack *a, t_stack *b, size_t n, int depth);
void	sort_merge(t_stack *a, t_stack *b, size_t n, int depth);

int		calc_depth(size_t n);

void	sort_stack(t_stack *a, t_stack *b)
{
	int		depth;
	size_t	n;

	if (is_sorted(a, a->len))
		return ;
	n = a->len;
	if (n <= 6)
		sort_tiny(push_swap);
	else
	{
		depth = calc_depth(n);
		if (depth % 2 == 1)
		{
			while (pb(a, b, 1))
				;
		}
		init_depth(push_swap, n, depth);
		while (depth--)
			merge_depth(push_swap, n, depth);
	}
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
	if (pow == 1)
		return (1);
	else if (i < pow / 3)
		return (calc_direction(pow / 3, i));
	else if (i < 2 * pow / 3)
		return (!calc_direction(pow / 3, 2 * pow / 3 - 1 - i));
	else
		return (!calc_direction(pow / 3, pow - 1 - i));
}

size_t	calc_amount(size_t pow, size_t i, size_t n)
{
	size_t	tmp;

	if (pow == 1)
		return (n);
	else if (i < pow / 3)
	{
		tmp = calc_amount(pow / 3, i, n);
		return (tmp / 3);
	}
	else if (i < 2 * pow / 3)
	{
		tmp = calc_amount(pow / 3, 2 * pow / 3 - 1 - i, n);
		return (tmp / 3 + (tmp % 3 > 0));
	}
	else
	{
		tmp = calc_amount(pow / 3, pow - 1 - i, n);
		return (tmp / 3 + (tmp % 3 > 1));
	}
}
