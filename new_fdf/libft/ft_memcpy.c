/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:29:22 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/03 11:19:16 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*tmp_d;
	char	*tmp_s;
	size_t	u;

	tmp_s = (char*)src;
	tmp_d = (char*)dest;
	u = 0;
	if (tmp_s && tmp_d)
	{
		while (u < n)
		{
			*tmp_d = *tmp_s;
			tmp_s++;
			tmp_d++;
			u++;
		}
	}
	return (dest);
}
