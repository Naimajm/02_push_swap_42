/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:15:28 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/23 11:43:16 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_duplicate_numbers(t_stack *stack_a, int number);
static int	ft_error_syntax(char *str_numbers);
static long int	ft_atol(const char *str);
//static long long	ft_atol(const char *str);

/* void	stack_init(t_stack **stack, char **argv, bool flag_argc_2)
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
			ft_print_error();
			ft_free_all(stack, argv, flag_argc_2);
		}		

		// CONVERSION ARGUMENTO STR A NUMERO
		number = ft_atol(argv[index]);

		//printf("stack_init() -> number atol()-> %li \n", number);

		if ( number < LONG_MIN || number > LONG_MAX )
		{
			ft_print_error();
			ft_free_all(stack, argv, flag_argc_2);
		}

		// VALIDACION NUMEROS ENTEROS MAXIMOS Y MINIMOS -> NUMEROS NO VALIDOS
		if ( number < INT_MIN || number > INT_MAX )
		{
			ft_print_error();
			ft_free_all(stack, argv, flag_argc_2);
		}
		// VALIDACION NUMBER CON NUMEROS EN LOS NODOS YA CREADOS
		if (ft_check_duplicate_numbers(*stack, (int)number))
		{
			ft_print_error();
			ft_free_all(stack, argv, flag_argc_2);
		}

		// AÑADIR VALOR EN NUEVO NODO
		ft_append_node(stack, (int)number);		
		index++;
	}
	if (flag_argc_2)
		ft_free_matrix(argv);	
} */

void	stack_init(t_stack **stack, char **argv, bool flag_argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	// ?????
	/* if (argv[i] == 0)
	{
		ft_print_error();
		return ;

	} */

	while (argv[i])
	{
		if (ft_error_syntax(argv[i]))
		{
			ft_print_error();
			ft_free_all(stack, argv, flag_argc_2);
		}
		nbr = ft_atol(argv[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
		{
			ft_print_error();
			ft_free_all(stack, argv, flag_argc_2);
		}
		if (ft_check_duplicate_numbers(*stack, (int)nbr))
		{
			ft_print_error();
			ft_free_all(stack, argv, flag_argc_2);
		}
		ft_append_node(stack, (int)nbr);
		++i;
	}
	if (flag_argc_2)
		ft_free_matrix(argv);
}

bool	stack_is_sorted(t_stack *stack)
{
	// VALIDACION INICIAL
	if (stack == NULL)
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
* @param str: puntero a estructura lista vinculada.
* @param int: numero entero a comparar con valores de los nodos.
* @returns 0 -> no duplicidad numero ; valor 1 -> duplicidad numero.
*/
static int	ft_check_duplicate_numbers(t_stack *stack, int number)
{
	// VALIDACION INICIAL ARGUMENTOS
	if (stack == NULL)
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
* @param str: puntero al string con valores numericos o de signo -,+.
* @returns 0 -> no errores sintacticos ; valor 1 -> error.
*/
static int	ft_error_syntax(char *str_numbers)
{
	int index;

	index = 0;
	if (str_numbers == NULL)
		return (1);
	// VALIDACION 1º CHAR-> char fuera de signo (+ -) y serie numerica (0-9) 
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
* @brief Convierte una representación de cadena de un número 'LONG'
en su valor entero correspondiente.
* @param str: puntero a la cadena que se va a converti.
* @returns long -> valor long obtenido de la cadena de entrada
o valor 0 como error.
*/
static long int	ft_atol(const char *str)
//static long long	ft_atol(const char *str)
{
	int		index;
	long	result;
	int	sign_count;
	int	sign;
	
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
	while (str[index] >= '0' && str[index] <= '9' && sign_count <= 1)
	{
		result = (result * 10) + (str[index] - '0');
		index++;
	}
	return (sign * result);
}

/* static long	ft_atol(const char *str)
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
} */

/* static long int	ft_atol(const char *str)
{
	int			i;
	long int	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		res = (res * 10) + str[i] - 48;
		i++;
	}
	return (res * sign);
} */

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