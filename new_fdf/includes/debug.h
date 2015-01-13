/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 10:33:50 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/13 11:28:45 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

enum	e_type
{
	INT,
	CHAR
};

/*
** debug_01.h
*/

void		print_type(char *str, void *elem, int type);
void		print_map(char **map);
void		print_tab(char ***tab);
void		print_coord(t_coord **tab, int size);

#endif
