/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:38:56 by rmeryan           #+#    #+#             */
/*   Updated: 2024/12/03 10:38:57 by rmeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flush_buff(t_data *data)
{
	data->chars_written += write(STDOUT_FILENO, data->buffer,
			data->buffer_index);
	ft_memset(data->buffer, 0, BUFFER_SIZE);
	data->buffer_index = 0;
}

void	write_buff(t_data *data, char c)
{
	if (data->buffer_index == BUFFER_SIZE)
	{
		flush_buff(data);
	}
	data->buffer[data->buffer_index++] = c;
}

void	putchar_buff_n(char str, int precision, t_data *data)
{
	if (precision <= 0)
		return ;
	while (precision--)
		write_buff(data, str);
}

void	putstr_buff_n(char *str, int precision, t_data *data)
{
	if (precision <= 0)
		return ;
	while (precision-- && *str)
		write_buff(data, *str++);
}
