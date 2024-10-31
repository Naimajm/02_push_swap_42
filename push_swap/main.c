/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:26:03 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/31 13:50:51 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	// DECLARACION + INICIALIZACION LISTAS VINCULADAS 'STACKS'
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	
	// RECEPCION + PROCESAMIENTO ARGUMENTOS
	if (argc == 1 || (argc == 2 && argv[1][0] == 0)) // ./push_swap "" // ARGUMENTOS VACIOS
		return (0);
	else if (argc == 2)  // INPUTS ARGUMENTOS POR STRING
		argv = split_push_swap(argv[1], ' '); // DIVISION ARGUMENTOS EN NUMEROS

	// IMPRIMIR ARGUMENTOS
	/* int index = 0;
	while (argv[index])
	{
		printf("main() -> arg %i -> %s \n" , index + 1, argv[index]);
		index++;
	}	 */

	// CREACION STACK + VALIDACION Y CONVERSION ARGUMENTOS	
	init_stack(&stack_a, argv + 1);
	
	// IMPRESION STACK 'INICIAL'
	/* t_stack *stack_copy_a;
	stack_copy_a = stack_a;
	while (stack_copy_a) 
	{
		printf( "main() stack a INICIAL-> arg numero-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_copy_a->value, stack_copy_a->prev, stack_copy_a, stack_copy_a->next );
		stack_copy_a = stack_copy_a->next;
	} */

	// ALGORTIMO ORDENACION -> push_swap()
	if (!is_stack_sorted(stack_a))
		push_swap(&stack_a, &stack_b); 

	// IMPRESION STACK 'ORDENADO'
	/* t_stack *stack_copy_a;
	stack_copy_a = stack_a;
	while (stack_copy_a) 
	{
		printf( "main() stack a FINAL -> arg numero-> %d, index-> %d, \t current_position-> %d \t target_node-> %p \t above_median-> %d \n", stack_copy_a->value, stack_copy_a->index, stack_copy_a->current_position, stack_copy_a->target_node, stack_copy_a->above_median);
		stack_copy_a = stack_copy_a->next;
	}
	t_stack *stack_copy_b;
	stack_copy_b = stack_b;
	while (stack_copy_b) 
	{
		printf( "main() stack a FINAL -> arg numero-> %d, index-> %d, \t current_position-> %d \t target_node-> %p \t above_median-> %d \n", stack_copy_b->value, stack_copy_b->index, stack_copy_b->current_position, stack_copy_b->target_node, stack_copy_b->above_median);
		stack_copy_b = stack_copy_b->next;
	}
 	*/
	// LIBERAR MEMORIA STACK
	free_stack(&stack_a);
	return (0);
}
