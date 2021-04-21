# include "../includes/operations.h"

int ft_isduplicate(char **av, char *number)
{
    int i;
    int found;

    i = 1;
    found = 0;
    while (av[i] != NULL)
    {
        if (ft_is_equal_str(av[i], number))
        {
            found++;
        }
        i++;
    }
    if (found == 2)
        return (1);
    else
        return (0);
}

int main(int ac, char **av)
{   
    // List of operations :
    //char *tab[] = {"pa", "pa", "sa", "sb", "ss", "ra", "rb", "rr", "rra", "rrb", NULL};
    int i;
    int elements;
    t_stack *astack = NULL;
    //t_stack *bstack = NULL;
    t_stack *printa;
    char *line;
    t_operations *operation_in;
    //t_operations *print_operations;

    i = 1;
    elements = 0;
    if (ac > 1)
    {
        while(av[i] != NULL)
        {
            if (!ft_isint(av[i]) || ft_isduplicate(av, av[i]))
            {
                ft_putendl_fd("Error", 1);
                return (0);
            }
            else
                elements++;
            i++;
        }
        i = 1;
        astack = ft_new_stack(elements, av);
        //bstack = ft_new_stack(0, av);
        printa = astack;
        
        while (printa)
        {
            printf("[%d] | \n", printa->number);
            printa = printa->next;
        }
        printf("---\n");
        while (get_next_line(0, &line) > 0)
        {
            ft_lstadd_back_operation(&operation_in, ft_new_operation(line));
            free(line);
        }
        ft_lstadd_back_operation(&operation_in, ft_new_operation(line));
        free(line);
        printf("\n---\n");
        //print_operations = operation_in;
        while (operation_in)
        {
            printf("operation[%d] : [%s]\n", operation_in->index, operation_in->operation);
            operation_in = operation_in->next;
        }
    }
    else
        write(1, "\n", 1);
    return (0);
}