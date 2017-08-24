/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 12:56:11 by wlin              #+#    #+#             */
/*   Updated: 2017/08/24 14:58:07 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int valid_def(char *def, int i)
{
	int j;

	j = -1;
	if (i == 0)
	{
		while (def[++j])
		{
			if (def[j] == '#' || def[j] == 'L'))
				return (0);
			else if (!ft_isalnum(def[j])
				return (0);
		}
	}
	else if (i == 1 || i == 2)
	{
		while (def[++j])
		{
			if (!ft_isdigit(def[j]))
				return (0);
		}
	}
	else
		return (0);
	return (1);
}

//check if defined room is already in list
int room_dupe(char **room_def, t_room *head)
{
	while (head)
	{
		if (head->name == room_def[0])
			return (1);
		if (head->cord[0] == room_def[1] && head->cord[1] == room_def[2])
			return (1);
		head = head->next;
	}
	return (0);
}

// cannot start with L or #
int valid_room(char *line, t_room *head)
{
	int i;
	int j;
	char **room_def;

	i = -1;
	room_def = ft_strsplit(line, ' ');
	while (room_def[++i])
	{
		if (!valid_def(room_def[i], i))
		{
			ft_arrdel(room_def);
			return (0);
		}
	}
	if (room_dupe(room_def, head))
	{
		ft_arrdel(room_def);
		return (0);
	}
	ft_arrdel(room_def);
	return (1);
}

//check for duplicate links
int link_dupe(char **link_def, t_room *head)
{
	t_room *room;
	t_link *link;

	room = get_room(link_def[0], head);
	link = room->adj_list;
	while (link)
	{
		if (link->adj_rm->name == link_def[1])
			return (1)
		link = link->next;
	}
	return (0);
}

int valid_link(char *line, t_room *head)
{
	int i;
	char **link_def;

	i = 0;
	link_def = ft_strsplit(line, '-');
	while (link_def[i])
	{
		if (!get_room(link_def[i], head) || i > 1)
		{
			ft_arrdel(link_def);
			return (0);
		}
		++i
	}
	if (link_dupe(link_def, head))
	{
		ft_arrdel(link_def);
		return (0);
	}
	ft_arrdel(link_def);
	return (1);
}

// check when no start/end is defined
// check if no rooms, ants, or links are defined
int	validate(t_antfarm *farm)
{
	if (farm->n_ants < 1)
		return (0);
	else if (farm->start == NULL || farm->end == NULL)
		return (0);
	else if (farm->rms == NULL)
		return (0);
	else if ()
	//check path from start to end
}
