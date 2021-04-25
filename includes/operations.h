#ifndef _OPERATIONS_H
# define _OPERATIONS_H
# include "../libft/libft.h"
# include "utils.h"

int                     ft_check_numbers(char **av);
void                    ft_print_stack(t_stack *stack);
int                     ft_push(t_stack **stack, int number);
int                     ft_pop(t_stack **stack);
void                    ft_apply_operation(char *line, t_stack **astack, t_stack **bstack);
int                     ft_isduplicate(char **av, char *number);
t_stack                 *ft_new_stack(char **av);
void                    ft_free_stack(t_stack **stack);
int                     ft_tablen(char **pointer_tab);
///////////////////////////////////////////// Remastered code above ///////////////////////
int                     ft_isint(char *av);
t_stack                 *ft_new_number(int number);
t_operations	        *ft_new_operation(char *operation);
void	                ft_lstadd_back_number(t_stack **alst, t_stack *new);
void	                ft_lstadd_back_operation(t_operations **alst, t_operations *new);
int			            ft_get_len_stack(t_stack *astack);
int                     ft_stack_is_sorted(t_stack *head);
int                     ft_operations_normed(t_stack **astack, t_stack **bstack);
int                     ft_is_equal_str(char *s1, char *s2);
int                     ft_get_maximum_value(int a, int b);

// Operations
void                    ft_sa(t_stack **astack);
void                    ft_sb(t_stack **bstack);
void                    ft_ss(t_stack **astack, t_stack **bstack);
void                    ft_pa(t_stack **astack, t_stack **bstack);
void                    ft_pb(t_stack **bstack, t_stack **astack);
void                    ft_ra(t_stack **astack);
void                    ft_rb(t_stack **bstack);
void                    ft_rr(t_stack **astack, t_stack **bstack);
void                    ft_rra(t_stack **astack);
void                    ft_rrb(t_stack **bstack);
void                    ft_rrr(t_stack **astack, t_stack **bstack);

//// check function param's order stack is not afected

# endif
