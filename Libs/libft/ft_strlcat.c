/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:29:36 by svillalv          #+#    #+#             */
/*   Updated: 2022/05/04 21:57:39 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && dstsize != 0)
	{
		i++;
		dstsize--;
	}
	while (src[j] != '\0' && dstsize > 1)
	{
		dst[i] = src[j];
		i++;
		j++;
		dstsize--;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	while (src[j] != '\0')
	{
		j++;
		i++;
	}
	return (i);
}
