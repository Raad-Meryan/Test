/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:40:57 by rmeryan           #+#    #+#             */
/*   Updated: 2024/12/03 10:40:58 by rmeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	parse_flags(t_data *data)
{
	char	flag;

	while (in (FLAGS, *data->s))
	{
		flag = *data->s;
		if (flag == '-')
			data->flags.left_justified = 1;
		else if (flag == '0')
			data->flags.zero_pad = 1;
		else if (flag == '#')
			data->flags.hash = 1;
		else if (flag == ' ')
			data->flags.space = 1;
		else if (flag == '+')
			data->flags.plus = 1;
		data->s++;
	}
}

static	void	parse_width(t_data *data)
{
	if (*data->s == '*')
	{
		data->flags.width = va_arg(data->args_pointer, int);
		if (data->flags.width < 0)
		{
			data->flags.left_justified = 1;
			data->flags.width = -(data->flags.width);
		}
		data->s++;
	}
	else
		data->flags.width = ft_atoi(data);
}

static	void	parse_precision(t_data *data)
{
	if (*data->s == '.')
	{
		data->s++;
		if (*data->s == '*')
		{
			data->flags.precision = va_arg(data->args_pointer, int);
			if (data->flags.precision < 0)
				data->flags.precision = -1;
			data->s++;
		}
		else
			data->flags.precision = ft_atoi(data);
	}
	else
		data->flags.precision = -1;
}

static	int	set_specifier(t_data *data)
{
	if (!in(SPECIFIERS, *data->s))
		return (-1);
	data->flags.specifier = *data->s;
	if (in("diu", data->flags.specifier))
		data->flags.base = BASE_10;
	else if (in("xXp", data->flags.specifier))
	{
		data->flags.base = BASE_16;
		if ('X' == data->flags.specifier)
			data->flags.uppercase = 1;
	}
	return (0);
}

int	parse_format(t_data *data)
{
	ft_memset(&data->flags, 0, sizeof(t_flags));
	data->flags.precision = -1;
	parse_flags(data);
	parse_width(data);
	parse_precision(data);
	if (set_specifier(data))
		return (-1);
	if (data->flags.left_justified)
		data->flags.zero_pad = 0;
	if (data->flags.plus)
		data->flags.space = 0;
	return (0);
}
