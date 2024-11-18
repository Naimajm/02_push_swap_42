/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:26:03 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/18 19:25:00 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**parse_arguments(int argc, char **argv);
static void	free_split_argvs(char **split_args);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**split_args;

	stack_a = NULL;
	stack_b = NULL;
	split_args = parse_arguments(argc, argv);
	if (split_args)
		argv = split_args;
	init_stack(&stack_a, argv + 1);
	if (!is_stack_sorted(stack_a))
		push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (split_args)
		free_split_argvs(split_args);
	return (0);
}

static char	**parse_arguments(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (argc == 2 && argv[1][0] == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else if (argc == 2)
		return (split_push_swap(argv[1], ' '));
	return (NULL);
}

static void	free_split_argvs(char **split_args)
{
	int	index;

	index = 0;
	while (split_args[index])
		free(split_args[index++]);
	free(split_args);
}
