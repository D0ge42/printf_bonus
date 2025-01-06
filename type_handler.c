#include "ft_printf.h"

void	struct_to_string(t_format *new, va_list args, int *count)
{
	if (new->conversion == 's')
		string_handler(new, args, count);
	if (new->conversion == 'c')
		char_handler(new, args, count);
	if (new->conversion == 'i' || new->conversion == 'd')
		int_handler(new, args, count);
	if (new->conversion == 'u')
		uint_handler(new, args, count);
	if (new->conversion == 'X' || new->conversion == 'x')
		hexa_handler(new, args, count);
	if (new->conversion == 'p')
		p_handler(new, args, count);
	if (new->conversion == '%')
		ft_putchar_count('%', count);
}
