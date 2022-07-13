/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:12:29 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/13 15:49:58 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

void	rotate(t_stack *stack)
{
	if (stack->len < 2)
		return ;
	else
		stack->top = stack->top->next;
}

int	is_sorted(t_stack *stack, size_t n)
{
	int		*array;
	size_t	i;

	array = to_array(stack);
	if (!array)
		return (-1);
	if (n > stack->len)
		n = stack->len;
	i = 0;
	while (i + 1 < n)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_rev_sorted(t_stack *stack, size_t n)
{
	int		*array;
	size_t	i;

	array = to_array(stack);
	if (!array)
		return (-1);
	if (n > stack->len)
		n = stack->len;
	i = 0;
	while (i + 1 < n)
	{
		if (array[i] < array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	print_stack(t_stack *stack)
{
	int		*array;
	size_t	i;

	array = to_array(stack);
	if (!array)
		return ;
	i = 0;
	while (i < stack->len)
	{
		ft_putnbr_fd(array[i++], 1);
		ft_putchar_fd('\n', 1);
	}
	free(array);
}
