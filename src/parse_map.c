/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:21:10 by wlin              #+#    #+#             */
/*   Updated: 2017/08/24 15:06:52 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void ft_arrdel(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(&(arr[i]));
		++i;
	}
	free(arr);
	arr = NULL;
}

int valid_ant(char *line, t_ant *colony)
{
	int i;

	i = -1;
	if (colony != NULL)
		return (0);
	while (line[++i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
	}
	return (atoi(line) > 0 ? 1 : 0);
}

int	valid_comment(char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (1);
	return (0);
}

// check other commands, unknown ignored
int valid_cmd(char *line)
{
	if (!ft_strcmp(line, "##start"))
		return (1);
	else if (!ft_strcmp(line, "##end"))
		return (2);
	else if (!ft_strncmp(line, "##", 2))
		return (3);
	else
		return (0);
}

// ERROR non complaint file, empty line
int parse_map(t_antfarm *farm)
{
	int		cmd;
	char	*line;

	cmd = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (valid_ant(line, farm->colony))
			init_colony(farm, line);
		else if (valid_room(line, farm->rms))
			add_room(line, farm, &cmd);
		else if (valid_link(line, farm->rms))
			setup_links(line, farm->rms);
		else if ((cmd = valid_cmd(line)) != 0 || valid_comment(line))
			;
		else
		{
			ft_strdel(&line);
			return (0);
		}
		ft_strdel(&line);
	}
	//check that everythin has been defined
	return (1);
}
