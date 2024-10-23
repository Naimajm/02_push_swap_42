/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:24:53 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/23 13:19:18 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	main(int argc, char **argv)
{
	// DECLARACION + INICIALIZACION LISTAS VINCULADAS 'STACKS' 
	t_stack	*stack_a; 	// ptr a nodo
	t_stack	*stack_b;
	int	stack_len_a;

	stack_a = NULL;
	stack_b = NULL;	
	// VALIDACION INPUT + CAPTURA ARGUMENTOS (1 ARG STRING O 2º ARGUMENTO SIN NUMERO)
	if (argc == 1 || (argc == 2 && argv[1][0] == 0)) // ./a.out ""
	{ 
		//printf("1 \n");
		return (1);
	}
	else if (argc == 2)  // INPUTS ARGUMENTOS POR STRING
	{
		argv = ft_split_1(argv[1], ' '); // DIVISION ARGUMENTO EN NUMEROS
		//argv = ft_split(argv[1], ' '); // DIVISION ARGUMENTO EN NUMEROS
		//printf("%s \n", argv[0]);
	}
	// CREACION STACK
	stack_init(&stack_a, argv + 1, argc == 2); 
	
	// VERIFICACION STACK A -> YA ORDENADO
	// ALGORTIMO ORDENACION -> ORDENAR PARA 2, 3 O RESTO ELEMENTOS (push_swap())
	stack_len_a = ft_stack_len(stack_a);
	if (stack_is_sorted(stack_a) == false)
	{
		if (stack_len_a == 2)
			sa(&stack_a, false);
		else if (stack_len_a == 3)
			tiny_sort_three(&stack_a);
		// else if (stack_len_a == 5)
			//tiny_sort_five(&stack_a, &stack_b); 
		else
			push_swap(&stack_a, &stack_b);		
	}	
	// LIBERAR MEMORIA STACK
	ft_free_stack(&stack_a);

	return (0);
} */

/* int	main(void)
{
	// DECLARACION + INICIALIZACION LISTAS VINCULADAS 'STACKS' 
	t_stack	*stack_a; 	// ptr a nodo
	t_stack	*stack_b;
	int	stack_len_a;

	stack_a = NULL;
	stack_b = NULL;	
	// VALIDACION INPUT + CAPTURA ARGUMENTOS (1 ARG STRING O 2º ARGUMENTO SIN NUMERO)
	if (argc == 1 || (argc == 2 && argv[1][0] == 0)) // ./a.out ""
	{ 
		//printf("1 \n");
		return (1);
	}
	else if (argc == 2)  // INPUTS ARGUMENTOS POR STRING
	{
		argv = ft_split_1(argv[1], ' '); // DIVISION ARGUMENTO EN NUMEROS
		//argv = ft_split(argv[1], ' '); // DIVISION ARGUMENTO EN NUMEROS
		//printf("%s \n", argv[0]);
	}
	// CREACION STACK
	stack_init(&stack_a, argv + 1, argc == 2); 
	//stack_init(&stack_a, argv + 1, argc); 
	//stack_init(&stack_a, argv + 1, false); 
	
	// VERIFICACION STACK A -> YA ORDENADO
	// ALGORTIMO ORDENACION -> ORDENAR PARA 2, 3 O RESTO ELEMENTOS (push_swap())
	stack_len_a = ft_stack_len(stack_a);
	if (stack_is_sorted(stack_a) == false)
	{
		if (stack_len_a == 2)
			sa(&stack_a, false);
		else if (stack_len_a == 3)
			tiny_sort_three(&stack_a);
		else
			push_swap(&stack_a, &stack_b);		
	}	
	// LIBERAR MEMORIA STACK
	ft_free_stack(&stack_a);

	return (0);
} */

/* int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	//stack_init(&stack_b, 0, 2 == argc); // DA SEGMENTATION FAULT ¡¡
	
	if (1 == argc || (2 == argc && !argv[1][0]))
	{
		//ft_print_error();
		return (1);
	}
	else if (2 == argc)
		argv = ft_split_1(argv[1], ' ');

	// IMPRIMIR ARGUMENTOS
	int index = 0;
	while (argv[index])
	{
		printf("arg %i -> %s \n" , index + 1, argv[index]);
		index++;
	}	
	

	stack_init(&stack_a, argv + 1, 2 == argc);
	

	t_stack *stack_copy_a;
	
	// CASO A -----------------------------------------------------------------------
	
	// IMPRESION STACK
	stack_copy_a = stack_a;
	while (stack_copy_a) 
	{
		printf( "main () stack a -> arg numero-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_copy_a->value, stack_copy_a->prev, stack_copy_a, stack_copy_a->next );
		stack_copy_a = stack_copy_a->next;
	}

	t_stack *stack_copy_b;
	stack_copy_b = stack_b;
	while (stack_copy_b) 
	{
		printf( "main () stack b -> arg numero-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_copy_b->value, stack_copy_b->prev, stack_copy_b, stack_copy_b->next );
		stack_copy_b = stack_copy_b->next;
	} */

	/* pb(&stack_b, &stack_a, false);
	pb(&stack_b, &stack_a, false);
	pb(&stack_b, &stack_a, false);
	pb(&stack_b, &stack_a, false);

	//rra(&stack_a, false);
	//pa(&stack_a, &stack_b, false);
	
	ra(&stack_a, false);

	stack_copy_a = stack_a;
	while (stack_copy_a)  // IMPRESION STACK
	{
		printf( "stack a-> arg numero-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_copy_a->value, stack_copy_a->prev, stack_copy_a, stack_copy_a->next );
		stack_copy_a = stack_copy_a->next;
	}
	t_stack *stack_copy_b = stack_b;
	while (stack_copy_b)  // IMPRESION STACK
	{
		printf( "stack b -> arg numero-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_copy_b->value, stack_copy_b->prev, stack_copy_b, stack_copy_b->next );
		stack_copy_b = stack_copy_b->next;
	} */
	
	
	/* // CASO B -> volcar 1 elemento en stack b y vaciarlo -----------------------------------------------------------------------

	stack_init(&stack_a, argv + 1, 2 == argc);
	
	pb(&stack_b, &stack_a, false);

	t_stack *stack_copy_b = stack_b;
	while (stack_copy_b)  // IMPRESION STACK
	{
		printf( "stack -> arg numero-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_copy_b->value, stack_copy_b->prev, stack_copy_b, stack_copy_b->next );
		stack_copy_b = stack_copy_b->next;
	}

	pa(&stack_a, &stack_b, false); */	


/* 	printf("stack_is_sorted-> %d \n", stack_is_sorted(stack_a));
	
	if (!stack_is_sorted(stack_a))
	{
		if (ft_stack_len(stack_a) == 2)
			sa(&stack_a, false);
		else if (ft_stack_len(stack_a) == 3)
			tiny_sort_three(&stack_a);
		else
			push_swap(&stack_a, &stack_b);
	}

	stack_copy_a = stack_a;
	while (stack_copy_a)  // IMPRESION STACK
	{
		printf( "stack -> arg numero-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_copy_a->value, stack_copy_a->prev, stack_copy_a, stack_copy_a->next );
		stack_copy_a = stack_copy_a->next;
	}

	ft_free_stack(&stack_a);
} */


/* int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (1);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');

	stack_init(&a, argv + 1, 2 == argc);

	//stack_init(&b, 0, 2 == argc);

	printf("main() stack_is_sorted-> %d \n", stack_is_sorted(a));

	printf("main() stack b -> %p \n", b);

	// IMPRESION STACK
	t_stack *stack_copy_a;
	stack_copy_a = a;
	while (stack_copy_a)  
	{
		printf( "main() stack -> arg numero-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_copy_a->value, stack_copy_a->prev, stack_copy_a, stack_copy_a->next );
		stack_copy_a = stack_copy_a->next;
	}
	
	if (!stack_is_sorted(a))
	{
		if (ft_stack_len(a) == 2)		
		{
			printf("main() sa() -> \n");
			sa(&a, false);
		}
		else if (ft_stack_len(a) == 3)
		{
			printf("main() tiny_sort_three() -> \n");
			tiny_sort_three(&a);
		}		
		else
		{
			printf("main()  push_swap() -> \n");
			push_swap(&a, &b);
		}
	}
	ft_free_stack(&a);
	ft_free_stack(&b);
} */

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	
	if (1 == argc || (2 == argc && !argv[1][0]))
	{	
		// ARGUMENTOS VACIOS
		//ft_print_error();
		return (0);
	}	
	else if (2 == argc)
		//argv = ft_split(argv[1], ' ');
		argv = ft_split_1(argv[1], ' ');

				
	stack_init(&a, argv + 1, 2 == argc);
	if (!stack_is_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			sa(&a, false);
		else if (ft_stack_len(a) == 3)
			tiny_sort_three(&a);
		else
			push_swap(&a, &b);
	}
	ft_free_stack(&a);
}