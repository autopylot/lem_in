/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:21:10 by wlin              #+#    #+#             */
/*   Updated: 2017/08/19 14:16:35 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// first argument has to define the number of ants
// the amounts of ants cannot be negative and must fit in an int
int is_ant(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			++i;
		else
			return (0);
	}
	return (1);
}

int	is_comment(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (i == 0 && line[i] == '#')
			++i;
		else if (ft_isprint(line[i]) && line[i] != '#')
			++i;
		else
			return (0);
	}
	return (1);
}

int is_mod(char *line)
{
	if (!ft_strcmp(line, "##start"))
		return (1);
	else if (!ft_strcmp(line, "##end"))
		return (-1);
	else
		return (0);
}

char **is_room(char *line)
{
	int i;
	int j;
	char **room_def;

	i = 0;
	room_def = ft_strsplit(line, ' ');
	while (room_def[i])
	{
		j = 0;
		while (room_def[i][j] && i == 0)
		{
			if (!ft_isalnum(room_def[i][j]))
				return (NULL);
			++j;
		}
		while (room_def[i][j] && (i == 1 || i == 2))
		{
			if (!ft_isdigit(room_def[i][j]))
				return (NULL);
			++j;
		}
		++i;
	}
	return (i == 3 ? room_def : NULL);
}

int is_link(char *line, t_room *head)
{
	int i;
	char **link_def;

	i = 0;
	link_def = ft_strsplit(line, '-');
	while (link_def[i])
	{
		if (get_room(link_def[i], head))
			++i;
		else
			return (0);
	}
	//free link_def
	return (i == 2 ? 1 : 0);
}

// error check and parse input into data structure
int parse_map(int fd, t_antfarm *farm)
{
	int mod;
	char *line;
	char **room_def;

	while (get_next_line(fd, &line) > 0)
	{
		if (is_ant(line) && farm->colony == NULL)
			farm->colony = (t_ant*)malloc(sizeof(t_ant) * ft_atoi(line));
		else if (is_comment(line))
			;
		else if ((mod = is_mod(line)) != 0)
			;
		else if ((room_def = is_room(line)))
			add_room(room_def, mod, &(farm->rms));
		else if (is_link(line, farm->rms))
			setup_links(line, farm->rms);
		else
			return (0);
		ft_strdel(&line);
	}
	print_antfarm(farm);
	return (1);
}