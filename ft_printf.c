/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:39:41 by rmeryan           #+#    #+#             */
/*   Updated: 2024/12/03 10:39:42 by rmeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	render_format(t_data *data)
{
	char	specifier;

	specifier = data->flags.specifier;
	if (specifier == '%')
		print_char(data, '%');
	else if (specifier == 'c')
		print_char(data, va_arg(data->args_pointer, int));
	else if (specifier == 's')
		print_str(data, va_arg(data->args_pointer, char *));
	else if (specifier == 'd' || specifier == 'i')
		print_signed(data);
	else if (specifier == 'u')
		print_unsigned(data);
	else if (specifier == 'x')
		print_hex(data, 0);
	else if (specifier == 'X')
		print_hex(data, 1);
	else if (specifier == 'p')
		print_pointer(data);
}

static int	init_data(t_data *data, const char *format)
{
	data->s = format;
	data->chars_written = 0;
	data->buffer = (char *)malloc(BUFFER_SIZE);
	if (!data->buffer)
		return (-1);
	data->buffer_index = 0;
	ft_memset(data->buffer, 0, BUFFER_SIZE * sizeof(char));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_data	data;

	va_start(data.args_pointer, format);
	if (init_data(&data, format))
		return (-1);
	while (*data.s)
	{
		if (*data.s == '%' && *(++data.s))
		{
			if (parse_format(&data))
				return (-1);
			render_format(&data);
		}
		else
			write_buff(&data, *data.s);
		data.s++;
	}
	flush_buff(&data);
	va_end(data.args_pointer);
	free(data.buffer);
	return (data.chars_written);
}
