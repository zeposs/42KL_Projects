/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:01:38 by zernest           #+#    #+#             */
/*   Updated: 2024/10/14 23:09:39 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* ERROR RELATED */

void	exit_error_str(char *str);
void	ft_putstr_err(char *s);

/* LIST UTILITIES */

t_stack	*ft_lstlast(t_stack *lst);

/* BASIC OPERATIONS */

void	ft_r1(t_stack **stack, char stack_letter, int j);
void	ft_s1(t_stack **stack, char stack_letter, int j);
void	ft_push(t_stack **src, t_stack **dst, char direction, int j);
void	ft_rr1(t_stack **stack, char stack_letter, int j);
void	ft_ss(t_stack **a, t_stack **b, int j);	
void	ft_rr(t_stack **a, t_stack **b, int j);
void	ft_rrr(t_stack **a, t_stack **b, int j);

#endif