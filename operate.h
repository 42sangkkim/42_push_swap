/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:16:49 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/13 15:58:54 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATE_H
# define OPERATE_H

# include <stdlib.h>
# include "stack.h"

# define OP_SA	0
# define OP_SB	1
# define OP_SS	2
# define OP_PA	3
# define OP_PB	4
# define OP_RA	5
# define OP_RB	6
# define OP_RR	7
# define OP_RRA	8
# define OP_RRB	9
# define OP_RRR	10

void	operate(t_stack *a, t_stack *b, int op, size_t n);

#endif
