/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:35:17 by matde-ol          #+#    #+#             */
/*   Updated: 2023/11/20 18:12:19 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_security(char *reste, char *dest);
char	*ft_strjoin_f(char *s1, char *s2);
char	*ft_loop_buffer(int fd);
char	*get_next_line(int fd);
char	*ft_strlcpy_f(char *src, int len);
char	*ft_substr(char *src, int start, int len);
int		ft_strlen(char *src);
int		ft_strchr_bis(char *src);
#endif
