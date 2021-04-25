#ifndef _UTILS_H
# define _UTILS_H

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

#endif