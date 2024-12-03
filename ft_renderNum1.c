#include "ft_printf.h"

void	print_signed(t_data *data)
{
	int		val;
	char	*num;

	val = va_arg(data->args_pointer, int);
	num = ft_itoa(val);
	if (!num)
		return (0);
	print_str(data, num);
	free(num);
}

char	*ft_uitoa(unsigned int n)
{
	char			*str;
	int				digits;
	unsigned int	temp;

	digits = 0;
	temp = n;
	if (n == 0)
		digits = 1;
	while (temp != 0)
	{
		temp = temp / 10;
		digits++;
	}
	str = malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	str[digits] = '\0';
	while (digits > 0)
	{
		str[--digits] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

void	print_unsigned(t_data *data)
{
	unsigned int	value;
	char			*str;

	value = va_arg(data->args_pointer, unsigned int);
	str = ft_uitoa(value);
	if (!str)
		return ;
	print_str(data, str);
	free(str);
}
