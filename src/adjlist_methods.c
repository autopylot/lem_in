/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjlist_methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 11:45:33 by wlin              #+#    #+#             */
/*   Updated: 2017/08/22 10:58:26 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//find room and returns adj list
t_link **get_adjlist(char *name, t_room *head)
{
	t_room *curr = head;

	while (curr)
	{
		if (ft_strcmp(name, curr->name) == 0)
			return (&(curr->adj_list));
		else
			curr = curr->next;
	}
	return (NULL);
}

t_room *get_room(char *name, t_room *head)
{
	t_room *curr = head;

	while (curr)
	{
		if (ft_strcmp(name, curr->name) == 0)
			return (curr);
		else
			curr = curr->next;
	}
	return (NULL);
}

void add_room(char *line, int *mod, t_antfarm *farm)
{
	char **room_def;
	t_room *new_rm;

	room_def = ft_strsplit(line, ' ');
	new_rm = init_room(room_def);
	if (*mod == 1)
		farm->start = new_rm->name;
 	else if (*mod == -1)
		farm->end = new_rm->name;
	if (farm->rms)
	{
		new_rm->next = farm->rms;
		farm->rms = new_rm;
	}
	else
		farm->rms = new_rm;
	++(farm->n_rms);
	*mod = 0;
	//free room_def memory
}

void add_link(t_link **adj_list, t_room *adj_rm)
{
	t_link *new_link;
	t_link **curr = adj_list;

	new_link = init_link(adj_rm);
	if (*curr)
	{
		new_link->next = *curr;
		*curr = new_link;
	}
	else
		*curr = new_link;
}

void setup_links(char *line, t_room *head)
{
	int i;
	char **link_def;
	t_link **adj_list;
	t_room *adj_rm;

	i = -1;
	link_def = ft_strsplit(line, '-');
	//printf("Link %s - %s\n", link_def[0], link_def[1]);
	while (link_def[++i])
	{
		//printf("Adj list for room: %s\n", link_def[i]);
		adj_list = get_adjlist(link_def[i], head);

		adj_rm = get_room(link_def[i + (i == 0 ? 1 : -1)], head);
		//printf("Adding adj rm: %s\n", link_def[i + (i == 0 ? 1 : -1)]);
		add_link(adj_list, adj_rm);
		//print_adj(*adj_list);

	}
}
