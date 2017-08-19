/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:54:29 by wlin              #+#    #+#             */
/*   Updated: 2017/08/18 12:48:18 by wlin             ###   ########.fr       */
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
		else if (ft_isprint(linep[i]) && line[i] != '#')
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

	len = 0;
	room_def = ft_strsplit(line, ' ');
	while (room[i])
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

int is_link(char *line)
{
	
}
// error check and parse input into data structure
int parse_input(char *filename, t_antfarm *farm)
{
	int fd;
	int mod;
	char *line;
	char **room_def;


	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > -1)
	{
		//ant def
		if (is_ant(line) && farm->colony = NULL)
			farm->colony = (t_ant)malloc(sizeof(t_ant) * ft_atoi(line));
		//comment def
	 	else if (is_comment(line))
			;
		//mod def
		else if ((mod = is_mod(line)) != 0)
			;
		//room def
		else if (room_def == is_room(line))
			add_room(room_def, mod, farm->rms);
		else if ()
		//link def
	}
}


int main(int argc, char **argv)
{
	t_antfarm antFarm;

	if (argc != 2)
		return (printf("Error\n");

}
