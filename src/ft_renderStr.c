/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderStr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:40:49 by rmeryan           #+#    #+#             */
/*   Updated: 2024/12/03 10:40:49 by rmeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	padding(t_data *data, char *str)
{
	int	len;

	len = str_len(str);
	if (data->flags.width > 0)
	{
		if (data->flags.precision >= 0)
		{
			if (data->flags.precision > len)
				data->flags.padding = data->flags.width - len;
			else if (data->flags.precision < len)
				data->flags.padding = data->flags.width - data->flags.precision;
		}
		else
			data->flags.padding = data->flags.width - len;
	}
}

static void	put_str(t_data *data, char *str)
{
	if (data->flags.precision >= 0)
		putstr_buff_n(str, data->flags.precision, data);
	else
		putstr_buff_n(str, str_len(str), data);
}

void	print_str(t_data *data, char *str)
{
	if (str == NULL)
		str = "(null)";
	padding(data, str);
	if (data->flags.left_justified)
	{
		put_str(data, str);
		putchar_buff_n(' ', data->flags.padding, data);
	}
	else
	{
		putchar_buff_n(' ', data->flags.padding, data);
		put_str(data, str);
	}
}
