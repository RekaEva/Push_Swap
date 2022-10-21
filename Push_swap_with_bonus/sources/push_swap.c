/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:36:15 by cpollito          #+#    #+#             */
/*   Updated: 2022/03/25 19:23:24 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	stack_a = 0;
	if (argc > 1)
	{
		ft_check_valid(argv);
		stack_a = ft_create_stack_a(argc, argv, stack_a);
		ft_check_double(stack_a);
		if (ft_sorted_already(stack_a) == 1)
			ft_sorting(&stack_a);
	}
	ft_lstclear(&stack_a, &free);
	return (0);
}
