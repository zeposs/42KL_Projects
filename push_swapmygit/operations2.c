/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:22:31 by zernest           #+#    #+#             */
/*   Updated: 2024/10/14 23:08:13 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rr(t_stack **a, t_stack **b, int j)
{
	ft_r1(a, 'a', 0);
	ft_r1(b, 'b', 0);
	if (j == 0)
		write(1, "rr\n", 3);
}

void	ft_rrr(t_stack **a, t_stack **b, int j)
{
	ft_rr1(a, 'a', 0);
	ft_rr1(b, 'b', 0);
	if (j == 0)
		write(1, "rrr\n", 3);
}
