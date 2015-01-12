/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 17:15:02 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/05 17:20:00 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int		sign;
	int		num;

	sign = -1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str == '0')
		str++;
	if (count_digit(str) > 10)
		return (sign);
	num = 0;
	while (*str && ft_isdigit(*str))
	{
		num = num * 10 + *str - '0';
		str++;
	}
	if (!sign)
		num = -num;
	return (num);
}
