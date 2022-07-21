/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:48:15 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/21 11:59:40 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stack.h"

int		parse_input(t_stack *stack, int argc, char **argv);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	init_stack(&a);
	init_stack(&b);
	if (parse_input(&a, argc, argv) < 0)
	{
		write(2, "Error\n", 6);
		destroy_stack(&a);
		destroy_stack(&b);
		return (-1);
	}
	sort_stack(&a, &b);
	print_stack(&a);
	destroy_stack(&a);
	destroy_stack(&b);
	return (0);
}
