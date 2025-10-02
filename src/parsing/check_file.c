/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:23:54 by alda-sil          #+#    #+#             */
/*   Updated: 2025/10/01 20:44:27 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	format_map(char *map)
{
	char	*search_dot;
	int		result;

	search_dot = ft_strrchr(map, '.');
	if (!search_dot)
	{
		ft_error("format invalid");
		return(EXIT_FAILURE);
	}
	result = ft_strcmp(search_dot, ".cub");
	if (result != 0)
	{
		ft_error("format invalid");
		return(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_file_path(int argc, char **argv)
{	
	if (argc != 2)
		return (EXIT_FAILURE);
	if (format_map(argv[1]))
		return (EXIT_FAILURE);
}