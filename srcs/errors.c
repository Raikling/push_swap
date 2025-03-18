
#include "../push_swap.h"

int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

int error_syntax(char *str)
{
    
    if (str == NULL || *str == '\0')  
        return (1);
    while (*str && is_space(*str))
        str++;
    if (*str == '\0')
        return (1);
    if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
        return (1);
    if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
        return (1);
    while (*++str)
    {
        if (!(*str >= '0' && *str <= '9') && !is_space(*str))
            return (1);
    }

    return (0);
}

int	error_dups(t_stack_node *a, int value) 
{
	if (!a) 
		return (0);
	while (a) 
	{
		if (a->value == value) 
			return (1);
		a = a->next; 
	}
	return (0);
}

void	free_stack(t_stack_node **stack) 
{
	t_stack_node	*tmp; 
	t_stack_node	*current;

	if (!stack) 
		return ;
	current = *stack;
	while (current) 
	{
		tmp = current->next; 
		current->value = 0; 
		free(current); 
		current = tmp; 
	}
	*stack = NULL;
}

void 	free_errors(t_stack_node **a, char **av) 
{
	free_stack(a);
	free_split_av(av);
	write (2, "Error\n", 6);
}
