/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:27:00 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/22 18:41:04 by sangkkim         ###   ########.fr       */
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
	size_t	a_len;
	size_t	b_len;
	t_node	*a;
	t_node	*b;

	a_len = ps->a.len;
	a = ps->a.top;
	b_len = ps->b.len;
	b = ps->b.top;
	ft_putstr_fd("------------\na\tb\n------------\n", 1);
	while (a_len + b_len)
	{
		if (a_len)
		{
			ft_putnbr_fd(a->value, 1);
			a = a->next;
			a_len--;
		}
		ft_putstr_fd("\t", 1);
		if (b_len)
		{
			ft_putnbr_fd(b->value, 1);
			b = b->next;
			b_len--;
		}
		ft_putstr_fd("\n", 1);
	}
	ft_putstr_fd("------------\n", 1);
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

int is_sorted(t_stack *stack, size_t n)
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
