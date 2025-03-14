

#include "../push_swap.h"
#include <stdio.h>

void print_list(t_stack_node *head)
{
    t_stack_node *current = head;
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int	main(int ac, char **av) 
{
	t_stack_node	*a;
	t_stack_node	*b;
	int i;

	a = NULL;
	b = NULL;
	i = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]))
        return (1);
	else if (ac == 2)
    {
        av = ft_split(av[1], ' ');
        init_stack_a(&a, av);
        while (av[i])
        {
            free(av[i]);
            i++;
        }
        free(av);
    }
	else
		init_stack_a(&a, av + 1); 
	//print_list(a);
	if (!stack_sorted(a)) 
	{
		if (stack_len(a) == 2) 
			sa(&a, true);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	//print_list(a);
	free_stack(&a); 
	return (0);
}

