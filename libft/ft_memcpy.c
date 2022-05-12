/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:54:21 by anfreire          #+#    #+#             */
/*   Updated: 2022/02/14 18:09:12 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*sd;
	char	*sr;

	if (!dst && !src)
		return (NULL);
	i = 0;
	sr = (void *)src;
	sd = dst;
	while (i < n)
	{
		sd[i] = sr[i];
		i++;
	}
	return (dst);
}
