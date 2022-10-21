/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:39:58 by cpollito          #+#    #+#             */
/*   Updated: 2022/03/25 23:06:05 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	ft_am_i_command(char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		return (1);
	if (ft_strcmp(str, "sb\n") == 0)
		return (2);
	if (ft_strcmp(str, "ss\n") == 0)
		return (3);
	if (ft_strcmp(str, "pa\n") == 0)
		return (4);
	if (ft_strcmp(str, "pb\n") == 0)
		return (5);
	if (ft_strcmp(str, "ra\n") == 0)
		return (6);
	if (ft_strcmp(str, "rb\n") == 0)
		return (7);
	if (ft_strcmp(str, "rr\n") == 0)
		return (8);
	if (ft_strcmp(str, "rra\n") == 0)
		return (9);
	if (ft_strcmp(str, "rrb\n") == 0)
		return (10);
	if (ft_strcmp(str, "rrr\n") == 0)
		return (11);
	return (0);
}

void	ft_execute_cmd(t_list **stack_a, t_list **stack_b, int cmd)
{
	if (cmd == 1)
		(sa_bonus(&(*stack_a)));
	if (cmd == 2)
		sb_bonus(&(*stack_b));
	if (cmd == 3)
		ss_bonus(&(*stack_a), &(*stack_b));
	if (cmd == 4)
		pa_bonus(&(*stack_b), &(*stack_a));
	if (cmd == 5)
		pb_bonus(&(*stack_a), &(*stack_b));
	if (cmd == 6)
		ra_bonus(&(*stack_a));
	if (cmd == 7)
		rb_bonus(&(*stack_b));
	if (cmd == 8)
		rr_bonus(&(*stack_a), &(*stack_b));
	if (cmd == 9)
		rra_bonus(&(*stack_a));
	if (cmd == 10)
		rrb_bonus(&(*stack_b));
	if (cmd == 11)
		rrr_bonus(&(*stack_a), &(*stack_b));
}

void	ft_final_check(t_list **stack_a, t_list **stack_b)
{
	int	sort_ok;

	sort_ok = ft_sorted_already(*stack_a);
	if (sort_ok == 0 && *stack_b == 0)
		write (1, "OK", 2);
	else
		write (1, "KO", 2);
}

void	ft_checker(char **str, t_list **stack_a, t_list **stack_b)
{
	int		cmd_exist;

	while (*str)
	{
		cmd_exist = ft_am_i_command(*str);
		free(*str);
		if (cmd_exist == 0)
			ft_error("Error");
		else
			ft_execute_cmd(&(*stack_a), &(*stack_b), cmd_exist);
		*str = get_next_line(STDIN_FILENO);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*str;

	stack_a = 0;
	stack_b = 0;
	if (argc < 2)
		return (0);
	else
	{
		ft_check_valid(argv);
		stack_a = ft_create_stack_a(argc, argv, stack_a);
		ft_check_double(stack_a);
		str = get_next_line(STDIN_FILENO);
		ft_checker(&str, &stack_a, &stack_b);
		ft_final_check(&stack_a, &stack_b);
	}
	ft_lstclear(&stack_a, &free);
	return (0);
}
