/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:34:54 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/24 15:18:20 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

char	*get_next_line(int fd);
int		parse_input(t_stack *stack, int argc, char **argv);

void	init_push_swap(t_push_swap *push_swap);
void	operate_push_swap(t_push_swap *ps);
int		operate(t_push_swap *ps, char *op);

int	main(int argc, char **argv)
{
	t_push_swap	push_swap;

	init_push_swap(&push_swap);
	if (parse_input(&(push_swap.a), argc, argv) < 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (0);
	}
	operate_push_swap(&push_swap);
	return (0);
}

void	init_push_swap(t_push_swap *push_swap)
{
	push_swap->a.len = 0;
	push_swap->a.top = NULL;
	push_swap->b.len = 0;
	push_swap->b.top = NULL;
}

void	operate_push_swap(t_push_swap *ps)
{
	char	*op;

	op = get_next_line(STDIN_FILENO);
	while (op)
	{
		if (operate(ps, op) < 0)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(-1);
		}
		free(op);
		op = get_next_line(STDIN_FILENO);
	}
	if (ps->b.len == 0 && is_sorted(&(ps->a), ps->a.len))
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
}

int	operate(t_push_swap *ps, char *op)
{
	if (ft_strncmp(op, "sa\n", 4) == 0)
		return (sa(ps, 0));
	else if (ft_strncmp(op, "sb\n", 4) == 0)
		return (sb(ps, 0));
	else if (ft_strncmp(op, "ss\n", 4) == 0)
		return (ss(ps, 0));
	else if (ft_strncmp(op, "pa\n", 4) == 0)
		return (pa(ps, 0));
	else if (ft_strncmp(op, "pb\n", 4) == 0)
		return (pb(ps, 0));
	else if (ft_strncmp(op, "ra\n", 4) == 0)
		return (ra(ps, 0));
	else if (ft_strncmp(op, "rb\n", 4) == 0)
		return (rb(ps, 0));
	else if (ft_strncmp(op, "rr\n", 4) == 0)
		return (rr(ps, 0));
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		return (rra(ps, 0));
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		return (rrb(ps, 0));
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		return (rrr(ps, 0));
	else
		return (-1);
}
