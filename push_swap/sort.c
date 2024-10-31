/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:28:06 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/31 12:37:00 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_nodes_to_stack_b(t_stack **stack_a, t_stack **stack_b);
static void ft_get_index(t_stack *stack);

void	sort_three(t_stack **stack)
{
    t_stack *highest_node; 

    highest_node = find_highest_node(*stack);
	// COLOCAR ABAJO EL VALOR MAS ALTO
	if (*stack == highest_node)  // 1º nodo numero + alto
		ra(stack, true);
	else if ((*stack)->next == highest_node) // 2º nodo numero + alto
		rra(stack, true);		
	// ORDENAR 2 ELEMENTOS (una vez el valor mayor se coloca abajo)
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, true);    
}

void	sort_small_stack(t_stack **stack_a, t_stack **stack_b)
{
	while (get_stack_len(*stack_a) > 3)
		pb(stack_b, stack_a, true);	// push to stack b			
	if (!is_stack_sorted(*stack_b)) 
		sb(stack_b, true);	// ordenar stack b 2 elementos
}

// CASO > 5 NODOS -> algoritmo ppal ordenacion ---------------
void	sort_big_stack(t_stack **stack_a, t_stack **stack_b)
{
	ft_get_index(*stack_a); // INDEXAR CADA NODO
	
	// MOVIMIENTO ORDENADO DESDE STACK A HASTA STACK B -----------------------
	move_nodes_to_stack_b(stack_a, stack_b); 

	// ORDENAR STACK CON 3 NODOS
	//tiny_sort_three(stack_a); 

	// MOVIMIENTO ORDENADO DESDE STACK B HASTA STACK A -----------------------
	/* while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		//move_cost(stack_a, stack_b);
		//set_cheapest_node(stack_a, stack_b);
	} */
	/*if (!stack_is_sorted(*stack_a))
		sorting_stack(stack_a); */
	//printf("sorting() -> fin sort to stack b \n");
}

// MOVIMIENTO ORDENADO DESDE STACK A HASTA STACK B
static void	move_nodes_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	pushed_number; // contabiliza las veces que mandamos números de stack_a a stack_b.
	int	stack_len;
	int	index;  //  iterar por los números de los stacks.

	stack_len = get_stack_len(*stack_a);
	pushed_number = 0;
	index = 0;
	//printf("stack_len/2-> %i \n", stack_len / 2);
	// stack >= 6 nodos + empujar la mitad de elementos con index superior a la mitad
	while (index < stack_len && (stack_len - pushed_number) >= 3 )
	{
		//printf("index node-> %i, \n", (*stack_a)->index);
		// PUSH TO STACK B CON INDICE < MITAD
		if ((*stack_a)->index <= (stack_len / 2 + 1))
		{
			pb(stack_b, stack_a, true);
			pushed_number++;
		} 
		else
			ra(stack_a, true);
		index++;
	}
	// ciclo para stack < 6 elementos
	while ( (stack_len - pushed_number) > 3) // mantener 3 nodos en stack a
	{
		//printf("index node-> %i, \n", (*stack_a)->index);
		pb(stack_b, stack_a, true);
		pushed_number++;		
	}
}

/* Asignar un 'index' a los nodos de la lista enlazada dependiendo del 'value'
que tengan. La función recibe un puntero al stack_a y un entero que será el 
tamaño máximo de stack_a.  'value' irá almacenando el valor más grande que 
vayamos encontrando durante cada iteración de la lista. */
static void ft_get_index(t_stack *stack)
{
	t_stack	*current_node_a; // nodo actual stack a
	t_stack	*bigger_node;
	int	highest_number;
	int	current_index;

	if (stack == NULL) //VALIDACION INICIAL ARGUMENTOS
		return ;
	current_index = get_stack_len(stack);

	while (current_index)
	{
		// INICIALIZACION VARIABLES PARA EL SIGUIENTE CICLO
		current_node_a = stack;
		bigger_node = NULL;
		highest_number = INT_MIN;
		
		// BUSQUEDA NODO DE VALOR MAYOR PARA INDENTAR
		while (current_node_a)
		{
			// ESTABLECER NUMERO MAYOR NO ETIQUETQADO -> SI indice del nodo todavia no se ha establecido
			if (current_node_a->value >= highest_number && current_node_a->index == 0)
			{
				highest_number = current_node_a->value; // cambio a valor actual
				bigger_node = current_node_a; // capturamos nodo mayor temporal		
				//printf("ft_get_index() nodo actual -> value-> %i, current_index-> %i \n", highest_number, current_index);		
			}
			current_node_a = current_node_a->next;			
		}		
		// REGISTRO INDICE EN NODO STACK mayor valor
		if (bigger_node)
			bigger_node->index = current_index;
		current_index--; // reduce indice para la siguiente indentacion
		//printf("ft_get_index() nodo mayor -> value-> %i, index-> %i \n", bigger_node->value, bigger_node->index);
	}		
}

/* int	main(void)
{
	t_stack	*stack;

	// INICIALIZACION STACK
	char	*arg_num_stack[4] = { arg_num_stack[0] = "0", arg_num_stack[1] = "4", arg_num_stack[2] = "2", arg_num_stack[3] = "1" };
	stack_init(&stack, arg_num_stack + 1, false);
	printf("stack_init() -> puntero (*stack_a) a 1º NODO-> %p \n", stack);

	// PROCESO TRANSFORMACION
	printf("\nPROCESO TRANSFORMACION --------\n");
	tiny_sort_three(&stack);
	printf("------------ \n");

	// ESTADO FINAL STACKS
	printf("ESTADO FINAL STACKS \n");
	while (stack)
	{
		printf( "stack -> numero-> %d, \t ptr previous-> %p \t address-> %p \t ptr next-> %p \n", stack->value, stack->prev, stack, stack->next );
		stack = stack->next;
	}
	printf("stack_init() -> puntero (*stack_a) a 1º NODO-> %p \n", stack);
	return (0);
} */

/* int	main(void)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;

	char    *arg_num_stack_a[8] = { arg_num_stack_a[0] = "23", arg_num_stack_a[1] = "6", arg_num_stack_a[2] = "-42", arg_num_stack_a[3] = "4", arg_num_stack_a[4] = "14", arg_num_stack_a[5] = "45", arg_num_stack_a[6] = "145" };

	stack_init(&stack_a, arg_num_stack_a);

	// IMPRESION STACK 'INICIAL'
	t_stack *stack_copy_a;
	stack_copy_a = stack_a;
	while (stack_copy_a) 
	{
		printf( "main() stack a INICIAL -> arg numero-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_copy_a->value, stack_copy_a->prev, stack_copy_a, stack_copy_a->next );
		stack_copy_a = stack_copy_a->next;
	}
	ft_get_index(stack_a, ft_stack_len(stack_a));
	nb_partition(&stack_a, &stack_b);

	// IMPRESION STACK 'FINAL'
	//stack_copy_a = stack_a;
	while (stack_a) 
	{
		printf( "main() stack a -> arg numero-> %d, index-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_a->value, stack_a->index, stack_a->prev, stack_a, stack_a->next );
		stack_a = stack_a->next;
	}
	//t_stack *stack_copy_b = stack_b;
	while (stack_b) 
	{
		printf( "main() stack b -> arg numero-> %d, index-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_b->value, stack_b->index, stack_b->prev, stack_b, stack_b->next );
		stack_b = stack_b->next;
	}
	return (0);
} */
