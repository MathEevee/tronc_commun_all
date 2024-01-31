/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 03:18:45 by matde-ol          #+#    #+#             */
/*   Updated: 2023/11/19 15:34:12 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(unsigned char c);
int		ft_putstr(char *c);
int		ft_strlen(const char *s);
int		ft_putnbr(int nbr);
int		ft_putnbr_hexa(size_t nbr, char *base);
int		ft_put_u_nbr(unsigned int nbr);
int		ft_hexa_pointer(void *pt, char *base);
int		ft_printf(const char *format, ...);

#endif
