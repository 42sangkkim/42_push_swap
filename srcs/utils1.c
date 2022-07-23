/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:27:00 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/23 18:38:52 by sangkkim         ###   ########.fr       */
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

void	print_push_swap(t_push_swap *ps)
{
	size_t	len[2];
	t_node	*a;
	t_node	*b;

	len[0] = ps->a.len;
	a = ps->a.top;
	len[1] = ps->b.len;
	b = ps->b.top;
	while (len[0] + len[1])
	{
		if (len[0])
		{
			ft_putnbr_fd(a->value, STDOUT_FILENO);
			a = a->next;
			len[0]--;
		}
		ft_putstr_fd("\t", 1);
		if (len[1])
		{
			ft_putnbr_fd(b->value, STDOUT_FILENO);
			b = b->next;
			len[1]--;
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
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

int	is_sorted(t_stack *stack, size_t n)
{
	t_node	*node;

	if (n > stack->len)
		n = stack->len;
	node = stack->top;
	while (--n)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}
