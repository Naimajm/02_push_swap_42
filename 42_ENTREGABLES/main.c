/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:26:03 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/16 12:02:07 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2 && argv[1][0] == 0)
	{
		return (0);
	}
	else if (argc == 2)
		argv = split_push_swap(argv[1], ' ');
	init_stack(&stack_a, argv + 1);
	if (!is_stack_sorted(stack_a))
		push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
