/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatetype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 05:31:35 by zernest           #+#    #+#             */
/*   Updated: 2024/12/14 22:33:32 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_rotate_type_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*temp;

	temp = b;
	i = ft_case_rrarrb(a, b, b->nbr, 1);
	while (temp)
	{
		if (i > ft_case_rarb(a, b, temp->nbr, 1))
			i = ft_case_rarb(a, b, temp->nbr, 1);
		if (i > ft_case_rrarrb(a, b, temp->nbr, 1))
			i = ft_case_rrarrb(a, b, temp->nbr, 1);
		if (i > ft_case_rarrb(a, b, temp->nbr, 1))
			i = ft_case_rarrb(a, b, temp->nbr, 1);
		if (i > ft_case_rrarb(a, b, temp->nbr, 1))
			i = ft_case_rrarb(a, b, temp->nbr, 1);
		temp = temp->next;
	}
	return (i);
}

int	ft_rotate_type_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*temp;

	temp = a;
	i = ft_case_rrarrb(a, b, a->nbr, 0);
	while (temp)
	{
		if (i > ft_case_rarb(a, b, temp->nbr, 0))
			i = ft_case_rarb(a, b, temp->nbr, 0);
		if (i > ft_case_rrarrb(a, b, temp->nbr, 0))
			i = ft_case_rrarrb(a, b, temp->nbr, 0);
		if (i > ft_case_rarrb(a, b, temp->nbr, 0))
			i = ft_case_rarrb(a, b, temp->nbr, 0);
		if (i > ft_case_rrarb(a, b, temp->nbr, 0))
			i = ft_case_rrarb(a, b, temp->nbr, 0);
		temp = temp->next;
	}
	return (i);
}
