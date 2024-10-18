/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solverutils_ab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:46:46 by zernest           #+#    #+#             */
/*   Updated: 2024/10/18 16:14:52 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_case_rarb(t_stack *a, t_stack *b, int c, int is_a)
{
	int	i;

	if (is_a)
	{
		i = ft_find_place_a(a, c);
		if (i < ft_find_index(b, c))
			i = ft_find_index(a, c);
	}
	else
	{
		i = ft_find_place_b(b, c);
		if (i < ft_find_index(a, c))
			i = ft_find_index(a, c);
	}
	return (i);
}

int	ft_case_rrarrb(t_stack *a, t_stack *b, int c, int is_a)
{
	int	i;

	i = 0;
	if (is_a)
	{
		if (ft_find_place_a(a, c))
			i = ft_lstsize(a) - ft_find_place_a(a, c);
		if ((i < (ft_lstsize(b) - ft_find_index(b, c))) && ft_find_index(b, c))
			i = ft_lstsize(b) - ft_find_index(b, c);
	}
	else
	{
		if (ft_find_place_b(b, c))
			i = ft_lstsize(b) - ft_find_place_b(b, c);
		if ((i < (ft_lstsize(a) - ft_find_index(a, c))) && ft_find_index(a, c))
			i = ft_lstsize(a) - ft_find_index(a, c);
	}
	return (i);
}

int	ft_case_rrarb(t_stack *a, t_stack *b, int c, int is_a)
{
	int	i;

	i = 0;
	if (is_a)
	{
		if (ft_find_index(b, c))
			i = ft_lstsize(b) - ft_find_index(b, c);
		i = ft_find_place_a(a, c) + i;
	}
	else
	{
		if (ft_find_index(a, c))
			i = ft_lstsize(a) - ft_find_index(a, c);
		i = ft_find_place_b(b, c) + i;
	}
	return (i);
}

int	ft_case_rarrb(t_stack *a, t_stack *b, int c, int is_a)
{
	int	i;

	i = 0;
	if (is_a)
	{
		if (ft_find_place_a(a, c))
			i = ft_lstsize(a) - ft_find_place_a(a, c);
		i = ft_find_index(b, c) + i;
	}
	else
	{
		if (ft_find_place_b(b, c))
			i = ft_lstsize(b) - ft_find_place_b(b, c);
		i = ft_find_index(a, c) + i;
	}
	return (i);
}