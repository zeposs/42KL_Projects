/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackhandling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:29:37 by zernest           #+#    #+#             */
/*   Updated: 2024/10/15 21:51:51 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_stack_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		exit_error_str("Error: ft_stack_new failed to allocate memory");
	new->nbr = content;
	new->next = NULL;
	return (new);
}

void	ft_add_back(t_stack **stack, t_stack **stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		ft_lstlast(*stack)->next = stack_new;
}

void	convert_to_int(char **av, t_stack **stack)
{
	long	i;

	i = 1;
	while (av[i] != NULL)
	{
		ft_add_back(stack, ft_stack_new(ft_atoi(av[i])));
		i++;
	}
}
