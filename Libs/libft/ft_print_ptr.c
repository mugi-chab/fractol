/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:07:19 by svillalv          #+#    #+#             */
/*   Updated: 2022/09/21 12:44:49 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pointer_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_pointer(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_pointer(num / 16);
		ft_put_pointer(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	i;

	write(1, "0x", 2);
	i = 2;
	if (ptr == 0)
	{
		write(1, "0", 1);
		i++;
	}
	else
	{
		ft_put_pointer(ptr);
		i += ft_pointer_len(ptr);
	}
	return (i);
}
