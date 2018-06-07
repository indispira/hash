/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:13:39 by sboulet           #+#    #+#             */
/*   Updated: 2018/03/01 23:42:37 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_ssl_des.h"

void	ssl_memory_error(t_env *e, const char *fct)
{
	ft_putstr("Memory allocation in function ");
	ft_putstr(fct);
	ft_putendl(" has failed.");
	if (e)
		ssl_free_env(e);
	exit(0);
}

int		ssl_ed(void)
{
	write(2, "Invalid combinaison of flags: ", 30);
	write(2, "impossible to encode and decode in the same time.\n", 50);
	return (0);
}

void	ssl_error_flags(const char *arg, char flag, t_env *e)
{
	printf("Enter to %s\n", __FUNCTION__);
	if (e->cmd & MD5)
		ft_putstr_fd("md5:\tinvalid option -- ", 2);
	else if (e->cmd & SHA256)
		ft_putstr_fd("sha256:\tinvalid option -- ", 2);
	else if (e->cmd & WHIRL)
		ft_putstr_fd("whirlpool:\tinvalid option -- ", 2);
	flag ? write(1, arg, 1) : ft_putstr(arg);
	if (e->cmd & MD5 || e->cmd & SHA256 || e->cmd & WHIRL)
		ssl_print_usage(e);
	exit(0);
}

int		ssl_help(char *s)
{
	write(2, "ft_ssl: Error: '", 16);
	write(2, s, ft_strlen(s));
	write(2, "' is an invalid command.\n\nStandard commands:\n\n", 46);
	write(2, "Message Digest commands:\nmd5\nsha256\nwhirlpool\n\n", 47);
	write(2, "Cipher commands:\n", 17);
	return (0);
}

void	ssl_error_length(t_env *e, int length)
{
	ssl_free_env(e);
	write(2, "Wrong length of input data, need a length modulo ", 49);
	ft_putnbr_fd(length, 2); // Sure about length ? Not size block ?
	write(2, "bits.\n", 6);
	exit(0);
}
