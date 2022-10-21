/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:44:42 by cpollito          #+#    #+#             */
/*   Updated: 2022/03/25 19:21:20 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*tmp;

	if (*stack_a && (*stack_a)->next)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
		ft_lstadd_back(&(*stack_a), tmp);
		ft_putstr("ra\n");
	}
}

void	rb(t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b && (*stack_b)->next)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
		ft_lstadd_back(&(*stack_b), tmp);
		ft_putstr("rb\n");
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
		ft_lstadd_back(&(*stack_a), tmp);
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
		ft_lstadd_back(&(*stack_b), tmp);
		ft_putstr("rr\n");
	}
}
