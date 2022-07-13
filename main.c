/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:48:15 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/13 21:31:17 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stack.h"

int		parse_input(t_stack *stack, int argc, char **argv);
int		sort_stack(t_stack *stack_a, t_stack *stack_b);

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a = new_stack();
	stack_b = new_stack();
	if (parse_input(&stack_a, argc, argv) < 0)
	{
		write(2, "Error\n", 6);
		destroy_stack(&stack_a);
		destroy_stack(&stack_b);
		return (-1);
	}
	print_stack(&stack_a);
	if (sort_stack(&stack_a, &stack_b) < 0)
	{
		write(2, "Error\n", 6);
		destroy_stack(&stack_a);
		destroy_stack(&stack_b);
		return (-1);
	}
//	print_stack(&stack_a);
	destroy_stack(&stack_a);
	destroy_stack(&stack_b);
	return (0);
}
