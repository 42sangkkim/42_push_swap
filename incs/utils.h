/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:26:34 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/23 21:35:33 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "stack.h"

// utils1.c
int		is_sorted(t_stack *stack, size_t n);
int		ft_pow(int a, int b);
int		value_of(t_stack *stack, int i);

#endif