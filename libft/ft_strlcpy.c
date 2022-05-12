/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:45:52 by anfreire          #+#    #+#             */
/*   Updated: 2022/02/15 13:45:54 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;
	char	*s;

	i = 0;
	len = 0;
	s = (char *)src;
	len = ft_strlen(s);
	if (!dstsize)
		return (len);
	while (s[i] && i < dstsize - 1)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
