#include "../includes/operations.h"

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