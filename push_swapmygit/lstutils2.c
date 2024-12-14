/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstutils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:15:00 by zernest           #+#    #+#             */
/*   Updated: 2024/12/14 22:42:10 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_find_index(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (stack->nbr != n)
	{
		i++;
		stack = stack->next;
	}
	stack->index = 0;
	return (i);
}

int	ft_find_place_b(t_stack *stack_b, int nbr_push)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (nbr_push > stack_b->nbr && nbr_push < ft_lstlast(stack_b)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_b) || nbr_push < ft_min(stack_b))
		i = ft_find_index(stack_b, ft_max(stack_b));
	else
	{
		temp = stack_b->next;
		while (stack_b->nbr < nbr_push || temp->nbr > nbr_push)
		{
			stack_b = stack_b->next;
			temp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	ft_find_place_a(t_stack *stack_a, int nbr_push)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (nbr_push < stack_a->nbr && nbr_push > ft_lstlast(stack_a)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_a) || nbr_push < ft_min(stack_a))
		i = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		temp = stack_a->next;
		while (stack_a->nbr > nbr_push || temp->nbr < nbr_push)
		{
			stack_a = stack_a->next;
			temp = stack_a->next;
			i++;
		}
	}
	return (i);
}
