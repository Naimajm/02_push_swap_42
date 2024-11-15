/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:23:03 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/15 09:27:26 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	free_all_stack(t_stack **stack_a, t_stack **stack_b);

static void	check_command(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (ft_strncmp(command, "pa\n", 3) == 0)
		pa(stack_a, stack_b, false);
	else if (ft_strncmp(command, "pb\n", 3) == 0)
		pb(stack_b, stack_a, false);
	else if (ft_strncmp(command, "ra\n", ft_strlen("ra\n")) == 0)
		ra(stack_a, false);
	else if (ft_strncmp(command, "rb\n", ft_strlen("rb\n")) == 0)
		rb(stack_b, false);
	else if (ft_strncmp(command, "rr\n", ft_strlen("rr\n")) == 0)
		rr(stack_a, stack_b, false);
	else if (ft_strncmp(command, "rra\n", ft_strlen("rra\n")) == 0)
		rra(stack_a, false);
	else if (ft_strncmp(command, "rrb\n", ft_strlen("rrb\n")) == 0)
		rrb(stack_b, false);
	else if (ft_strncmp(command, "rrr\n", ft_strlen("rrr\n")) == 0)
		rrr(stack_a, stack_b, false);
	else if (ft_strncmp(command, "sa\n", ft_strlen("sa\n")) == 0)
		sa(stack_a, false);
	else if (ft_strncmp(command, "sb\n", ft_strlen("sb\n")) == 0)
		sb(stack_b, false);
	else
		free_all_stack(stack_a, stack_b);
}

static void	free_all_stack(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*next_line;
	int		stack_len;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		argv = split_push_swap(argv[1], ' ');
	init_stack(&stack_a, argv + 1);
	stack_len = get_stack_len(stack_a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		check_command(&stack_a, &stack_b, next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if ((is_stack_sorted(stack_a)) && (stack_len == get_stack_len(stack_a))
		&& get_stack_len(stack_a) > 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&stack_a);
}
