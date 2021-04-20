#include "./libft/libft.h"

typedef struct s_env
{
    char *key;
    char *value;
    struct s_env *next;
}t_env;

typedef struct s_cmds
{
    char **tokenz;

}t_cmds;

typedef struct s_multipls
{
    t_cmds **cmds;
    int    nb_semicolons;   
}t_multipls;

int ft_tablen(char **pointer_tab)
{
    int i;

    i = 0;
    if (pointer_tab)
    {
        while (pointer_tab[i] != NULL)
            i++;
    }
    return (i);
}

t_cmds		*ft_new_cmds(char *line)
{
	t_cmds	*cmd;

	cmd = (t_cmds *)malloc(sizeof(t_cmds));
    cmd->tokenz = ft_split(line, ' ');
	return (cmd);
}

t_multipls		*ft_new_multipls(char **lines)
{
	t_multipls	*parsed_line;
	int			i;

    i = 0;
	parsed_line = (t_multipls *)malloc(sizeof(t_multipls));
	parsed_line->cmds = (t_cmds **)malloc(sizeof(t_cmds *) * (ft_tablen(lines) + 1));
	while (lines[i])
    {
		parsed_line->cmds[i] = ft_new_cmds(lines[i]);
        i++;
    }
	parsed_line->cmds[i] = 0;
	parsed_line->nb_semicolons = i;
	return (parsed_line);
}

void ft_free_tab(char **pointer_tab)
{
	int		i;

	i = 0;
	if (pointer_tab)
	{
		while (pointer_tab[i])
		{
			if (pointer_tab[i])
				free(pointer_tab[i]);
			i++;
		}
		free(pointer_tab);
	}
}


int main(int ac, char **av, char **env)
{
    int i = 0;
    int j = 0;
    int k;
    char **semicolons;
    t_multipls **parsed_line;
    char **cmds;
    char *line = "echo yassir | cat file1 | echo < file2;wonder lool | yolo polo; pronto boyyyyy";
    
    semicolons = ft_split(line, ';');
    parsed_line = (t_multipls **)malloc(sizeof(t_multipls *) * (ft_tablen(semicolons) + 1));
    while (semicolons[i] != NULL)
    {
        cmds = ft_split(semicolons[i], '|');
        parsed_line[i] = ft_new_multipls(cmds);
        ft_free_tab(cmds);
        i++;
    }
    parsed_line[i] = 0;
    ft_free_tab(semicolons);

    i = 0;
    while (parsed_line[i] != NULL)
    {
        j = 0;
        while(parsed_line[i]->cmds[j] != NULL)
        {
            k = 0;
            while (parsed_line[i]->cmds[j]->tokenz[k] != NULL)
            {
                ft_putendl_fd(parsed_line[i]->cmds[j]->tokenz[k], 1);
                k++;
            }
            j++;
            write(1, "\n", 1);
        }
        write(1, "\n", 1);
        i++;
    }
    return (0);
}