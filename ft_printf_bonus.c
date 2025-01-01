#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			j;
	int			i;
	int			count;
	va_list		args;
	t_format	**struct_array;

	j = 0;
	i = 0;
	count = 0;
	struct_array = create_struct_array(format);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			struct_to_string(struct_array[j], args, &count);
			jump_index(format, &i); // Skip to next % or end.
			j++;
		}
		else if (format[i])
		{
			ft_putchar_count(format[i], &count);
			i++;
		}
	}
	va_end(args);
	return (count);
}
