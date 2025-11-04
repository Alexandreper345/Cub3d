/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:52:46 by alda-sil          #+#    #+#             */
/*   Updated: 2025/10/22 21:57:05 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	insert_value_texture(char *line, t_map *map)
{
	char **split;

	split = ft_split(line, ' ');
	if (!split || !split[0] || !split[1])
	{
		//free split not create
		ft_error("split texture failed");
		return (EXIT_FAILURE);
	}
	if (ft_strcmp(split[0], "NO") == 0)
		map->NO_path = split[1];
	if (ft_strcmp(split[0], "SO") == 0)
		map->SO_path = split[1];
	if (ft_strcmp(split[0], "WE") == 0)
		map->WE_path = split[1];
	if (ft_strcmp(split[0], "EA") == 0)
		map->EA_path = split[1];
	//free split not create
	return (EXIT_SUCCESS);
}

static int	format_map(char *line, t_map *map)
{
	char	*search_dot;																	
	int		result;

	search_dot = ft_strrchr(line, '.');
	if (!search_dot)
	{
		ft_error("format invalid");
		return(EXIT_FAILURE);
	}
	result = ft_strcmp(search_dot, ".xpm");
	if (result != 0)
	{
		ft_error("format texture invalid");
		return(EXIT_FAILURE);
	}
	insert_value_texture(line);
	return (EXIT_SUCCESS);
}

int	get_path_text(t_map *map)
{
	char    *line;
	int		i;

	i = 0;
	while(map->matriz[i])
	{
		line = map->matriz[i];
		if (ft_strcmp(line, "NO") == 0 || ft_strcmp(line, "SO") == 0 ||
			ft_strcmp(line, "WE") == 0 || ft_strcmp(line, "EA") == 0)
			if (format_texture(line, map))
				return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}


/*

void	insert_value_texture(char *line, t_map *map)
{
	char **split;

	split = ft_split(line, ' '); // separa ["NO", "./path/to/file.xpm"]
	if (!split || !split[0] || !split[1])
	{
		ft_error("invalid texture line");
		return ;
	}
	if (ft_strcmp(split[0], "NO") == 0)
		map->NO_path = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "SO") == 0)
		map->SO_path = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "WE") == 0)
		map->WE_path = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "EA") == 0)
		map->EA_path = ft_strdup(split[1]);

	free_split(split); // libera o split
}

E no format_map (que você chamou de format_texture no get_path_text):

static int	format_texture(char *line, t_map *map)
{
	char	*search_dot;
	char	**split;

	split = ft_split(line, ' ');
	if (!split || !split[1])
	{
		ft_error("missing texture path");
		return (EXIT_FAILURE);
	}

	search_dot = ft_strrchr(split[1], '.');
	if (!search_dot || ft_strcmp(search_dot, ".xpm") != 0)
	{
		ft_error("invalid texture format");
		free_split(split);
		return (EXIT_FAILURE);
	}

	insert_value_texture(line, map);
	free_split(split);
	return (EXIT_SUCCESS);
}







*/
