/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:34:48 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/22 19:55:01 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

void	init_push_swap(t_push_swap *push_swap);
int		parse_input(t_stack *stack, int argc, char **argv);
void	sort_stack(t_push_swap *push_swap);

int	main(int argc, char **argv)
{
	t_push_swap	push_swap;

	init_push_swap(&push_swap);
	if (parse_input(&(push_swap.a), argc, argv) < 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (0);
	}
	sort_stack(&push_swap);
	return (0);
}

void	init_push_swap(t_push_swap *push_swap)
{
	push_swap->a.len = 0;
	push_swap->a.top = NULL;
	push_swap->b.len = 0;
	push_swap->b.top = NULL;
}
