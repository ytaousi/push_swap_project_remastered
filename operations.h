#ifndef _OPERATIONS_H
# define _OPERATIONS_H
#include "./libft/libft.h"

typedef struct      s_stack
{
    int             number;
    struct s_stack  *next;
}                   t_stack;

typedef struct          s_operations
{
    char                *operation;
    int                 index;
    struct s_operations *next;
}                       t_operations;

int                     ft_isint(char *av);
t_stack                 *ft_new_number(int number);
t_operations	        *ft_new_operation(char *operation);
void	                ft_lstadd_back_number(t_stack **alst, t_stack *new);
void	                ft_lstadd_back_operation(t_operations **alst, t_operations *new);
int			            ft_get_len_env(t_stack *astack);
int                     ft_stack_is_sorted(t_stack *head);
int                     ft_operations_normed(t_operations **operation_in , char **tab);
int                     ft_is_equal_str(char *s1, char *s2);
int                     ft_get_maximum_value(int a, int b);
void                    ft_apply_operations(t_operations *operation_in, t_stack **astack, t_stack **bstack);

// Operations
int                     ft_sa(t_stack **astack, t_stack **bstack);
int                     ft_sb(t_stack **bstack, t_stack **astack);
int                    ft_ss(t_stack **astack, t_stack **bstack);
int                     ft_pa(t_stack **astack, t_stack **bstack);
int                     ft_pb(t_stack **bstack, t_stack **astack);
int                     ft_ra(t_stack **astack, t_stack **bstack);
int                     ft_rb(t_stack **bstack, t_stack **astack);
int                    ft_rr(t_stack **astack, t_stack **bstack);
int                     ft_rra(t_stack **astack, t_stack **bstack);
int                     ft_rrb(t_stack **bstack, t_stack **astack);
int                    ft_rrr(t_stack **astack, t_stack **bstack);

//// check function param's order stack is not afected

# endif
