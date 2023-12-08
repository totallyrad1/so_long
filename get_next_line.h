/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:27:42 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/05 17:19:51 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>

char	*get_next_line(int fd);

char	*ft_substrgnl(char *s, size_t start, size_t len);
char	*ft_strjoingnl(char *s1, char *s2);
size_t	ft_strlengnl(char *s);
char	*ft_strdupgnl(char *s1);
int		newlineexistsgnl(char *s);

#endif