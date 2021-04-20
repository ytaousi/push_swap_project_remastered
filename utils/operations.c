#include "../includes/operations.h"

int    ft_sa(t_stack **astack, t_stack **bstack)
{
    t_stack *tmp;

    if (bstack)
    {
        ;
    }
    if (ft_get_len_env(*astack) < 2)
        return (0);
    else
    {
        tmp = (*astack)->next;
        (*astack)->next = tmp->next;
        tmp->next = *astack;
        *astack = tmp;
        return (1);
    }
}

int    ft_sb(t_stack **bstack, t_stack **astack)
{
    t_stack *tmp;

    if (astack)
    {
        ;
    }
    if (ft_get_len_env(*bstack) < 2)
        return (0);
    else
    {
        tmp = (*bstack)->next;
        (*bstack)->next = tmp->next;
        tmp->next = *bstack;
        *bstack = tmp;
        return (1);
    }
}

int        ft_ss(t_stack **astack, t_stack **bstack)
{
    ft_sa(astack, bstack);
    ft_sb(bstack, astack);
    return (1);
}

int         ft_pa(t_stack **astack, t_stack **bstack)
{
    if (ft_get_len_env(*bstack) == 0)
        return (0);
    else
    {
        if (astack || bstack)
        {
            ;
        }
        return (1);
    }
}

int         ft_pb(t_stack **bstack, t_stack **astack)
{
    if (ft_get_len_env(*astack) == 0)
        return (0);
    else
    {
        if (astack || bstack)
        {
            ;
        }
        return (1);
    }
}

int        ft_ra(t_stack **astack, t_stack **bstack)
{
    t_stack *tmp;
    t_stack *tmp2;
    int     rotatea;

    if (bstack)
    {
        ;
    }
    if(ft_get_len_env(*astack) < 2)
        return (0);
    else
    {
        rotatea = (*astack)->number;
        tmp = *astack;
        tmp2 = *astack;
        tmp = tmp->next;
        while (tmp != NULL)
        {
            tmp2->number = tmp->number;
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }
        tmp2->number = rotatea;
        return (1);
    }
}

int        ft_rb(t_stack **bstack, t_stack **astack)
{
    t_stack *tmp;
    t_stack *tmp2;
    int     rotateb;

    if (astack)
    {
        ;
    }
    if(ft_get_len_env(*bstack) < 2)
        return (0);
    else
    {
        rotateb = (*bstack)->number;
        tmp = *bstack;
        tmp2 = *bstack;
        tmp = tmp->next;
        while (tmp != NULL)
        {
            tmp2->number = tmp->number;
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }
        tmp2->number = rotateb;
        return (1);
    }
}

int        ft_rr(t_stack **astack, t_stack **bstack)
{
    ft_ra(astack, bstack);
    ft_rb(bstack, astack);
    return (1);
}

int         ft_rra(t_stack **astack, t_stack **bstack)
{
    t_stack *tmp;
    t_stack *tmp2;
    int     i;

    if (bstack)
    {
        ;
    }
    i = 0;
    if(ft_get_len_env(*astack) < 2)
        return (0);
    else
    {
        tmp = *astack;
        tmp2 = *astack;
        while (tmp2->next != NULL)
            tmp2 = tmp2->next;
        while (i < ft_get_len_env(*astack) - 2)
        {
            tmp = tmp->next;
            i++;
        }
        tmp->next = NULL;
        tmp2->next = *astack;
        *astack = tmp2;
        return (1);
    }
}

int         ft_rrb(t_stack **bstack, t_stack **astack)
{
    t_stack *tmp;
    t_stack *tmp2;
    int     i;

    if (astack)
    {
        ;
    }
    i = 0;
    if(ft_get_len_env(*bstack) < 2)
        return (0);
    else
    {
        tmp = *bstack;
        tmp2 = *bstack;
        while (tmp2->next != NULL)
            tmp2 = tmp2->next;
        while (i < ft_get_len_env(*bstack) - 2)
        {
            tmp = tmp->next;
            i++;
        }
        tmp->next = NULL;
        tmp2->next = *bstack;
        *bstack = tmp2;
        return (1);
    }
}

int        ft_rrr(t_stack **astack, t_stack **bstack)
{
    ft_rra(astack, bstack);
    ft_rrb(bstack, astack);
    return (1);
}

int         ft_stack_is_sorted(t_stack *head)
{
    t_stack *tmp;

    tmp = head;
    if (ft_get_len_env(head) < 2)
        return (1);
    while (head->next != NULL)
    {
        head = head->next;
        if(tmp->number > head->number)
            return (0);
        tmp = tmp->next;
    }

    return (1);
}

int        ft_operations_normed(t_operations **operation_in , char **tab)
{
    int found;
    int i;

    while (*operation_in)
    {
        found = 0;
        i = 0;
        while (tab[i])
        {
            if (ft_is_equal_str((*operation_in)->operation, tab[i]))
            {   
                (*operation_in)->index = i;
                found = 1;
                break;
            }
            else
                i++;
        }
        if (found == 0)
        {
            ft_putendl_fd("Error", 1);
            return (0);
        }
        else
            (*operation_in) = (*operation_in)->next;
    }
    return (1);
}

void        ft_apply_operations(t_operations *operation_in, t_stack **astack, t_stack **bstack)
{
    int        (*g_builtins_operations[11])(t_stack **, t_stack **);

    g_builtins_operations[0] = &ft_sa;
    g_builtins_operations[1] = &ft_sb;
    g_builtins_operations[2] = &ft_ss;
    g_builtins_operations[3] = &ft_pa;
    g_builtins_operations[4] = &ft_pb;
    g_builtins_operations[5] = &ft_ra;
    g_builtins_operations[6] = &ft_rb;
    g_builtins_operations[7] = &ft_rr;
    g_builtins_operations[8] = &ft_rra;
    g_builtins_operations[9] = &ft_rrb;
    g_builtins_operations[10] = &ft_rrr;

    while (operation_in)
    {
        g_builtins_operations[operation_in->index](astack, bstack);
        operation_in = operation_in->next;
    }
}