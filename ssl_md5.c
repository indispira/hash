/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_md5->c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:13:39 by sboulet           #+#    #+#             */
/*   Updated: 2018/02/24 13:59:46 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_ssl_des.h"

static unsigned int g_s[64] = { 7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
                                7, 12, 17, 22,  5,  9, 14, 20,  5,  9, 14, 20,
                                5,  9, 14, 20,  5,  9, 14, 20,  4, 11, 16, 23,
                                4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
                                6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,
                                6, 10, 15, 21};

static unsigned int g_k[64] = {0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
                               0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
                               0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
                               0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
                               0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
                               0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
                               0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
                               0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
                               0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
                               0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
                               0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
                               0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
                               0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
                               0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
                               0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
                               0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

static void md5_init(t_env *e, t_md5 *md5)
{
    unsigned int  length;

    md5->a0 = 1732584193;
    md5->b0 = 4023233417;
    md5->c0 = 2562383102;
    md5->d0 = 271733878;
    ft_memset(md5->hash, 0, 16);
    md5->blocks = NULL;
    length = e->length % 64 <= 56 ? e->length / 64 + 1 : e->length / 64 + 2;
    if (!(md5->blocks = ft_memalloc(length * 64)))
      ssl_memory_error(e, (void*)md5, __FUNCTION__);
    ft_memcpy(md5->blocks, e->data, e->length);
    md5->blocks[e->length] = (unsigned int)1 << 7;
    *(unsigned int*)(md5->blocks + length * 64 - 8) = e->length * 8 % UINT_MAX;
    *(unsigned int*)(md5->blocks + length * 64 - 4) = e->length * 8 / UINT_MAX;
    md5->nb_blocks = length;
    e->size_hash = 32;
}

static void md5_16_iteration(t_md5 *md5, unsigned int *f, unsigned int *g,
                             unsigned int i)
{
  if (i < 16)
  {
    *f = (md5->b & md5->c) | ((~md5->b) & md5->d);
    *g = i;
  }
  else if (i < 32)
  {
    *f = (md5->d & md5->b) | ((~md5->d) & md5->c);
    *g = (5 * i + 1) % 16;
  }
  else if (i < 48)
  {
    *f = md5->b ^ md5->c ^ md5->d;
    *g = (3 * i + 5) % 16;
  }
  else
  {
    *f = md5->c ^ (md5->b | (~md5->d));
    *g = (7 * i) % 16;
  }
}

static void md5_hash_loop(t_md5 *md5)
{
  unsigned int  i;
  unsigned int  f;
  unsigned int  g;

  i = 0;
  while (i < 64)
  {
    md5_16_iteration(md5, &f, &g, i);
    f = f + md5->a + g_k[i] + md5->m[g];
    md5->a = md5->d;
    md5->d = md5->c;
    md5->c = md5->b;
    md5->b = md5->b + (f << g_s[i]);
    md5->b = md5->b + (f >> (32 - g_s[i]));
    i++;
  }
}

static void md5_loop_on_block(t_md5 *md5, char *block)
{
    unsigned int  i;

    i = 0;
    while (i < 16)
    {
        md5->m[i] = 0;
        md5->m[i] |= *(block + i * 4) & 255;
        md5->m[i] |= *(block + i * 4 + 1) << 8 & 65280;
        md5->m[i] |= *(block + i * 4 + 2) << 16 & 16711680;
        md5->m[i] |= *(block + i * 4 + 3) << 24 & 4278190080;
        i++;
    }
    md5->a = md5->a0;
    md5->b = md5->b0;
    md5->c = md5->c0;
    md5->d = md5->d0;
    md5_hash_loop(md5);
    md5->a0 += md5->a;
    md5->b0 += md5->b;
    md5->c0 += md5->c;
    md5->d0 += md5->d;
}

void        ssl_md5(t_env *e)
{
    t_md5         md5;
    unsigned int  i;

    md5_init(e, &md5);
    i = 0;
    while (i < md5.nb_blocks)
    {
      md5_loop_on_block(&md5, md5.blocks + i * 64);
      i++;
    }
    memcpy(md5.hash, &md5.a0, 4);
    memcpy(md5.hash + 4, &md5.b0, 4);
    memcpy(md5.hash + 8, &md5.c0, 4);
    memcpy(md5.hash + 12, &md5.d0, 4);
    if (!(e->out = ft_strdup(md5.hash)))
      ssl_memory_error(e, (void*)&md5, __FUNCTION__);
    ssl_free_md5(&md5);
}
