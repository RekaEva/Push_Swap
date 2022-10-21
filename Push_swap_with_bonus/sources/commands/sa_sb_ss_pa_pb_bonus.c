/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_pa_pb_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:44:48 by cpollito          #+#    #+#             */
/*   Updated: 2022/03/25 19:21:38 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_bonus(t_list **stack_a)
{
	t_list	*tmp;

	if (*stack_a && (*stack_a)->next)
	{	
		tmp = (*stack_a)->next;
		(*stack_a)->next = tmp->next;
		tmp->next = (*stack_a);
		*stack_a = tmp;
	}
}

void	sb_bonus(t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b && (*stack_b)->next)
	{
		tmp = (*stack_b)->next;
		(*stack_b)->next = tmp->next;
		tmp->next = (*stack_b);
		*stack_b = tmp;
	}
}

void	ss_bonus(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if ((*stack_a && (*stack_a)->next) && (*stack_b && (*stack_b)->next))
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = tmp->next;
		tmp->next = (*stack_a);
		*stack_a = tmp;
		tmp = (*stack_b)->next;
		(*stack_b)->next = tmp->next;
		tmp->next = (*stack_b);
		*stack_b = tmp;
	}
}

void	pb_bonus(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
		ft_lstadd_front(stack_b, tmp);
	}
}

void	pa_bonus(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;

	if (*stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
		ft_lstadd_front(stack_a, tmp);
	}
}
