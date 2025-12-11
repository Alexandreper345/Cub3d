/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recreate_matriz.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 02:30:14 by erick             #+#    #+#             */
/*   Updated: 2025/12/11 20:37:44 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int check_is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' '  || line[i] == '\n'))
	{
		i++;
	}
	if (line[i] == '1' || line[i] == '0') // not sure if this will work
		return(0);
	return(1);
	
}

char *start_line(int fd)
{
    char *line;
    
    line = get_next_line(fd);
    while (line != NULL)
    {
        if (check_is_map_line(line) == 0)
        {
            free(line);
            return (line);
        }
        free(line);
		line = get_next_line(fd);
    }
    return(NULL) ;
}

int find_height(char *path)
{
    int		fd;
    int     height;
    char    *line;

    fd = 0;
    height = 0;
	open()
    if (!fd)
		return ; 
    line = start_line(fd);
    while (line != NULL && check_is_map_line(line) == 0)
    {
        free(line);
        line = get_next_line(fd);
        height++;
    }
    return (height);
}

int recreate_matriz(t_vars *vars, char *path)  // need to free oldmatriz
{
	int		index;
	int		fd;
    int     height;
	size_t	max;
	char	*line;
	
	index = 0;
	max = 0;
	fd = open(path, O_RDWR);
	if (!fd)
		return 1; 
    free_matriz(vars->map->matriz);
    height = find_height(path);
    vars->map->matriz = (char **)malloc(sizeof(char *) * (height + 1));
    if (vars->map->matriz != NULL)
        return (1);
    line = start_line(fd);
	if (line && check_is_map_line(line) == 0)
		max = ft_strlen(line);
	while (line != NULL)
	{
		if (check_is_map_line(line) == 0)
			vars->map->matriz[index] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		if (line && ft_strlen(line) > max && check_is_map_line(line) == 0)
			max = ft_strlen(line);
		index++;
	}
	printf("aqui está width %d\n", (int)max);
	vars->map->width = (int)max;
	return (EXIT_SUCCESS);
}
