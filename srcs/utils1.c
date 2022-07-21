/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:27:00 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/21 22:06:37 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		ft_putnbr_fd(node->value, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		if (node->next == stack->top)
			break ;
		node = node->next;
	}
}

int	to_array(t_stack *stack, int **arr_ptr)
{
	size_t	i;
	t_node	*node;
	int		*arr;

	arr = malloc(stack->len * sizeof(int));
	if (arr == NULL)
		return (-1);
	node = stack->top;
	i = 0;
	while (i < stack->len)
	{
		arr[i] = node->value;
		i++;
		node = node->next;
	}
	*arr_ptr = arr;
	return (0);
}

int	ft_pow(int a, int b)
{
	int	pow;

	pow = 1;
	while (b-- > 0)
		pow *= a;
	return (pow);
}
