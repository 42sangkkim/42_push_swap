/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:34:48 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/23 20:45:01 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "push_swap.h"
#include "utils.h"

int		parse_input(t_stack *stack, int argc, char **argv);
void	sort_stack(t_push_swap *push_swap);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	init_stack(&a);
	init_stack(&b);
	if (parse_input(&a, argc, argv) < 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		clear_stack(&a);
		clear_stack(&b);
		return (0);
	}
	sort_stack(&a, &b);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
