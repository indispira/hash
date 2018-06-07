/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_ssl_des.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:46:29 by sboulet           #+#    #+#             */
/*   Updated: 2018/03/02 00:22:08 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_SSL_DES_H
# define H_SSL_DES_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define MD5		1
# define SHA256	2
# define WHIRL	4

# define FLAG_P	1
# define FLAG_Q	2
# define FLAG_R	4
# define FLAG_S	8

# define BIT_1	1
# define BIT_2	2
# define BIT_3	4
# define BIT_4	8
# define BIT_5	16
# define BIT_6	32
# define BIT_7	64
# define BIT_8	128

typedef struct	s_env
{
	char					cmd;
	int						flag;
	const char		*infile;
	const char		*outfile;
	const char		*iv;
	char					*data;
	char					*out;
	int						nb_blocks;
	int						size_block;
	int						length;
}								t_env;

// ssl functions
int							ssl_parse(int ac, char **av, t_env *e);
int							ssl_read(t_env *e);
void						ssl_dispatch(t_env *e);
void						ssl_output(t_env *e);

// errors
int							ssl_help(char *s);
void						ssl_print_usage(t_env *e);
void						ssl_memory_error(t_env *e, const char *fct);
void						ssl_error_flags(const char *arg, char flag, t_env *e);
void						ssl_error_length(t_env *e, int length);

// free
void						ssl_free_env(t_env *e);

// inits
void						ssl_init_env(t_env *e);

#endif
