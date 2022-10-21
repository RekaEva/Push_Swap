/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:00:29 by cpollito          #+#    #+#             */
/*   Updated: 2022/03/25 19:22:25 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_index(t_list **stack_a, int size, int *array)
{
	int		i;
	int		k;
	t_list	*tmp;

	tmp = *stack_a;
	while (*stack_a)
	{
		i = 0;
		k = 0;
		while (i < size)
		{
			if (array[i] == (*stack_a)->content)
			{
				k = 1;
				(*stack_a)->index = i;
			}
			i++;
		}
		*stack_a = (*stack_a)->next;
	}
	*stack_a = tmp;
}

int	*ft_bubble(int *array, int size)
{
	int		sort;
	int		i;
	int		tmp;

	sort = -1;
	while (sort != 0)
	{
		sort = 0;
		i = 0;
		while (i < size)
		{
			if ((i + 1) < size && array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				sort = -1;
			}
			i++;
		}
	}
	return (array);
}

void	ft_assign_index(t_list **stack_a, int size)
{
	int		*array;
	int		i;
	t_list	*lst;

	lst = *stack_a;
	array = (int *)malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		array[i] = (*stack_a)->content;
		i++;
		*stack_a = (*stack_a)->next;
	}
	array = ft_bubble(array, size);
	*stack_a = lst;
	ft_find_index(&(*stack_a), size, array);
	free(array);
}
