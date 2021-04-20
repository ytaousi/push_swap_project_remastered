#include "operations.h"

int main(int ac, char **av)
{
    int i;

    i = 1;
    if (ac > 1)
    {
        while (av[i] != NULL)
        {
            if (!ft_isint(av[i]))
            {
                ft_putendl_fd("Error", 1);
                return (0);
            }
            i++;
        }

        

    }
    write(1, "\n", 1);
    return (0);
}