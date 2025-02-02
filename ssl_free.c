/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:13:39 by sboulet           #+#    #+#             */
/*   Updated: 2018/03/02 01:19:06 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_ssl_des.h"

void		ssl_free_env(t_env *e)
{
	if (e->data)
		ft_memdel((void**)&e->data);
	if (e->out)
		ft_memdel((void**)&e->out);
}

void    ssl_free_md5(t_md5 *md5)
{
  if (md5->blocks)
    ft_memdel((void**)&md5->blocks);
}