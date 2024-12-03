/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printingNum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:40:00 by rmeryan           #+#    #+#             */
/*   Updated: 2024/12/03 10:40:01 by rmeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa_base(unsigned int n, char *base)
{
	char			*str;
	unsigned int	base_len;
	unsigned int	temp;
	int				digits;

	base_len = str_len(base);
	digits = 0;
	temp = n;
	if (n == 0)
		digits = 1;
	while (temp != 0)
	{
		temp = temp / base_len;
		digits++;
	}
	str = malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	str[digits] = '\0';
	while (digits > 0)
	{
		str[--digits] = base[n % base_len];
		n = n / base_len;
	}
	return (str);
}

void	print_hex(t_data *data, int uppercase)
{
	unsigned int	value;
	char			*str;
	char			*base;

	value = va_arg(data->args_pointer, unsigned int);
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	str = ft_uitoa_base(value, base);
	if (!str)
		return (0);
	print_str(data, str);
	free(str);
}

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_luitoa_base(unsigned long n, char *base)
{
	char			*str;
	unsigned int	base_len;
	unsigned long	temp;
	int				digits;

	base_len = str_len(base);
	digits = 0;
	temp = n;
	if (n == 0)
		digits = 1;
	while (temp != 0)
	{
		temp = temp / base_len;
		digits++;
	}
	str = malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	str[digits] = '\0';
	while (digits > 0)
	{
		str[--digits] = base[n % base_len];
		n = n / base_len;
	}
	return (str);
}

void	print_pointer(t_data *data)
{
	unsigned long	value;
	char			*str;
	char			*temp_str;

	value = (unsigned long)va_arg(data->args_pointer, void *);
	if (value == 0)
	{
		print_str(data, "(nil)");
		return ;
	}
	str = ft_luitoa_base(value, "0123456789abcdef");
	if (!str)
		return ;
	temp_str = malloc(str_len(str) + 3);
	if (!temp_str)
	{
		free(str);
		return ;
	}
	temp_str[0] = '0';
	temp_str[1] = 'x';
	ft_strcpy(&temp_str[2], str);
	print_str(data, temp_str);
	free(str);
	free(temp_str);
}
