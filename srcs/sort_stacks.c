

#include "../push_swap.h"

static void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node) 
		rr(a, b, true); 
	nodes_index(*a);
	nodes_index(*b);
}

static void	rev_rotate_both(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node) 
		rrr(a, b, true); 
	nodes_index(*a); 
	nodes_index(*b);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b) 
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a); 
	if (cheapest_node->median && cheapest_node->target_node->median) 
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->median) && !(cheapest_node->target_node->median)) 
		rev_rotate_both(a, b, cheapest_node);
	prep_push(a, cheapest_node, 'a');
	prep_push(b, cheapest_node->target_node, 'b');
	pb(b, a, true);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_push(a, (*b)->target_node, 'a');
	pa(a, b, true); 
}


void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, true);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, true);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_a_to_b(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b) 
	{
		init_b_to_a(*a, *b);
		move_b_to_a(a, b); 
	}
	nodes_index(*a);
	sort_min_on_top(a);
}