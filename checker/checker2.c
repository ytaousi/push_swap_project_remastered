#include "../includes/operations.h"

int        ft_check_numbers(char **av)
{
    int i;

    i = 1;
    while(av[i] != NULL)
    {
        if (!ft_isint(av[i]) || ft_isduplicate(av, av[i]))
        {
            ft_putendl_fd("Error", 1);
            return (0);
        }
        i++;
    }
    return (1);
}

void        ft_print_stack(t_stack *stack)
{
    while (stack)
    {
        ft_putnbr_fd(stack->number, 1);
        write(1, "\n", 1);
        stack = stack->next;
    }
}

int         main(int ac, char **av)
{
    t_stack *astack;
    t_stack *bstack;

    astack = NULL;
    bstack = NULL;
    if (ac > 1)
    {
        if (!ft_check_numbers(av))
            return (0);
        astack = ft_new_stack(av);
        bstack = ft_new_stack(av);
        if (!ft_operations_normed(&astack, &bstack))
             return (0);
        if (ft_stack_is_sorted(astack))
            printf("OK\n");
        else
            printf("KO\n");
    }
    ft_free_stack(&astack);
    ft_free_stack(&bstack);
    return (0);
}