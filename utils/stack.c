#include "../includes/operations.h"

int     ft_peek(t_stack *stack)
{
    if (!stack)
        return (-1);
    return (stack->number);
}

int     ft_push(t_stack **stack, int number)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (!new)
        return -1;
    new->number = number;
    new->next = *stack;
    *stack = new;
    return (1);
}

int    ft_pop(t_stack **stack)
{
    int number;
    t_stack *tmp;
    if (*stack == NULL)
        return -1;
    tmp = *stack;
    number = tmp->number;
    *stack = tmp->next;
    free(tmp);
    return (number);
}

int         ft_stack_is_sorted(t_stack *head)
{
    t_stack *tmp;

    tmp = head;
    if (ft_get_len_stack(head) < 2)
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

t_stack *ft_new_stack(char **av)
{
	t_stack *astack;
	int  i;

	astack = NULL;
	i = 1;
	while (av[i] != NULL)
	{
    	ft_lstadd_back_number(&astack, ft_new_number(ft_atoi(av[i])));
    	i++;
	}
	return (astack);
}

void    ft_free_stack(t_stack **stack)
{
    t_stack *tmp;

    if (*stack)
    {
        while (*stack)
        {
            tmp = *stack;
            *stack = tmp->next;
            free(tmp);
        }
    }
}