
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h> 
# include <limits.h> 
# include "Libft/libft.h"
# include "ft_Printf/ft_printf.h"

typedef struct s_stack_node 
{
	int					value; 
	int					index; 
	int					push_cost; 
	bool				median; 
	bool				cheapest;
	struct s_stack_node	*target_node; 
	struct s_stack_node	*next; 
	struct s_stack_node	*prev; 
}	t_stack_node;

int				error_syntax(char *str_n); 
int				error_dups(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void				free_errors(t_stack_node **a, char **av);
int				init_stack_a(t_stack_node **a, char **argv);
void			init_a_to_b(t_stack_node *a, t_stack_node *b);
void			init_b_to_a(t_stack_node *a, t_stack_node *b);
void			nodes_index(t_stack_node *stack);
void			cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_push(t_stack_node **s, t_stack_node *n, char c);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack); 
t_stack_node	*find_max(t_stack_node *stack);
void			sort_min_on_top(t_stack_node **a); 
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
int				is_space(char c);
void free_split_av(char **split_av);

#endif