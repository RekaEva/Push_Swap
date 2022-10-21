/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:36:21 by cpollito          #+#    #+#             */
/*   Updated: 2022/03/28 16:42:37 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_double(t_list *stack_a)
{
	t_list	*p;

	while (stack_a)
	{
		p = stack_a;
		while (p)
		{
			p = p->next;
			if (p && p->content == stack_a->content)
			{
				ft_lstclear(&stack_a, &free);
				ft_error ("Error\n");
			}
		}
		stack_a = stack_a->next;
	}
}

int	ft_sorted_already(t_list *stack_a)
{
	t_list	*p;
	int		sort_ok;

	sort_ok = 0;
	while (stack_a)
	{
		p = stack_a;
		while (p)
		{
			p = p->next;
			if (p && p->content < stack_a->content)
			{
				sort_ok = 1;
				break ;
			}
		}
		stack_a = stack_a->next;
	}
	if (sort_ok == 0)
		return (0);
	return (1);
}

void	ft_check_valid(char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (argv[i])
	{
		k = 0;
		while (argv[i][k])
		{
			if ((argv[i][k] >= 58 && argv[i][k] <= 126)
				|| (argv[i][k] >= 33 && argv[i][k] <= 42)
				|| (argv[i][k] == 46 || argv[i][k] == 47)
				|| (argv[i][k] == 44))
				ft_error("Error\n");
			if ((argv[i][k] == '-' || argv[i][k] == '+')
				&& (argv[i][k + 1] == '-' || argv[i][k + 1] == '+'))
				ft_error("Error\n");
			if ((argv[i][k] == '-' || argv[i][k] == '+')
				&& (argv[i][k + 1] < '0' || argv[i][k + 1] > '9'))
				ft_error("Error\n");
			k++;
		}
		i++;
	}
}

void	ft_becouse_norminette(long *num, t_list **stack_a)
{
	t_list	*tmp;

	if ((*num < INT_MIN) || (*num > INT_MAX))
		ft_error("Error\n");
	tmp = ft_lstnew(*num);
	ft_lstadd_front(&(*stack_a), tmp);
}

t_list	*ft_create_stack_a(int argc, char **argv, t_list *stack_a)
{
	long	num;
	char	**split;
	int		i;
	int		k;

	i = argc - 1;
	while (i > 0)
	{
		split = ft_split(argv[i], ' ');
		k = 0;
		while (split[k])
			k++;
		k = k - 1;
		while (k >= 0)
		{
			num = ft_atoi_ps(split[k]);
			ft_becouse_norminette(&num, &stack_a);
			k--;
		}
		ft_free_arr(split);
		i--;
	}
	return (stack_a);
}
