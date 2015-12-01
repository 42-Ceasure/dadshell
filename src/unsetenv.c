#include "shell.h"

void		unset_utils(t_env *e, char *lol, int varl)
{
	if (!ft_strncmp(lol, "PWD=", varl))
		*e->pwd = NULL;
	else if (!ft_strncmp(lol, "OLDPWD=", varl))
		*e->oldpwd = NULL;
	else if (!ft_strncmp(lol, "HOME=", varl))
		*e->home = NULL;
	else if (!ft_strncmp(lol, "PATH=", varl))
	{
		memreg(e->paths);
		e->paths = NULL;
	}
}

char		**new_env(t_env *e, char *lol, int varl)
{
	char	**tmp;
	size_t	i;
	size_t	j;
	int		mem;

	i = 0;
	mem = 0;
	while (e->env[i])
	{
		if (!ft_strncmp(e->env[i], lol, varl))
			mem = 1;
		i++;
	}
	if (mem == 1)
	{
		tmp = (char **)ft_memalloc(sizeof(char *) * i);
		i = 0;
		while (e->env[i] && ft_strncmp(e->env[i], lol, varl) != 0)
		{
			tmp[i] = ft_strdup(e->env[i]);
			i++;
		}
		j = i;
		i = i + 1;
		while (e->env[i])
		{
			tmp[j] = ft_strdup(e->env[i]);
			i++;
			j++;
		}
		memreg(e->env);
		return (tmp);
	}
	else
	{
		ft_putendl("no var");
		return (e->env);
	}
}

void		ft_unsetenv(t_env *e)
{
	int		varl;
	char	*var;
	char	*lol;
	
	e->i = 0;
	var = ft_strdup(e->av[1]);
	lol = ft_strjoin(var, "=");
	varl = ft_strlen(lol);
	while (e->env[e->i])
		e->i++;
	if (e->av[1])
	{
		e->env = new_env(e, lol, varl);
		unset_utils(e, lol, varl);
	}
	else
		ft_putendl("use unsetenv <var>");
	free(lol);
	free(var);
	lol = NULL;
	var = NULL;
	prompt(e);
}
