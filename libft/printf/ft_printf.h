/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:09:07 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/14 16:36:46 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# include "../libft.h"

typedef struct	s_ft_printf
{
	int			printed;
	int			i;
	const char	*string;
	va_list		arguments;
	int			ladjust;
	int			zero;
	int			plus;
	int			space;
	int			sign;
	int			hash;
	int			prefix;
	int			hex_zero;
	int			width;
	int			precision;
	int			negative;
}				t_ft_printf;

int				ft_printf(const char *string, ...);
void			ft_printf_putchar(t_ft_printf *print_s, char c);
void			ft_printf_putstr(t_ft_printf *print_s, char *s);
void			ft_printf_conversion(t_ft_printf *print_s);
void			ft_printf_conversion_char(t_ft_printf *print_s);
void			ft_printf_conversion_percent(t_ft_printf *print_s);
char			*ft_printf_conversion_string(t_ft_printf *print_s);
char			*ft_printf_conversion_decimal(t_ft_printf *print_s);
char			*ft_printf_conversion_unsigned(t_ft_printf *print_s);
char			*ft_printf_conversion_hex(t_ft_printf *print_s);
char			*ft_printf_conversion_pointer(t_ft_printf *print_s);
void			ft_printf_conversion_n(t_ft_printf *print_s);
void			ft_printf_width(t_ft_printf *print_s);
void			ft_printf_width_asterics(t_ft_printf *print_s);
void			ft_printf_precision(t_ft_printf *print_s);
char			*ft_printf_precision_numbers(t_ft_printf *print_s, char *str);
void			ft_printf_flag_minus(t_ft_printf *print_s);
void			ft_printf_flag_zero(t_ft_printf *print_s);
void			ft_printf_flag_plus(t_ft_printf *print_s);
void			ft_printf_flag_space(t_ft_printf *print_s);
void			ft_printf_flag_hash(t_ft_printf *print_s);
void			ft_printf_output(t_ft_printf *print_s, char *str);

#endif
