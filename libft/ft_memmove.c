/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:45:26 by anfreire          #+#    #+#             */
/*   Updated: 2022/02/15 13:45:38 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

	dest = dst;
	source = (char *)src;
	if (dest > source)
	{
		while (len--)
			dest[len] = source[len];
	}
	else if (dest < source)
		ft_memcpy(dst, src, len);
	return (dst);
}
