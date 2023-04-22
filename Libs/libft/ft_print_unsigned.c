/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:53:34 by svillalv          #+#    #+#             */
/*   Updated: 2022/09/21 12:44:41 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int num)
{
	int		i;
	char	*str_num;

	i = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		i++;
	}
	else
	{
		str_num = ft_uitoa(num);
		i = ft_strlen(str_num);
		ft_putstr_fd(str_num, 1);
		free(str_num);
	}
	return (i);
}
