/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:44:45 by cpollito          #+#    #+#             */
/*   Updated: 2022/03/25 19:21:33 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*stack_a && (*stack_a)->next)
	{
		tmp = *stack_a;
		while ((*stack_a)->next->next != 0)
			*stack_a = (*stack_a)->next;
		tmp2 = (*stack_a)->next;
		(*stack_a)->next = NULL;
		*stack_a = tmp;
		ft_lstadd_front(&(*stack_a), tmp2);
		ft_putstr("rra\n");
	}
}

void	rrb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*stack_b && (*stack_b)->next)
	{
		tmp = *stack_b;
		while ((*stack_b)->next->next != 0)
			*stack_b = (*stack_b)->next;
		tmp2 = (*stack_b)->next;
		(*stack_b)->next = NULL;
		*stack_b = tmp;
		ft_lstadd_front(&(*stack_b), tmp2);
		ft_putstr("rrb\n");
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		tmp = *stack_a;
		while ((*stack_a)->next->next != 0)
			*stack_a = (*stack_a)->next;
		tmp2 = (*stack_a)->next;
		(*stack_a)->next = NULL;
		*stack_a = tmp;
		ft_lstadd_front(&(*stack_a), tmp2);
		tmp = *stack_b;
		while ((*stack_b)->next->next != 0)
			*stack_b = (*stack_b)->next;
		tmp2 = (*stack_b)->next;
		(*stack_b)->next = NULL;
		*stack_b = tmp;
		ft_lstadd_front(&(*stack_b), tmp2);
		ft_putstr("rrr\n");
	}
}
