/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:15:28 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/28 20:49:48 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_duplicate_numbers(t_stack *stack_a, int number);
static int	ft_error_syntax(char *str_numbers);
static long	ft_atol(const char *str);

void	stack_init(t_stack **stack, char **argv)
{
	long number; 
	int	index;

	index = 0;

	// para cada argumento string -> validar, convertir a numero y añadir a nodo
	while (argv[index])
	{	
		// VALIDACION ERRORES SINTACTICOS -> ARG STRING VALIDOS
		if (ft_error_syntax(argv[index]))
		{
			ft_putstr_fd("Error\n", 2);
			ft_free_stack(stack);
			exit(1);
		}
		// CONVERSION ARGUMENTO STR A NUMERO
		number = ft_atol(argv[index]);
		//printf("stack_init() -> number atol()-> %li \n", number);

		// VALIDACION NUMEROS ENTEROS MAXIMOS Y MINIMOS -> NUMEROS NO VALIDOS
		if ( number < INT_MIN || number > INT_MAX )
		{
			ft_putstr_fd("Error\n", 2);
			ft_free_stack(stack);
			exit(1);
		}
		// VALIDACION NUMBER CON NUMEROS EN LOS NODOS YA CREADOS
		if (ft_check_duplicate_numbers(*stack, (int)number))
		{
			ft_putstr_fd("Error\n", 2);
			ft_free_stack(stack);
			exit(1);
		}
		// AÑADIR VALOR EN NUEVO NODO
		ft_append_node(stack, (int)number);		
		index++;
	}
}

bool	stack_is_sorted(t_stack *stack)
{	
	if (stack == NULL) // VALIDACION INICIAL
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

/** 
* @brief Checkea string por error de repeticion de numeros en el stack.
* @param stack t_stack *: puntero a estructura lista vinculada.
* @param number int: numero entero a comparar con valores de los nodos.
* @returns int -> 0 -> no duplicidad numero ; valor 1 -> duplicidad numero.
*/
static int	ft_check_duplicate_numbers(t_stack *stack, int number)
{	
	if (stack == NULL) // VALIDACION INICIAL ARGUMENTOS
		return (0);
	// CICLO VALORES EN NODOS Y COMPARACION CON NUMBER
	while (stack)
	{
		if (stack->value == number)
			return (1);
		stack = stack->next;
	}
	return (0);	
}

/** 
* @brief Checkea string por error sintaticos para la conversion de 
numeros validos.
* @param str_numbers char *: puntero al string con valores numericos o de signo -,+.
* @returns int -> 0 -> no errores sintacticos ; valor 1 -> error.
*/
static int	ft_error_syntax(char *str_numbers)
{
	int index;

	index = 0;
	if (str_numbers == NULL)
		return (1);
	// VALIDACION 1º CHAR-> char fuera de signo (+ -) o serie numerica (0-9) 
	if(!(str_numbers[index] == '+' || str_numbers[index] == '-' 
		|| ft_isdigit(str_numbers[index])))
		return (1);

	//VALIDACION 1º CHAR COMO SIGNO y siguiente caracter NO ES NUMERO
	if ((str_numbers[index] == '+' || str_numbers[index] == '-') && !(ft_isdigit(str_numbers[index + 1])))
		return (1);
		
	// validacion valor numerico a partir del 2º character
	index++;
	while (str_numbers[index])
	{		
		if (!ft_isdigit(str_numbers[index]))
			return (1);
		index++;		
	}
	return (0);	
}

/** 
* @brief Convierte una representación de cadena 'str' de un número 'LONG'
en su valor entero correspondiente.
* @param str const char *: puntero a la cadena que se va a converti.
* @returns long -> valor long obtenido de la cadena de entrada
o valor 0 como error.
*/
static long ft_atol(const char *str)
{
	int		index;
	long	result;
	int		sign_count;
	int		sign;
	
	index = 0;
	result = 0;
	sign_count = 0;
	sign = 1;	
	while ((str[index] == ' ' || (str[index] >= '\t' && str[index] <= '\r')))
		index++;
	while ((str[index] == '+' || str[index] == '-'))
	{
		sign_count += 1;
		if (str[index] == '-' && sign_count <= 1)
			sign = -1;
		index++;
	}
	while ( ft_isdigit(str[index]) && sign_count <= 1 )
	{
		result = (result * 10) + (str[index] - '0');
		index++;
	}
	return ((long) sign * result);
}

/* int main(void)
{
	// TESTEO FUNCIONES AUXILIARES
	printf("TESTEO ft_atol()-> str '%s', return %ld \n\n", " -945asd", ft_atol(" -945asd"));

	printf("TESTEO ft_isdigit()-> int '%s', return %i \n\n", "9", ft_isdigit('9'));

	printf("TESTEO ft_error_syntax()-> int '%s', return %d \n\n", " -a945", ft_error_syntax(" -a945"));

	printf("TESTEO ft_error_syntax()-> int '%s', return %d \n\n", "945", ft_error_syntax("945"));

	printf("TESTEO ft_error_syntax()-> int '%s', return %d \n\n", "-945", ft_error_syntax("-945"));

	// TESTEO INICIALIZAR STACK
	t_stack *stack_a;
	//stack_a = NULL;	

	// listado ptr string -> simulacion inputs string en 'argv' // argv[0] no cuenta
	char	*arg_num[6] = { arg_num[0]= "arg archivo", arg_num[1] = "42", arg_num[2] = "1337", arg_num[3] = "-21", arg_num[4] = "21" };  // 21
	stack_init(&stack_a, arg_num + 1, false);   // (arg_num + 1) apuntaria a 2º argumento
	printf("TESTEO INICIALIZAR STACK stack_init()-> ptr '%p' \n\n", stack_a);

	printf("TESTEO ft_check_duplicate_numbers()-> int, return %d \n\n", ft_check_duplicate_numbers(stack_a, 42)); 
	
	while (stack_a)
	{
		printf( "arg numero-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_a->value, stack_a->prev, stack_a, stack_a->next );
		stack_a = stack_a->next;
	}
	ft_free_stack(&stack_a);
	return (0);
} */