/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:38:58 by zernest           #+#    #+#             */
/*   Updated: 2024/10/18 20:22:08 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort_three(t_stack **a)
{
	if (ft_min(*a) == (*a)->nbr)
	{
		ft_rra(a, 0);
		ft_sa(a, 0);
	}
	else if (ft_max(*a) == (*a)->nbr)
	{
		ft_ra(*a, 0);
		if (!checksorted(*a))
			ft_sa(a, 0);
	}
	else
	{
		if (ft_find_index(*a, ft_max(*a)) == 1)
			ft_rra(a, 0);
		else
			ft_sa(a, 0);
	}
}

void	ft_sort_b_till_3(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*temp;

	while (ft_lstsize(*a) > 3 && !ft_checksorted(*a))
	{
		temp = *a;
		i = ft_rotate_type_ab(*a, *b);
		while (i >= 0)
		{
			if (i == ft_case_rarb(*a, *b, temp->nbr, 0))
				i = ft_apply_rarb(a, b, temp->nbr, 1);
			else if (i == ft_case_rrarrb(*a, *b, temp->nbr, 0))
				i = ft_apply_rrarrb(a, b, temp->nbr, 1);
			else if (i == ft_case_rarrb(*a, *b, temp->nbr, 0))
				i = ft_apply_rarrb(a, b, temp->nbr, 1);
			else if (i == ft_case_rrarb(*a, *b, temp->nbr, 0))
				i = ft_apply_rrarb(a, b, temp->nbr, 1);
			else
				temp = temp->next;
		}
	}
}
