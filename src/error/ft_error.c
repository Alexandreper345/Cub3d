/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:50:14 by alda-sil          #+#    #+#             */
/*   Updated: 2026/01/13 21:59:05 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	return_failure(char **matriz, char *temp, char *str)
{
	if (matriz != NULL || matriz)
		free_matriz(matriz);
	if (temp != NULL || temp)
		free(temp);
	if (str)
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
