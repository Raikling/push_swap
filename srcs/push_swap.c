
#include "../push_swap.h"

int validate_args(int ac, char **av)
{
	int i;
	char *args;

	i = 0;
	while (i < ac)
	{
		args = av[i];
		while (args && is_space(*args))
			args++;
		if (*args == '\0')
		{
			write (2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}
void free_split_av(char **split_av)
{
	int i;

	i = 0;
	while (split_av[i])
	{
		free(split_av[i]);
		i++;
	}
	free(split_av);
}

char *fill_all_args(int ac, char **av)
{
    int i;
    char *all_args;
    char *tmp;

    all_args = ft_strdup(av[1]);
    i = 2;
    while (i < ac)
    {
        tmp = ft_strjoin(all_args, " ");
        free(all_args);
        all_args = ft_strjoin(tmp, av[i]);
        free(tmp);
        i++;
    }
    return all_args;
}
int process_args(int ac, char **av, t_stack_node **a)
{
	char *all_args;
	char **split_av;

	all_args = fill_all_args(ac, av);
	split_av = ft_split(all_args, ' ');
	if (init_stack_a(a, split_av) != 0)
	{
		free(all_args);
		return(1);
	}
	free_split_av(split_av);
	free(all_args);
	if (!*a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}



// void print_list(t_stack_node *head)
// {
//     t_stack_node *current = head;
//     while (current)
//     {
//         printf("%d ", current->value);
//         current = current->next;
//     }
//     ft_printf("\n");
// }
int main(int ac, char **av)
{
	t_stack_node *a, *b;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (validate_args(ac, av))
		return (1);
	if (process_args(ac, av, &a))
		return (1);
	if (stack_sorted(a))
		return (0);
	if (stack_len(a) == 2)
		sa(&a, true);
	else if (stack_len(a) == 3)
		sort_three(&a);
	else
		sort_stacks(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}






