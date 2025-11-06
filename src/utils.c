/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:23:12 by alda-sil          #+#    #+#             */
/*   Updated: 2025/11/05 21:27:29 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);	
}

int	get_height_map(char **matriz)
{
	int	i;

	i = 0;
	while (matriz[i])
		i++;
	return (i);
}

int	get_width_map(char **matriz)
{
	int	i;
	int	max;
	int	len;

	i = -1;
	max = 0;
	while (matriz[++i])
	{
		len = len(matriz[i]);
		if (len > max)
			max = len;
	}
	return (len);
}