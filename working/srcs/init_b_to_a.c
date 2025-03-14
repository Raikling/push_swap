

#include "../push_swap.h"

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match;

	while (b)
	{
		best_match = LONG_MAX; 
		current_a = a;
		while (current_a) 
		{
			if (current_a->value > b->value 
				&& current_a->value < best_match) 
			{
				best_match = current_a->value; 
				target_node = current_a; 
			}
			current_a = current_a->next; 
		}
		if (best_match == LONG_MAX) 
			b->target_node = find_min(a); 
		else
			b->target_node = target_node;
		b = b->next; 
	}
}

void	init_b_to_a(t_stack_node *a, t_stack_node *b)
{
	nodes_index(a);
	nodes_index(b);
	set_target_b(a, b);
}
