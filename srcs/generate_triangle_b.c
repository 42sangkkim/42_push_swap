/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_triangle_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:19:34 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/23 21:42:48 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	generate_triangle_b(t_stack *a, t_stack *b, int dir, size_t amt)
{
	if ()
	if (amt <= 1)
		return (pb(a, b, 1));
	if (amt == 2)
	{
		if ((value_of(a, 0) > value_of(a, 1)) == dir)
			sa(a, b, 1);
		return (pb(a, b, 1) && pb(a, b, 1));
	}
	if (amt == 3)
	{
		if ((value_of(a, 0) > value_of(a, 1) != dir)
			sa(a, b, 1);
		if ((value_of(a, 0) > value_of(a, -1)) != dir)
			return (rra(a, b, 1) && pb(a, b, 1) && pb(a, b, 1) && pb(a, b, 1));
			
	}
}