/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_dispatch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:13:39 by sboulet           #+#    #+#             */
/*   Updated: 2018/02/24 13:59:46 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_ssl_des.h"

void		ssl_dispatch(t_env *e)
{
	if (e->cmd & MD5)
		ssl_md5(e);
	else if (e->cmd & SHA256)
		// ssl_dispatch_sha256(e);
		printf("Dispatch sha256\n");
	else if (e->cmd & WHIRL)
		// ssl_dispatch_whirlpool(e);
		printf("Dispatch whirlpool\n");
}
