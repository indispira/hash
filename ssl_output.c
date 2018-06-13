/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:13:39 by sboulet           #+#    #+#             */
/*   Updated: 2018/02/18 23:03:16 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_ssl_des.h"

void    ssl_print_hex(t_env *e)
{
  unsigned int  i;
  unsigned char c;

  i = 0;
  while (i < e->size_hash / 2)
  {
    c = (unsigned char)e->out[i] / 16;
    if (c > 9)
      ft_putchar(c - 10 + 'a');
    else
      ft_putchar(c + '0');
    c = (unsigned char)e->out[i] % 16;
    if (c > 9)
      ft_putchar(c - 10 + 'a');
    else
      ft_putchar(c + '0');
    i++;
  }
  write(1, "\n", 1);
}

void		ssl_output(t_env *e)
{
  if (e->flag & FLAG_P)
    ft_putstr(e->data);
  ssl_print_hex(e);
}
