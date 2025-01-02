#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*Takes format string and makes a structure out of it,
	with all the relative infos.*/

t_format	*create_struct(const char *format)
{
	t_format	*new;

	new = (t_format *)malloc(sizeof(t_format));
	initialize_struct(new);
	new->width = get_width(format);
	new->precision = get_precision(format);
	get_flags(new, format);
	get_conversion(format, new);
	return (new);
}

/*Creates a struct array out of a format string. Each % is a structure.*/

t_format	**create_struct_array(const char *format)
{
	int			struct_count;
	int			n_struct;
	int			i;
	t_format	**struct_array;

	i = 0;
	n_struct = 0;
	struct_count = 0;
	struct_count = perc_counter('%', format);
	struct_array = (t_format **)malloc(sizeof(t_format *) * struct_count);
	while (format[i])
	{
		if (format[i] == '%')
		{
			struct_array[n_struct] = create_struct(&(format[i]));
			jump_index(format, &i);
			n_struct++;
		}
		else
			i++;
	}
	return (struct_array);
}
