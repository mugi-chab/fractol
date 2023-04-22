/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:48:37 by svillalv          #+#    #+#             */
/*   Updated: 2022/05/22 20:52:28 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *) malloc(sizeof(char) * len + 1);
	if (!s3)
		return (NULL);
	ft_memmove(s3, s1, ft_strlen(s1));
	ft_memmove(s3 + ft_strlen(s1), s2, ft_strlen(s2));
	s3[len] = '\0';
	return (s3);
}
