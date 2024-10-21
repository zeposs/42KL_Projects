/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatenpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:15:27 by zernest           #+#    #+#             */
/*   Updated: 2024/10/21 20:57:38 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_apply_rarb(t_stack **a, t_stack **b, int c, int is_a)
{
	if (is_a)
	{
		while ((*a)->nbr != c && ft_find_place_b(*b, c) > 0)
			ft_rr(a, b, 0);
		while ((*a)->nbr != c)
			ft_r1(a, 'a', 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_r1(b, 'b', 0);
		ft_push(a, b, 'b', 0);
	}
	else
	{
		while ((*b)->nbr != c && ft_find_place_a(*a, c) > 0)
			ft_rr(a, b, 0);
		while ((*b)->nbr != c)
			ft_r1(b, 'b', 0);
		while (ft_find_place_a(*a, c) > 0)
			ft_r1(a, 'a', 0);
		ft_push(b, a, 'a', 0);
	}
	return (-1);
}

int	ft_apply_rrarrb(t_stack **a, t_stack **b, int c, int is_a)
{
	if (is_a)
	{
		while ((*a)->nbr != c && ft_find_place_b(*b, c) > 0)
			ft_rrr(a, b, 0);
		while ((*a)->nbr != c)
			ft_rr1(a, 'a', 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_rr1(b, 'b', 0);
		ft_push(a, b, 'b', 0);
	}
	else
	{
		while ((*b)->nbr != c && ft_find_place_a(*a, c) > 0)
			ft_rrr(a, b, 0);
		while ((*b)->nbr != c)
			ft_rr1(b, 'b', 0);
		while (ft_find_place_a(*a, c) > 0)
			ft_rr1(a, 'a', 0);
		ft_push(b, a, 'a', 0);
	}
	return (-1);
}

int	ft_apply_rrarb(t_stack **a, t_stack **b, int c, int is_a)
{
	if (is_a)
	{
		while ((*a)->nbr != c)
			ft_rr1(a, 'a', 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_r1(b, 'b', 0);
		ft_push(a, b, 'b', 0);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ft_rr1(a, 'a', 0);
		while ((*b)->nbr != c)
			ft_r1(b, 'b', 0);
		ft_push(b, a, 'a', 0);
	}
	return (-1);
}

int	ft_apply_rarrb(t_stack **a, t_stack **b, int c, int is_a)
{
	if (is_a)
	{
		while ((*a)->nbr != c)
			ft_r1(a, 'a', 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_rr1(b, 'b', 0);
		ft_push(a, b, 'b', 0);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ft_r1(a, 'a', 0);
		while ((*b)->nbr != c)
			ft_rr1(b, 'b', 0);
		ft_push(b, a, 'a', 0);
	}
	return (-1);
}
