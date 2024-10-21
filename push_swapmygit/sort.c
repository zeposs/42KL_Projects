/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:38:58 by zernest           #+#    #+#             */
/*   Updated: 2024/10/21 21:00:48 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort_three(t_stack **a)
{
	if (ft_min(*a) == (*a)->nbr)
	{
		ft_rr1(a, 'a', 0);
		ft_s1(a, 'a', 0);
	}
	else if (ft_max(*a) == (*a)->nbr)
	{
		ft_r1(a, 'a', 0);
		if (!ft_checksorted(*a))
			ft_s1(a, 'a', 0);
	}
	else
	{
		if (ft_find_index(*a, ft_max(*a)) == 1)
			ft_rr1(a, 'a', 0);
		else
			ft_s1(a, 'a', 0);
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

t_stack	*ft_sort_b(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (ft_lstsize(*a) > 3 && !ft_checksorted(*a))
		ft_push(a, &b, 'b', 0);
	if (ft_lstsize(*a) > 3 && !ft_checksorted(*a))
		ft_push(a, &b, 'b', 0);
	if (ft_lstsize(*a) > 3 && !ft_checksorted(*a))
		ft_sort_b_till_3(a, &b);
	if (!ft_checksorted(*a))
		ft_sort_three(a);
	return (b);
}

t_stack	**ft_sort_a(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*temp;

	while (*b)
	{
		temp = *b;
		i = ft_rotate_type_ba(*a, *b);
		while (i >= 0)
		{
			if (i == ft_case_rarb(*a, *b, temp->nbr, 1))
				i = ft_apply_rarb(a, b, temp->nbr, 0);
			else if (i == ft_case_rarrb(*a, *b, temp->nbr, 1))
				i = ft_apply_rarrb(a, b, temp->nbr, 0);
			else if (i == ft_case_rrarrb(*a, *b, temp->nbr, 1))
				i = ft_apply_rrarrb(a, b, temp->nbr, 0);
			else if (i == ft_case_rrarb(*a, *b, temp->nbr, 1))
				i = ft_apply_rrarb(a, b, temp->nbr, 0);
			else
				temp = temp->next;
		}
	}
	return (a);
}

void	ft_sort(t_stack **a)
{
	t_stack	*b;
	int		i;

	b = NULL;
	if (ft_lstsize(*a) == 2)
		ft_s1(a, 'a', 0);
	else
	{
		b = ft_sort_b(a);
		a = ft_sort_a(a, &b);
		i = ft_find_index(*a, ft_min(*a));
		if (i < ft_lstsize(*a) - 1)
		{
			while ((*a)->nbr != ft_min(*a))
				ft_r1(a, 'a', 0);
		}
		else
		{
			while ((*a)->nbr != ft_min(*a))
				ft_rr1(a, 'a', 0);
		}
	}
}
