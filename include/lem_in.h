/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 11:31:04 by wlin              #+#    #+#             */
/*   Updated: 2017/08/17 15:34:15 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H
#include "../libft/libft.h"

typedef struct s_path
{
	int *route;
	int len;
	s_path *next;
}	t_path;

typedef struct s_link
{
	char *src;
	char *dst;
}	t_link;

typedef struct s_room
{
	char *name;
	char loc;
	char full;
	int cord[2];
	t_link *adjlist;
}	t_room;

typedef struct s_antfarm
{
	t_room *farm_rms;
	t_link *rm_links;
	int n_rms;
	int n_ants;
}	t_antfarm;



#endif
