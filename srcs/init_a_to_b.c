

#include "../push_swap.h"

void	nodes_index(t_stack_node *stack)
{
	int	i; 
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->median = true;
		else
			stack->median = false; 
		stack = stack->next;
		i++;
	}
}

static void	target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b; 
	t_stack_node	*target_node; 
	long			best_match;

	while (a) 
	{
		best_match = LONG_MIN; 
		current_b = b; 
		while (current_b)
		{
			if (current_b->value < a->value 
				&& current_b->value > best_match) 
			{
				best_match = current_b->value; 
				target_node = current_b; 
			}
			current_b = current_b->next; 
		}
		if (best_match == LONG_MIN) 
			a->target_node = find_max(b); 
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost(t_stack_node *a, t_stack_node *b) 
{
	int	len_a; 
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index; 
		if (!(a->median)) 
			a->push_cost = len_a - (a->index); 
		if (a->target_node->median) 
			a->push_cost += a->target_node->index; 
		else 
			a->push_cost += len_b - (a->target_node->index); 
		a = a->next; 
	}
}

void	cheapest(t_stack_node *stack) 
{
	long			cheapest_value;
	t_stack_node	*cheapest_node; 

	if (!stack) 
		return ;
	cheapest_value = LONG_MAX; 
	while (stack) 
	{
		if (stack->push_cost < cheapest_value) 
		{
			cheapest_value = stack->push_cost; 
			cheapest_node = stack; 
		}
		stack = stack->next; 
	}
	cheapest_node->cheapest = true; 
}

void	init_a_to_b(t_stack_node *a, t_stack_node *b) 
{
	nodes_index(a);
	nodes_index(b);
	target_a(a, b);
	cost(a, b);
	cheapest(a);
}