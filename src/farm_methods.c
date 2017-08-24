/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 11:45:33 by wlin              #+#    #+#             */
/*   Updated: 2017/08/24 14:51:33 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link **get_adjlist(char *name, t_room *head)
{
	t_room *curr;

	curr = head;
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
	t_room *curr;

	curr = head;
	while (curr)
	{
		if (ft_strcmp(name, curr->name) == 0)
			return (curr);
		else
			curr = curr->next;
	}
	return (NULL);
}

void	 add_room(char *line, t_antfarm *farm, int *mod)
{
	t_room *new_rm;
	char **room_def;

	room_def = ft_strsplit(line, ' ');
	new_rm = init_room(room_def);
	if (*mod == 1)
		farm->start = new_rm->name;
 	else if (*mod == 2)
		farm->end = new_rm->name;
	*mod = 0;
	if (farm->rms)
	{
		new_rm->next = farm->rms;
		farm->rms = new_rm;
	}
	else
		farm->rms = new_rm;
	++(farm->n_rms);
	ft_arrdel(room_def);
}

void	add_link(t_link **adj_list, t_room *adj_rm)
{
	t_link *new_link;
	t_link **curr;

	curr = adj_list;
	new_link = init_link(adj_rm);
	if (*curr)
	{
		new_link->next = *curr;
		*curr = new_link;
	}
	else
		*curr = new_link;
}

//check for links to rooms not defined
void setup_links(char *line, t_room *head)
{
	int		i;
	char	**link_def;
	t_link	**adj_list;
	t_room	*adj_rm;

	i = -1;
	link_def = ft_strsplit(line, '-');
	while (link_def[++i])
	{
		adj_list = get_adjlist(link_def[i], head);
		adj_rm = get_room(link_def[i + (i == 0 ? 1 : -1)], head);
		add_link(adj_list, adj_rm);
	}
	ft_arrdel(link_def);
}
