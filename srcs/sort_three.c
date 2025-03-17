
#include "../push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, true);
	else if ((*a)->next == biggest_node)
		rra(a, true);
	if ((*a)->value > (*a)->next->value)
		sa(a, true);
}


void	sort_min_on_top(t_stack_node **a) 
{
	while ((*a)->value != find_min(*a)->value) 
	{
		if (find_min(*a)->median) 
			ra(a, true);
		else
			rra(a, true);
	}
}