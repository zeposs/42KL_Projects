/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:30:49 by zernest           #+#    #+#             */
/*   Updated: 2024/10/16 17:42:49 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_parse(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;
	int		j;

	i = 1;
	stack_a = NULL;
	if (ac < 2)
		exit_err_str("Error: Less than 2 arguements");
	else if (ac == 2)
		stack_a = ft_parse_quoted(av);
	else
		convert_to_int(av, &stack_a);
	return (stack_a);
}

t_stack	*ft_parse_quoted(char **av)
{
	t_stack	*stack_a;
	char	**temp;

	stack_a = NULL;
	temp = ft_split(av[1], 32);
	convert_to_int(temp, &stack_a);
	ft_freestr(temp);
	free(temp);
	return (stack_a);
}
