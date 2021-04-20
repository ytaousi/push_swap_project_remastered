#include "../includes/operations.h"

int ft_isint(char *av)
{
    int i;

    i = 0;
    if (i == 0 && (av[i] == '-' || av[i] == '+'))
    {
        i++;
        while (av[i] != '\0')
        {
            if (!ft_isdigit(av[i]))
                return (0);
            i++;
        }
    }
    else
        while(av[i] != '\0')
        {
            if(!ft_isdigit(av[i]))
                return (0);
            i++;
        }
    return (1);

}

t_stack	*ft_new_number(int number)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	new->number = number;
	new->next = NULL;
	return (new);
}

t_operations	*ft_new_operation(char *operation)
{
	t_operations *new;

	if (!(new = (t_operations *)malloc(sizeof(t_operations))))
		return (0);
	new->operation = ft_strdup(operation);
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_number(t_stack **alst, t_stack *new)
{
	t_stack *tmp;

	tmp = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_lstadd_back_operation(t_operations **alst, t_operations *new)
{
	t_operations *tmp;

	tmp = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
int			ft_get_len_env(t_stack *astack)
{
    t_stack *tmp;
    int     len;

    len = 0;
    tmp = astack;
    while (tmp)
    {
        len++;
        tmp = tmp->next;
    }
    return (len);
}

int			ft_get_maximum_value(int a, int b)
{
	if (a > b)
		return (a);
	else
		return(b);
}

int		ft_is_equal_str(char *s1, char *s2)
{
	if (ft_strncmp(s1, s2, ft_get_maximum_value(ft_strlen(s1), ft_strlen(s2))) == 0)
		return (1);
	else
		return (0);
}