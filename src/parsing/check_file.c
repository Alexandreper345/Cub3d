/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:23:54 by alda-sil          #+#    #+#             */
/*   Updated: 2025/12/18 21:28:09 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	format_map(char *map)
{
	char	*search_dot;
	int		result;

	search_dot = ft_strrchr(map, '.');
	if (!search_dot)
		return(ft_error("format invalid"));
	result = ft_strcmp(search_dot, ".cub");
	if (result != 0)
		return (ft_error("format invalid"));
	return (EXIT_SUCCESS);
}

int	check_file_path(int argc, char **argv)
{	
	if (argc != 2)
		return (EXIT_FAILURE);
	if (format_map(argv[1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_number(const char *s)
{
	int	i;

	if (!s || !*s)
		return (EXIT_FAILURE);
	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

char	*switch_newline(char *rgb)
{
	int	i;

	i = 0;
	while(rgb[i])
	{
		if (rgb[i] == '\n')
		{
			rgb[i] = '\0';
			break;
		}
		i++;
	}
	return (rgb);
}
