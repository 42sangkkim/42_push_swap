/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:26:34 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/22 17:27:30 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	print_stack(t_stack *stack);
int		ft_pow(int a, int b);
int		to_array(t_stack *stack, int **arr_ptr);
void	print_push_swap(t_push_swap *ps);

#endif