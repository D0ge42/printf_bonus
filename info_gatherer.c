#include "ft_printf.h"

int	get_width(const char *format)
{
	char	width[11];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (format[i] == '%')
	{
		i++;
		while (is_flag(format[i]) && format[i])
			i++;
		while (is_digit(format[i]) && format[i])
			width[j++] = format[i++];
	}
	width[j] = '\0';
	return (ft_atoi(width));
}

int	get_precision(const char *format)
{
	int		i;
	int		j;
	char	precision[11];
	int		k;

	k = 0;
	i = 0;
	j = 0;
	if (format[i] == '%')
		i++;
	while (is_flag(format[i]) && format[i] && format[i] != '%')
		i++;
	while (format[i] != '.' && format[i] && format[i] != '%')
		i++;
	if (format[i] == '.')
	{
		k = i++;
		while (is_digit(format[i]) && format[i] && format[i] != '%')
			precision[j++] = format[i++];
	}
	precision[j] = '\0';
	if (format[k] == '.' && ft_strlen(precision) == 0)
		return (-1);
	return (ft_atoi(precision));
}

void	get_conversion(const char *format, t_format *new)
{
	int	i;

	i = 0;
	if (format[i] == '%')
		i++;
	while (is_flag(format[i]) && format[i] && format[i] != '%')
		i++;
	while ((format[i] && format[i] == '.' && format[i] != '%')
		|| (is_digit(format[i])))
		i++;
	if (is_conversion(format[i]))
		new->conversion = format[i];
}

void	get_flags(t_format *new, const char *format)
{
	int	i;

	i = 0;
	if (format[i] == '%')
		i++;
	while (is_flag(format[i]) && format[i] && format[i] != '%')
	{
		if (format[i] == '-')
			new->minus = 1;
		if (format[i] == '+')
			new->plus = 1;
		if (format[i] == '#')
			new->hashtag = 1;
		if (format[i] == ' ')
			new->space = 1;
		if (format[i] == '0')
			new->zero = 1;
		i++;
	}
}
