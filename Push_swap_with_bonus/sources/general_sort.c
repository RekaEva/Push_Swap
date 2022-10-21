/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:57:24 by cpollito          #+#    #+#             */
/*   Updated: 2022/03/25 19:23:01 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_the_index(t_list **stack_b, int *marker)
{
	int		max_index;
	int		counter;
	t_list	*tmp;

	tmp = *stack_b;
	max_index = (*stack_b)->index;
	counter = 1;
	while (*stack_b)
	{
		if ((*stack_b)->index > max_index)
		{
			max_index = (*stack_b)->index;
			*marker = counter;
		}
		counter++;
		*stack_b = (*stack_b)->next;
	}
	*stack_b = tmp;
	return (max_index);
}

void	ft_rotate_stack_b(t_list **stack_b, int size_b,
	int marker, int max_index)
{
	if (marker <= size_b / 2)
	{
		while ((*stack_b)->index != max_index)
			rb(&(*stack_b));
	}
	else
	{
		while ((*stack_b)->index != max_index)
			rrb(&(*stack_b));
	}
}

void	ft_butterfly(t_list **stack_a, t_list **stack_b, int step)
{
	int	i;
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	i = 0;
	while (size_a > 0 && *stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(&(*stack_a), &(*stack_b));
			i++;
		}
		else if ((*stack_a)->index <= (i + step))
		{
			pb(&(*stack_a), &(*stack_b));
			rb(&(*stack_b));
			i++;
		}
		else
			ra(&(*stack_a));
	}
}

void	ft_final_sort(t_list **stack_a, t_list **stack_b)
{
	int	max_index;
	int	marker;
	int	size_b;

	marker = 1;
	while (*stack_b)
	{
		size_b = ft_lstsize(*stack_b);
		max_index = ft_find_the_index(&(*stack_b), &marker);
		ft_rotate_stack_b(&(*stack_b), size_b, marker, max_index);
		pa(&(*stack_b), &(*stack_a));
	}
}

void	ft_sorting(t_list **stack_a)
{
	int		size_a;
	t_list	*stack_b;

	stack_b = 0;
	size_a = ft_lstsize(*stack_a);
	ft_assign_index(&(*stack_a), size_a);
	if (size_a <= 5)
		ft_minisort(&(*stack_a), &stack_b, size_a);
	else
	{
		if (size_a <= 100)
			ft_butterfly(&(*stack_a), &stack_b, 15);
		else
			ft_butterfly(&(*stack_a), &stack_b, 30);
		ft_final_sort(&(*stack_a), &stack_b);
	}
}
