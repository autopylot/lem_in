/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:54:29 by wlin              #+#    #+#             */
/*   Updated: 2017/08/24 14:48:36 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int main(int argc, char **argv)
{
	t_antfarm antFarm;

	init_farm(&antFarm);
	if (argc > 1 || !parse_map(&antFarm))
	{
		puts("Error");
		return (1);
	}
	init_start(&antFarm);
	set_dist(&antFarm);
	migrate_colony(&antFarm);
	print_antfarm(&antFarm);
	return (0);
}
