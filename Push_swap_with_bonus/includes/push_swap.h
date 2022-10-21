/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:36:18 by cpollito          #+#    #+#             */
/*   Updated: 2022/03/25 22:55:14 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

void	ft_check_valid(char **argv);
t_list	*ft_create_stack_a(int argc, char **argv, t_list *stack_a);
void	ft_check_double(t_list *stack_a);
int		ft_sorted_already(t_list *stack_a);

void	ft_sorting(t_list **stack_a);
void	ft_assign_index(t_list **stack_a, int size);
void	ft_minisort(t_list **stack_a, t_list **stack_b, int size_a);

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_b, t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

long	ft_atoi_ps(const char *str);
char	**ft_split(char const *s, char c);

void	ft_putstr(char *str);
void	ft_error(char *str);
void	ft_free_arr(char **arr);

int		ft_strcmp(const char *s1, const char *s2);
void	sa_bonus(t_list **stack_a);
void	sb_bonus(t_list **stack_b);
void	ss_bonus(t_list **stack_a, t_list **stack_b);
void	pa_bonus(t_list **stack_b, t_list **stack_a);
void	pb_bonus(t_list **stack_a, t_list **stack_b);
void	ra_bonus(t_list **stack_a);
void	rb_bonus(t_list **stack_b);
void	rr_bonus(t_list **stack_a, t_list **stack_b);
void	rra_bonus(t_list **stack_a);
void	rrb_bonus(t_list **stack_b);
void	rrr_bonus(t_list **stack_a, t_list **stack_b);
#endif