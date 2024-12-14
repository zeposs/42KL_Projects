/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:01:38 by zernest           #+#    #+#             */
/*   Updated: 2024/10/21 21:16:22 by zernest          ###   ########.fr       */
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
void	ft_free(t_stack **lst);
void	ft_freestr(char **lst);

/* LIST UTILITIES */

t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
int		ft_min(t_stack *stack);
int		ft_max(t_stack *stack);
int		ft_find_index(t_stack *stack, int n);
int		ft_find_place_b(t_stack *stack_b, int nbr_push);
int		ft_find_place_a(t_stack *stack_a, int nbr_push);

/* STUFF FOR HANDLING THE STACK */

t_stack	*ft_stack_new(int content);
void	ft_add_back(t_stack **stack, t_stack *stack_new);
void	convert_to_int(char **av, t_stack **stack);
t_stack	*arse(int ac, char **av);
t_stack	*ft_parse_quoted(char **av);

/* BASIC OPERATIONS */

void	ft_r1(t_stack **stack, char stack_letter, int j);
void	ft_s1(t_stack **stack, char stack_letter, int j);
void	ft_push(t_stack **src, t_stack **dst, char direction, int j);
void	ft_rr1(t_stack **stack, char stack_letter, int j);
void	ft_ss(t_stack **a, t_stack **b, int j);	
void	ft_rr(t_stack **a, t_stack **b, int j);
void	ft_rrr(t_stack **a, t_stack **b, int j);

/* FUNCTIONS FOR CHECKING */

void	alpha_check(char **av);
int		issign(int c);
int		isspace(int c);
int		check_error(char **av, int i, int j);
int		check_args(char **argv);
int		ft_checkdup(t_stack *a);
int		ft_checksorted(t_stack *a);

/* ALGORITHM */

int		ft_case_rarb(t_stack *a, t_stack *b, int c, int is_a);
int		ft_case_rrarrb(t_stack *a, t_stack *b, int c, int is_a);
int		ft_case_rrarb(t_stack *a, t_stack *b, int c, int is_a);
int		ft_case_rarrb(t_stack *a, t_stack *b, int c, int is_a);
int		ft_rotate_type_ba(t_stack *a, t_stack *b);
int		ft_rotate_type_ab(t_stack *a, t_stack *b);
int		ft_apply_rarb(t_stack **a, t_stack **b, int c, int is_a);
int		ft_apply_rrarrb(t_stack **a, t_stack **b, int c, int is_a);
int		ft_apply_rrarb(t_stack **a, t_stack **b, int c, int is_a);
int		ft_apply_rarrb(t_stack **a, t_stack **b, int c, int is_a);
void	ft_sort_three(t_stack **a);
void	ft_sort_b_till_3(t_stack **a, t_stack **b);
t_stack	*ft_sort_b(t_stack **a);
t_stack	**ft_sort_a(t_stack **a, t_stack **b);
void	ft_sort(t_stack **a);
t_stack	*ft_process(int ac, char **av);
t_stack	*ft_sub_process(char **av);

#endif