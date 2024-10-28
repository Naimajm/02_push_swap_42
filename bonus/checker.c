/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:23:03 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/26 20:58:54 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	check_command(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (ft_strncmp(command, "pa\n", 3) == 0)
		pa(stack_a, stack_b, true);
	else if (ft_strncmp(command, "pb\n", 3) == 0)
		pb(stack_b, stack_a, true);
	else if (ft_strncmp(command, "ra\n", ft_strlen("ra\n")) == 0)
		ra(stack_a, true);		
	else if (ft_strncmp(command, "rb\n", ft_strlen("rb\n")) == 0)
		rb(stack_b, true);
	else if (ft_strncmp(command, "rr\n", ft_strlen("rr\n")) == 0)
		rr(stack_a, stack_b, true);
	else if (ft_strncmp(command, "rra\n", ft_strlen("rra\n")) == 0)
		rra(stack_a, true);
	else if (ft_strncmp(command, "rrb\n", ft_strlen("rrb\n")) == 0)
		rrb(stack_b, true);
	else if (ft_strncmp(command, "rrr\n", ft_strlen("rrr\n")) == 0)
		rrr(stack_a, stack_b, true);
	else if (ft_strncmp(command, "sa\n", ft_strlen("sa\n")) == 0)
		sa(stack_a, true);
	else if (ft_strncmp(command, "sb\n", ft_strlen("sb\n")) == 0)
		sb(stack_b, true);
	else
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}	
}

int	main(int argc, char **argv)
{
	// DECLARACION + INICIALIZACION LISTAS VINCULADAS 'STACKS
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*next_line;
	int		stack_len;

	stack_a = NULL;
	stack_b = NULL;

	// RECEPCION + PROCESAMIENTO ARGUMENTOS
	if (argc == 1)
		return (0);
	else if (argc == 2)
		argv = split(argv[1],' ');
	
	// CREACION STACK
	stack_init(&stack_a, argv + 1);

	// IMPRESION STACK 'INICIAL'
	/* t_stack *stack_copy_a;
	stack_copy_a = stack_a;
	while (stack_copy_a) 
	{
		printf( "main() stack a -> arg numero-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_copy_a->value, stack_copy_a->prev, stack_copy_a, stack_copy_a->next );
		stack_copy_a = stack_copy_a->next;
	} */
	stack_len = ft_stack_len(stack_a);
	
	next_line = get_next_line(STDIN_FILENO);

	while (next_line)
	{
		// LEER COMANDOS IMPRIMIDOS POR STDIN
		//printf("%i \n", ft_strncmp((const char *)(next_line), "pa\n", ft_strlen("pa\n")));
		//printf("next_line -> %s", next_line);
		check_command(&stack_a, &stack_b, next_line);
		next_line = get_next_line(STDIN_FILENO);
	}	
	// VALIDACION ORDENAMIENTO STACK + IGUAL NUM ELEMENTOS en estados inicial y final
	if ((stack_is_sorted(stack_a)) && (ft_stack_len(stack_a) == stack_len) && ft_stack_len(stack_a) > 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);	

	// LIBERAR MEMORIA STACK
	ft_free_stack(&stack_a);
	return (0);
}
