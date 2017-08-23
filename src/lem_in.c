/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:54:29 by wlin              #+#    #+#             */
/*   Updated: 2017/08/23 14:19:10 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// check if no rooms, ants, or links are defined
// check when no start/end is defined
// check when no path is possible
// check other commands
//check for links to rooms not defined
//check for duplicate links
int main(int argc, char **argv)
{
	int fd;
	t_antfarm antFarm;

	if (argc != 2)
	{
		puts("Error");
		// return (1);
	}
	init_farm(&antFarm);
	fd = open(argv[1], O_RDONLY);
	parse_map(fd, &antFarm);
	init_start(&antFarm);
	set_dist(&antFarm);
	migrate_colony(&antFarm);
	print_antfarm(&antFarm);
	return (0);
}
