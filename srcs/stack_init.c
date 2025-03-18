
#include "../push_swap.h"

static long	ft_atol(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1; 
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return (res * sign);
}

static void	append_node(t_stack_node **stack, int value) 
{
	t_stack_node	*node; 
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node)); 
	if (!node)
		return ;
	node->next = NULL; 
	node->value = value;
	node->cheapest = 0; 
	if (!(*stack))
	{
		*stack = node; 
		node->prev = NULL;
	}
	else 
	{
		last_node = find_last(*stack);
		last_node->next = node; 
		node->prev = last_node;
	}
}

int init_stack_a(t_stack_node **a, char **av)
{
	long	value;
	int i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
		{
			free_errors(a, av);
			return (1);
		}
		value = ft_atol(av[i]);
		if (value > INT_MAX || value < INT_MIN)
		{
			free_errors(a, av);
			return (1);
		}
		if (error_dups(*a, (int)value))
		{
			free_errors(a, av);
			return (1);
		}
		append_node(a, (int)value);
		i++;
	}
	return (0);
}

t_stack_node	*get_cheapest(t_stack_node *stack) 
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_push(t_stack_node **stack ,t_stack_node *top_node, char stack_name) 
{
	while (*stack != top_node) 
	{
		if (stack_name == 'a') 
		{
			if (top_node->median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b') 
		{
			if (top_node->median)
				rb(stack, true);
			else
				rrb(stack, true);
		}	
	}
}
