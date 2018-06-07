/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:13:39 by sboulet           #+#    #+#             */
/*   Updated: 2018/03/02 00:29:18 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_ssl_des.h"

void	ssl_init_env(t_env *e)
{
	e->cmd = 0;
	e->flag = 0;
	e->infile = NULL;
	e->outfile = NULL;
	e->iv = NULL;
	e->data = NULL;
	e->out = NULL;
	e->nb_blocks = 0;
	e->size_block = 0;
	e->length = 0;
}
