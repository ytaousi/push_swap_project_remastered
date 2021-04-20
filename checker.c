#include "operations.h"

int         main(int ac, char **av)
{
    char **tab;
    
    tab = ft_split("sa|sb|ss|pa|pb|ra|rb|rr|rra|rrb|rrr", '|');
    int i = 0;
    if (ac > 1)
    {
        i = 1;
        while (av[i] != NULL)
        {
            if (!ft_isint(av[i]))
            {
                ft_putendl_fd("Error", 1);
                return (0);
            }
            i++;
        }
        i = 1;
        t_stack *head;
        t_stack *tmp;
        t_stack *head2;
        t_stack *tmp3;
        t_operations *tmp2;
        t_operations *operation_in;
    
        head = (t_stack *)malloc(sizeof(t_stack));
        head->number = ft_atoi(av[1]);
        head->next = NULL;
        head2 = (t_stack *)malloc(sizeof(t_stack));
        head2->number = 1;
        head2->next = NULL;
        i++;
        while (av[i] != NULL)
        {
            ft_lstadd_back_number(&head, ft_new_number(ft_atoi(av[i])));
             ft_lstadd_back_number(&head2, ft_new_number(i));
            i++;
        }
        tmp = head;
        tmp3 = head2;
        while (tmp != NULL && tmp3 != NULL)
        {
            printf("[%d]--[%d]\n", tmp->number, tmp3->number);
            tmp = tmp->next;
            tmp3 = tmp3->next;
        }
        // get Operations as char* from stdin

        char *line;
        while (get_next_line(0, &line) > 0)
        {
            ft_lstadd_back_operation(&operation_in, ft_new_operation(line));
            free(line);
        }
        ft_lstadd_back_operation(&operation_in, ft_new_operation(line));
        free(line);
        printf("\n");
        tmp2 = operation_in;
        if (ft_operations_normed(&operation_in, tab) == 0)
            return (0);
        while (tmp2 != NULL)
        {
            printf("[%s]--[%d]\n", tmp2->operation, tmp2->index);
            tmp2 = tmp2->next;
        }
        ft_apply_operations(operation_in, &head, &head2);
        if (ft_stack_is_sorted(head) == 1)
            printf("OK");
        else
            printf("KO");
    }
    else
        write(1, "\n", 1);
    return (0);
}
