/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:42:26 by cglavieu          #+#    #+#             */
/*   Updated: 2015/12/19 16:32:29 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include "libft.h"

typedef struct	s_env
{
	char	**env;
	char	**av;
	char	**tmp2;
	int		mem;
	size_t	i;
	size_t	j;
	size_t	k;
}				t_env;

char		**g_pwd;
char		**g_oldpwd;
char		**g_home;
char		**g_paths;

void		ft_swagg(char *s);
void		prompt(void);

void		handler(int sig);
void		handler2(int sig);

void		parse_env(t_env *e, char **ep);
void		parse_cmd(t_env *e, char *buf);
void		inspection(t_env *e);
void		chk_n_ex_cmd(t_env *e);

void		modif_env(t_env *e, char *var, char *val);
void		usefull_vars(t_env *e, size_t i);
void		re_usefull_vars(t_env *e);
void		ft_setenv(t_env *e);
void		ft_unsetenv(t_env *e);
void		print_env(t_env *e);
void		print_vars(t_env *e);
void		ft_swagg(char *s);
void		check_tild_minus(t_env *e, size_t z);
void		ft_cd(t_env *e);
void		change_dir(t_env *e, char *s);

#endif
