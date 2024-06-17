/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melinamotylewski <melinamotylewski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:38:49 by memotyle          #+#    #+#             */
/*   Updated: 2024/06/16 18:02:51 by melinamotyl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_attributions(va_list argument, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = len + ft_putchar(va_arg(argument, int));
	if (c == 's')
		len = len + ft_putstr(va_arg(argument, char *));
	if (c == 'd' || c == 'i')
		len = len + ft_putnbr(va_arg(argument, int));
	if (c == 'u')
		len = len + ft_putunsi_dec(va_arg(argument, unsigned int));
	if (c == 'X')
		len = len + ft_putnbr_base("0123456789ABCDEF", va_arg(argument, int));
	if (c == 'x')
		len = len + ft_putnbr_base("0123456789abcdef", va_arg(argument, int));
	if (c == 'p')
		len = len + ft_putptr(va_arg(argument, void *), "0123456789abcdef", 0);
	if (c == '%')
		len = len + ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	argument;
	int		len_print;

	i = 0;
	len_print = 0;
	va_start(argument, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len_print = len_print + ft_attributions(argument, s[i + 1]);
			i++;
		}
		else
			len_print = len_print + ft_putchar(s[i]);
		i++;
	}
	va_end(argument);
	return (len_print);
}

/*
#include <stdio.h>
int	main()
{
	char	c = 'c';
	char	*str = "Hello you";
	char	*ptr = "po";
	int	i = -2147483648;
	int	imax = 2147483647;
	int zero = 0;
	unsigned int u = 285236;
	int	low = 4660;
	int	upp = 45698123;


	ft_printf("Print a char with MY function printf : %c\n", c);
	printf("Prints a char with Printf : %c\n", c);

	printf("--------------------------------------------------\n");

	ft_printf("Prints a string with MY function printf : %s\n", str);
	printf("Prints a string with Printf : %s\n", str);

	printf("\n\n");

	ft_printf("Prints a pointer with MY function printf : %p\n", ptr);
	printf("Prints a pointer with Printf : %p\n", ptr);

	printf("\n\n");

	ft_printf("Prints dec num with MY printf : %d %d %d\n", i, imax, zero);
	printf("Prints a dec number with Printf : %d %d %d\n", i, imax, zero);

	printf("\n\n");

	ft_printf("Prints int(base 10) with MY printf : %i %i %i\n", i, imax, zero);
	printf("Prints an integer(base 10) with Printf : %i %i %i\n", i, imax, zero);

	printf("\n\n");

	ft_printf("Prints an uns deci number with MY function printf : %u\n", u);
	printf("Prints an unsigned decimal number with Printf : %u\n", u);

	printf("\n\n");

	ft_printf("Prints a number in Hexa lowercase with MY printf : %x\n", low);
	printf("Prints a number in Hexa lowercase with Printf : %x\n", low);

	printf("\n\n");

	ft_printf("Prints a number in Hexa uppercase with MY printf : %X\n", upp);
	printf("Prints a number in Hexa uppercase with Printf : %X\n", upp);

	printf("\n\n");

	ft_printf("Prints a percent sign with MY printf : %%\n");
	printf("Prints a percent sign with Printf : %%\n");
	return (0);
}

*/
