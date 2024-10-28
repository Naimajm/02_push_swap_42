/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:24:53 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/28 14:28:43 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	// DECLARACION + INICIALIZACION LISTAS VINCULADAS 'STACKS
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	
	// RECEPCION + PROCESAMIENTO ARGUMENTOS
	if (argc == 1 || (argc == 2 && argv[1][0] == 0)) // ./push_swap "" // ARGUMENTOS VACIOS
		return (0);
	else if (argc == 2)  // INPUTS ARGUMENTOS POR STRING
		argv = split(argv[1], ' '); // DIVISION ARGUMENTOS EN NUMEROS

	// IMPRIMIR ARGUMENTOS
	/* int index = 0;
	while (argv[index])
	{
		printf("main() -> arg %i -> %s \n" , index + 1, argv[index]);
		index++;
	}	 */

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

	// ALGORTIMO ORDENACION -> ORDENAR PARA 2, 3 O RESTO ELEMENTOS (push_swap())
	//printf("main() -> stack_is_sorted-> %d \n", stack_is_sorted(stack_a));
	
	if (!stack_is_sorted(stack_a))
	{
		if (ft_stack_len(stack_a) == 2)
		{
			//printf("main() sa() -> \n");
			sa(&stack_a, true);
		}
		else if (ft_stack_len(stack_a) == 3)
		{
			//printf("main() tiny_sort_three() -> \n");
			tiny_sort_three(&stack_a);
		}
		else
		{
			//printf("main()  push_swap() -> \n");
			push_swap(&stack_a, &stack_b);
		}
	}
	// IMPRESION STACK 'ORDENADO'
	/* stack_copy_a = stack_a;
	while (stack_copy_a) 
	{
		printf( "main() stack a -> arg numero-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_copy_a->value, stack_copy_a->prev, stack_copy_a, stack_copy_a->next );
		stack_copy_a = stack_copy_a->next;
	} */

	// LIBERAR MEMORIA STACK
	ft_free_stack(&stack_a);
	return (0);
}