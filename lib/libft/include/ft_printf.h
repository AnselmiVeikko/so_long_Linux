/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:29:14 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/20 12:49:19 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printstr(char *str);
int		ft_printchar(int c);
int		ft_printnbr(int n);
int		ft_printper(void);
int		ft_print_ui(unsigned int n);
int		ft_printhex(const char form, unsigned int n);
int		ft_printptr(void *ptr);
int		ft_printf(const char *s, ...);
char	*ft_uitoa(unsigned int n);
char	*ft_hextoa(unsigned int n, char *str);

#endif
