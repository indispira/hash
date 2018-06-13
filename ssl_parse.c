/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:13:39 by sboulet           #+#    #+#             */
/*   Updated: 2018/02/24 18:22:40 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_ssl_des.h"

static void	ssl_check_flags(t_env *e, char c)
{
	unsigned int	flag;

	flag = e->flag;
	e->flag |= c == 'p' ? FLAG_P : 0;
	e->flag |= c == 'q' ? FLAG_Q : 0;
	e->flag |= c == 'r' ? FLAG_R : 0;
	e->flag |= c == 's' ? FLAG_S : 0;
	if (flag == e->flag)
		ssl_error_flags(&c, 1, e);
}

static int	ssl_args_parser(int ac, char **av, t_env *e)
{
	int			i;
	const char	*arg;

	i = 1;
	while (++i < ac)
	{
		arg = av[i];
		if (!e->infile && *arg == '-')
			while (*(++arg))
				ssl_check_flags(e, *arg);
		else
			e->infile = av[i];
	}
	return (1);
}

int			ssl_parse(int ac, char **av, t_env *e)
{
	if (!ft_strcmp("md5", av[1]))
		e->cmd = MD5;
	else if (!ft_strcmp("sha256", av[1]))
		e->cmd = SHA256;
	else if (!ft_strcmp("whirlpool", av[1]))
		e->cmd = WHIRL;
	if (e->cmd)
		return (ssl_args_parser(ac, av, e));
	return (ssl_help(av[1]));
}
