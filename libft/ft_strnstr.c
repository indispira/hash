/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:50:41 by sboulet           #+#    #+#             */
/*   Updated: 2015/11/26 13:56:56 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (++i < n && s1[i] != '\0')
	{
		j = 0;
		if (s1[i] == s2[0])
		{
			while (s1[i + j] == s2[j] && i + j < n && s1[i + j] != '\0')
				j++;
			if (s2[j] == '\0')
				return (&((char*)s1)[i]);
		}
	}
	return (NULL);
}
