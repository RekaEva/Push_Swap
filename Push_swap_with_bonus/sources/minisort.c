/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:36:30 by cpollito          #+#    #+#             */
/*   Updated: 2022/03/25 19:23:11 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_triple_sort(t_list **stack_a)
{	
	int	first;
	int	second;
	int	third;

	first = ((*stack_a)->index);
	second = ((*stack_a)->next)->index;
	third = ((*stack_a)->next->next)->index;
	if (second > third && first < third)
	{
		rra(&(*stack_a));
		sa(&(*stack_a));
	}
	else if (first > second && first < third)
		sa(&(*stack_a));
	else if (second > first && second > third)
		rra(&(*stack_a));
	else if (first > second && second < third)
		ra(&(*stack_a));
	else if (first > second && first > third)
	{
		ra(&(*stack_a));
		sa(&(*stack_a));
	}
}

void	ft_rotate_stack_a(t_list **stack_a, int value)
{
	while ((*stack_a)->index != value)
	{
		ra(&(*stack_a));
	}
}

void	ft_four_sort(t_list **stack_a, t_list **stack_b)
{
	int		min;
	t_list	*tmp;

	min = (*stack_a)->index;
	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->next && tmp->next->index < min)
			min = tmp->next->index;
		tmp = tmp->next;
	}
	if (min == tmp->index)
		rra(&(*stack_a));
	else
		ft_rotate_stack_a(&(*stack_a), min);
	pb(&(*stack_a), &(*stack_b));
	ft_triple_sort(&(*stack_a));
	pa(&(*stack_b), &(*stack_a));
}

void	ft_five_sort(t_list **stack_a, t_list **stack_b)
{
	int		max;
	t_list	*tmp;

	max = (*stack_a)->index;
	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->next && tmp->next->index > max)
			max = tmp->next->index;
		tmp = tmp->next;
	}
	if (max == tmp->index)
		rra(&(*stack_a));
	else
		ft_rotate_stack_a(&(*stack_a), max);
	pb(&(*stack_a), &(*stack_b));
	ft_four_sort(&(*stack_a), &(*stack_b));
	pa(&(*stack_b), &(*stack_a));
	ra(&(*stack_a));
}

void	ft_minisort(t_list **stack_a, t_list **stack_b, int size_a)
{
	if (size_a == 2)
		ra(&(*stack_a));
	if (size_a == 3)
		ft_triple_sort(&(*stack_a));
	if (size_a == 4)
		ft_four_sort(&(*stack_a), &(*stack_b));
	if (size_a == 5)
		ft_five_sort(&(*stack_a), &(*stack_b));
}
