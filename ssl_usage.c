/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_usage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:13:39 by sboulet           #+#    #+#             */
/*   Updated: 2018/02/24 16:55:02 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_ssl_des.h"

static void	ssl_print_usage_md5(void)
{
	ft_putendl("\nUsage:\tmd5 [-pqrs]");
	ft_putstr("  -p\t\t\techo STDIN to STDOUT and the checksum to STDOUT\n");
	ft_putstr("  -q\t\t\tquiet mode\n");
	ft_putstr("  -r\t\t\treverse the format of the output\n");
	ft_putstr("  -s\t\t\tprint the sum of the given string\n");
}

static void	ssl_print_usage_sha256(void)
{
	ft_putstr("\nUsage:\tsha256 [-pqrs]");
	ft_putstr("  -p\t\t\techo STDIN to STDOUT and the checksum to STDOUT\n");
	ft_putstr("  -q\t\t\tquiet mode\n");
	ft_putstr("  -r\t\t\treverse the format of the output\n");
	ft_putstr("  -s\t\t\tprint the sum of the given string\n");
}

static void	ssl_print_usage_whirlpool(void)
{
	ft_putstr("\nUsage:\twhirlpool [-pqrs]");
	ft_putstr("  -p\t\t\techo STDIN to STDOUT and the checksum to STDOUT\n");
	ft_putstr("  -q\t\t\tquiet mode\n");
	ft_putstr("  -r\t\t\treverse the format of the output\n");
	ft_putstr("  -s\t\t\tprint the sum of the given string\n");
}

void		ssl_print_usage(t_env *e)
{
	if (e->cmd & MD5)
		ssl_print_usage_md5();
	else if (e->cmd & SHA256)
		ssl_print_usage_sha256();
	else if (e->cmd & WHIRL)
		ssl_print_usage_whirlpool();
}
