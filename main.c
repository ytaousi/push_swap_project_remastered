# include "./includes/operations.h"

int main()
{
    t_stack *astack;

    astack = NULL;

    ft_push(&astack, 3);
    ft_push(&astack, 5);
    ft_push(&astack, 4);
    ft_print_stack(astack);
    write(1, "-\n", 2);
    ft_pop(&astack);
    ft_print_stack(astack);
    write(1, "-\n", 2);
    return (0);
}