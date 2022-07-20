/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:14:54 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/15 23:22:00 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stack.h"

int	to_array(t_stack *stack, int **array_ptr)
{
	size_t	i;
	int		*array;
	t_node	*node;

	if (stack->len == 0)
		return (-1);
	array = malloc(stack->len * sizeof(int));
	if (!array)
	{
		*array_ptr = NULL;
		return (-1);
	}
	i = 0;
	node = stack->top;
	while (i < stack->len)
	{
		array[i] = node->value;
		node = node->next;
		i++;
	}
	*array_ptr = array;
	return (0);
}

static void	put_nbr(int n)
{
	int		upper;
	int		lower;
	char	digit;

	upper = n / 10;
	lower = n % 10;
	if (n < 0)
	{
		write(1, "-", 1);
		upper *= -1;
		lower *= -1;
	}
	if (upper)
		put_nbr(upper);
	digit = lower + '0';
	write(1, &digit, 1);
}

int	print_stack(t_stack *stack)
{
	size_t	i;
	t_node	*node;

	if (stack->len == 0)
		return (0);
	i = 0;
	node = stack->top;
	while (i < stack->len)
	{
		put_nbr(node->value);
		write(1, "\n", 1);
		node = node->next;
		i++;
	}
	return (0);
}
