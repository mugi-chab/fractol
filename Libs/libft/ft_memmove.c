/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:13:10 by svillalv          #+#    #+#             */
/*   Updated: 2022/04/26 20:31:49 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!len || dst == src)
		return (dst);
	if (dst > src)
	{
		while (len --)
		{
			((unsigned char *) dst)[len] = ((unsigned const char *)src)[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
