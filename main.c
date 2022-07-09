/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:48:15 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/09 23:02:25 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "stack.h"

int		init_stack(t_stack **stack_a, t_stack **stack_b, int argc, char **argv);
void	print_stack(t_stack *stack);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (init_stack(&stack_a, &stack_b, argc, argv) < 0)
		return (-1);
	print_stack(stack_a);
}

void	print_stack(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		ft_putnbr_fd(stack->data[i++], 1);
		ft_putchar_fd('\n', 1);
	}
}
