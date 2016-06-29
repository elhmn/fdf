/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:10:43 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/05 18:49:41 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		car;
	const unsigned char	*ptr;
	size_t				i;

	i = 0;
	car = (unsigned char)c;
	ptr = (const unsigned char*)s;
	if (!s)
		return (0);
	while (i < n)
	{
		if (*ptr == car)
			return ((void*)ptr);
		ptr++;
		i++;
	}
	return (NULL);
}
