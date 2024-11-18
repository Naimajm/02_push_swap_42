/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:26:03 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/17 23:30:14 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split_argvs(char **split_args);

/* int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2 && argv[1][0] == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else if (argc == 2)
		argv = split_push_swap(argv[1], ' ');
	init_stack(&stack_a, argv + 1);
	if (!is_stack_sorted(stack_a))
		push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
} */

int	main(int argc, char **argv)
{
    t_stack	*stack_a;
    t_stack	*stack_b;
    char	**split_args;

    stack_a = NULL;
    stack_b = NULL;
    split_args = NULL;

    if (argc == 1)
        return (0);
    if (argc == 2 && argv[1][0] == 0)
    {
        ft_putstr_fd("Error\n", 2);
        exit(1);
    }
    else if (argc == 2)
    {
        split_args = split_push_swap(argv[1], ' ');
        argv = split_args;
    }
    init_stack(&stack_a, argv + 1);
    if (!is_stack_sorted(stack_a))
        push_swap(&stack_a, &stack_b);
    free_stack(&stack_a);
    free_stack(&stack_b);
    if (split_args)
        free_split_argvs(split_args);  
    return (0);
}

static void	free_split_argvs(char **split_args)
{
    int index;

    index = 0;
    while (split_args[index])
        free(split_args[index++]);
    free(split_args);
}
