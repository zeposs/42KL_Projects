/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:22:31 by zernest           #+#    #+#             */
/*   Updated: 2024/10/14 23:09:36 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_r1(t_stack **stack, char stack_letter, int j)
{
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = ft_lstlast(*stack);
	(*stack)->next = temp;
	*stack = temp->next;
	temp->next = NULL;
	if (j == 0)
	{
		write(1, "r", 1);
		write(1, &stack_letter, 1);
		write(1, "\n", 1);
	}
}

void	ft_s1(t_stack **stack, char stack_letter, int j)
{
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	if (j == 0)
	{
		write(1, "s", 1);
		write(1, &stack_letter, 1);
		write(1, "\n", 1);
	}
}

void	ft_push(t_stack **src, t_stack **dst, char direction, int j)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = *dst;
	*dst = *src;
	*src = (*src)->next;
	(*dst)->next = temp;
	if (j == 0)
	{
		if (direction == 'b')
			write(1, "pb\n", 3);
		else if (direction == 'a')
			write(1, "pa\n", 3);
		else
			ft_putstr_fd("push operation direct not specified", 1);
	}
}

void	ft_rr1(t_stack **stack, char stack_letter, int j)
{
	t_stack	*temp;
	int		i;

	if (!*stack || !(*stack)->next)
		return ;
	i = 0;
	temp = *stack;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	if (j == 0)
	{
		write(1, "rr", 1);
		write(1, &stack_letter, 1);
		write(1, "\n", 1);
	}
}

void	ft_ss(t_stack **a, t_stack **b, int j)
{
	ft_s1(a, 'a', 0);
	ft_s1(b, 'b', 0);
	if (j == 0)
		write(1, "ss\n", 3);
}
