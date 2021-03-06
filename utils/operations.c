#include "../includes/operations.h"

void    ft_sa(t_stack **astack)
{
    int tmp;
    int tmp2;
    
    if (ft_get_len_stack(*astack) > 1)
    {
        tmp = ft_pop(astack);
        tmp2 = ft_pop(astack);
        ft_push(astack, tmp);
        ft_push(astack, tmp2);
    }
}

void    ft_sb(t_stack **bstack)
{
    int tmp;
    int tmp2;
    
    if (ft_get_len_stack(*bstack) > 1)
    {
        tmp = ft_pop(bstack);
        tmp2 = ft_pop(bstack);
        ft_push(bstack, tmp);
        ft_push(bstack, tmp2);
    }
}

void        ft_ss(t_stack **astack, t_stack **bstack)
{
    ft_sa(astack);
    ft_sb(bstack);
}

void         ft_pa(t_stack **astack, t_stack **bstack)
{
     int tmp;

    if (*bstack)
    {
        tmp = ft_pop(bstack);
        ft_push(astack, tmp);
    }
}

void         ft_pb(t_stack **bstack, t_stack **astack)
{
    int tmp;

    if (*astack)
    {
        tmp = ft_pop(astack);
        ft_push(bstack, tmp);
    }
}

void        ft_ra(t_stack **astack)
{
    t_stack *tmp;
    t_stack *tmp2;
    
    if (ft_get_len_stack(*astack) > 1)
    {
        tmp = *astack;
        while (tmp->next)
        {
            tmp2 = tmp;
            tmp = tmp->next;
        }
        tmp2->next = NULL;
        ft_push(astack, tmp->number);
        free(tmp);
    }
}

void        ft_rb(t_stack **bstack)
{
    t_stack *tmp;
    t_stack *tmp2;
    
    if (ft_get_len_stack(*bstack) > 1)
    {
        tmp = *bstack;
        while (tmp->next)
        {
            tmp2 = tmp;
            tmp = tmp->next;
        }
        tmp2->next = NULL;
        ft_push(bstack, tmp->number);
        free(tmp);
    }
}

void        ft_rr(t_stack **astack, t_stack **bstack)
{
    ft_ra(astack);
    ft_rb(bstack);
}

void         ft_rra(t_stack **astack)
{
    t_stack *tmp;
    t_stack *tmp2;

    tmp = malloc(sizeof(t_stack));
    tmp->number = ft_pop(astack);
    tmp->next = NULL;

    tmp2 = *astack;
    while (tmp2)
    {
        if (!tmp2->next)
        {
            tmp2->next = tmp;
            break ;
        }
        tmp2 = tmp2->next;
    }
}

void         ft_rrb(t_stack **bstack)
{
    t_stack *tmp;
    t_stack *tmp2;

    tmp = malloc(sizeof(t_stack));
    tmp->number = ft_pop(bstack);
    tmp->next = NULL;

    tmp2 = *bstack;
    while (tmp2)
    {
        if (!tmp2->next)
        {
            tmp2->next = tmp;
            break ;
        }
        tmp2 = tmp2->next;
    }
}

void        ft_rrr(t_stack **astack, t_stack **bstack)
{
    ft_rra(astack);
    ft_rrb(bstack);
}

int        ft_operation_found(char *operation)
{
    char **operations;
    int i;
    int found;

    i = 0;
    found = 0;
    operations = ft_split("sa;sb;ss;pa;pb;ra;rb;rr;rra;rrb;rrr", ';');
    while (operations[i])
    {
        if (ft_is_equal_str(operations[i], operation))
        {
            found = 1;
            ft_strfree(operations);
            break;
        }
        i++;
    }
    if (found == 1)
    {
        ft_strfree(operations);
        return (1);
    }
    else
    {
        ft_strfree(operations);
        return (0);
    }
}

void        ft_apply_operation(char *operation, t_stack **astack, t_stack **bstack)
{
    if (*astack || *bstack)
    {
        ;
    }
    if (ft_is_equal_str(operation, "sa"))
    {
        printf("sa\n");
		//ft_sa(astack);
    }
    if (ft_is_equal_str(operation, "sb"))
	{
    	printf("sb\n");
        //ft_sb(bstack);
    }
    if (ft_is_equal_str(operation, "ss"))
	{
    	printf("ss\n");
        //ft_ss(astack, bstack);
    }
    if (ft_is_equal_str(operation, "pa"))
	{
    	printf("pa\n");
        //ft_pa(astack);
    }
    if (ft_is_equal_str(operation, "pb"))
	{
    	printf("pb\n");
        //ft_pb(bstack);
    }
    if (ft_is_equal_str(operation, "ra"))
	{
    	printf("ra\n");
        //ft_ra(astack);
    }
    if (ft_is_equal_str(operation, "rb"))
	{
    	printf("rb\n");
        //ft_rb(bstack);
    }
    if (ft_is_equal_str(operation, "rr"))
	{
    	printf("rr\n");
        //ft_rr(astack, bstack);
    }
    if (ft_is_equal_str(operation, "rra"))
	{
    	printf("rra\n");
        //ft_rra(astack);
    }
    if (ft_is_equal_str(operation, "rrb"))
	{
    	printf("rrb\n");
        //ft_rrb(bstack);
    }
    if (ft_is_equal_str(operation, "rrr"))
	{
    	printf("rrr\n");
        //ft_rrr(astack, bstack);
    }
}

int        ft_operations_normed(t_stack **astack, t_stack **bstack)
{
    char *line;

    while (get_next_line(0, &line) > 0)
    {
        if (!ft_operation_found(line))
        {
            free(line);
            ft_putendl_fd("Error", 1);
            return (0);
        }
        else
        {
            ft_apply_operation(line, astack, bstack);
            free(line);
        }
    }
    return(1);
}