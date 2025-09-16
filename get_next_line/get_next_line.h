/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:51:59 by alda-sil          #+#    #+#             */
/*   Updated: 2025/09/15 20:39:22 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif
# include <stdlib.h>
# include <unistd.h>

char	*ftt_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ftt_strdup(char *s);

#endif
