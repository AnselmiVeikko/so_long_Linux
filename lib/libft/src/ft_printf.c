/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:32:36 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/20 13:28:18 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(va_list args, const char form)
{
	int	len;

	len = 0;
	if (form == 'c')
		len = ft_printchar(va_arg(args, int));
	if (form == 's')
		len = ft_printstr(va_arg(args, char *));
	if (form == 'p')
		len = ft_printptr(va_arg(args, void *));
	if (form == 'd' || form == 'i')
		len = ft_printnbr(va_arg(args, int));
	if (form == 'u')
		len = ft_print_ui(va_arg(args, unsigned int));
	if (form == 'x' || form == 'X')
		len = ft_printhex(form, va_arg(args, unsigned long int));
	if (form == '%')
		len = ft_printper();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		printlen;
	int		lentotal;
	va_list	args;

	i = 0;
	lentotal = 0;
	printlen = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (!str[++i])
				break ;
			printlen = ft_convert(args, str[i++]);
		}
		else
			printlen = ft_printchar(str[i++]);
		if (printlen == -1)
			return (-1);
		lentotal = lentotal + printlen;
	}
	va_end(args);
	return (lentotal);
}
