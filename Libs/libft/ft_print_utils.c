/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:10:33 by svillalv          #+#    #+#             */
/*   Updated: 2022/09/21 12:46:11 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		i = 6;
	}
	else
	{
		i = -1;
		while (str[++i])
			write(1, &str[i], 1);
	}
	return (i);
}

int	ft_printnbr(int n)
{
	char	*str_n;
	int		len;

	str_n = ft_itoa(n);
	ft_putstr_fd(str_n, 1);
	len = ft_strlen(str_n);
	free(str_n);
	return (len);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
