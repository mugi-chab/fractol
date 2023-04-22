/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:59:09 by svillalv          #+#    #+#             */
/*   Updated: 2022/05/25 21:59:09 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	if (!lst)
		return (0);
	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
