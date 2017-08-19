/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 12:14:36 by wlin              #+#    #+#             */
/*   Updated: 2017/08/19 14:27:21 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room  *room(char **room_def)
{
	t_room *new_rm;

	new_rm = (t_room*)malloc(sizeof(t_room));
	new_rm->name = ft_strdup(room_def[0]);
	new_rm->full = 0;
	new_rm->cord[0] = ft_atoi(room_def[1]);
	new_rm->cord[1] = ft_atoi(room_def[2]);
	new_rm->adj_list = NULL;
	return (new_rm);
}

t_link *link(t_room *adj_rm)
{
	t_link *new_link;

	new_link = (t_link*)malloc(sizeof(t_link));
	new_link->adj_rm = adj_rm;
	new_link->next = NULL;
	return (new_link);
}

void init_farm(t_antfarm *farm)
{
	farm->n_rms = 0;
	farm->n_ants = 0;
	farm->start = NULL;
	farm->end = NULL;
	farm->colony = NULL;
	farm->rms = NULL;
}
//find room and returns adj list
t_link *get_adjlist(char *name, t_room *head)
{
	while (head)
	{
		if (ft_strcmp(name, head->name) == 0)
			return (head->adj_list);
		else
			head = head->next;
	}
	return (NULL);
}

t_room *get_room(char *name, t_room *head)
{
	while (head)
	{
		if (ft_strcmp(name, head->name) == 0)
			return (head);
		else
			head = head->next;
	}
	return (NULL);
}

void add_room(char **room_def, int mod, t_room **head)
{
	t_room *new_rm;
	static int roomID = 1;

	new_rm = init_room(room_def);
	if (mod == 1)
		new_rm->roomID = 0;
	else if (mod == -1)
		new_rm->roomID = -1;
	else
		new_rm->roomID = roomID++;
	if (*head)
	{
		new_rm->next = *head;
		*head = new_rm;
	}
}

void setup_links(char *line, t_room *head)
{
	int i;
	char **link_def;
	t_link *adj_list;
	t_room *adj_rm;

	i = -1;
	link_def = ft_strsplit(line, '-');
	while (link_def[++i])
	{
		adj_list = get_adjlist(link_def[i], head);
		while (adj_list->next)
			adj_list = adj_list->next;
		adj_rm = get_room(link_def[i + (i == 0 ? 1 : -1)], head);
		adj_list->next = init_link(adj_rm);
	}
}
