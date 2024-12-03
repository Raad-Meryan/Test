/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:39:47 by rmeryan           #+#    #+#             */
/*   Updated: 2024/12/03 10:39:48 by rmeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // For Variadic Stuff
# include <stdio.h>
# include <stdlib.h> // For malloc, free
# include <unistd.h> // For write

# define BUFFER_SIZE 4096 // 4096, the (1<<12) means 2^12, which is 4096

typedef unsigned char	t_byte;

# define FLAGS "-+ 0#"
# define NUMBERS "0123456789"
# define SPECIFIERS "cspdiuxX%"

# define RST "\033[0m"
# define O "\033[1;33m" // BOLD Yellow
# define R "\033[1;31m" // BOLD Red
# define G "\033[1;32m" // BOLD Green
# define Y "\033[1;33m" // BOLD Yellow
# define B "\033[1;34m" // BOLD Blue
# define M "\033[1;35m" // BOLD Magenta

typedef enum t_base
{
	BASE_2 = 2,
	BASE_8 = 8,
	BASE_10 = 10,
	BASE_16 = 16
}	t_base;

typedef struct s_flags
{
	int		left_justified;// 0 = right justified, 1 = left justified,
	int		plus;
	int		zero_pad;// 0 = no zero padding, 1 = zero padding
	int		space;
	int		hash;
	char	specifier; // c, s, p, d, i, u, x, X, %, n
	int		width;// The width of the field
	int		precision; // The precision of the field
	int		uppercase;
	t_base	base; // The base of the number
	int		padding; // The padding of the number
}	t_flags;
	// This struct will hold all the flags that we need to keep track of

typedef struct s_data
{
	// pointer copy to format string
	const char	*s;
	// va_list -> va_arg(args_pointer, type)
	va_list		args_pointer; // va_list to hold the arguments,
		//and this to fetch the following variable
	// chars written
	int			chars_written;
	// Buffer, 4k bools
	char		*buffer;// This will hold the buffer
	int			buffer_index; // This will hold the index of the buffer
	//[+-' '0#][width][.precision][specifier]
	t_flags		flags;
}	t_data;

int				ft_printf(const char *format, ...);

void			ft_memset(void *s, t_byte c, size_t n);
int				in(const char *s, char c);
int				ft_atoi(t_data *data);
int				str_len(char *str);

int				parse_format(t_data *data);

void			flush_buff(t_data *data);
void			write_buff(t_data *data, char c);
void			putchar_buff_n(char c, int precision, t_data *data);
void			putstr_buff_n(char *str, int precision, t_data *data);

void			print_char(t_data *data, int c);

void			print_str(t_data *data, char *str);

void			base_convert(unsigned long num, int base, int uppercase,
					char *buffer);
void			print_num(t_data *data, long num, int is_signed);
void			print_signed(t_data *data);
void			print_unsigned(t_data *data);
void			print_hex(t_data *data, int uppercase);
void			print_pointer(t_data *data);
// void			output_number(t_data *data, char *buffer,
// 					int prefix_len);
// void			handle_padding(t_data *data, int len, int content,
// 					char pad_char);
// unsigned long	calc_abs_value(long num, int is_signed);
char			*ft_itoa(int n);
#endif
