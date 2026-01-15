/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:50:14 by alda-sil          #+#    #+#             */
/*   Updated: 2026/01/14 22:03:36 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	return_failure(char **matriz, char *temp, char *str)
{
	if (matriz != NULL || matriz)
		free_matriz(matriz);
	if (temp != NULL || temp)
		free(temp);
	if (*str != '\0')
		ft_error(str);
	return (EXIT_FAILURE);
}

int	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	printf("\n");
	return (EXIT_FAILURE);
}

char	*ft_strtrim_cub(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	if (start == end)
		return (ft_strdup(""));
	end--;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}

int	ft_color_free(char **color)
{
	free_matriz(color);
	return (-1);
}
