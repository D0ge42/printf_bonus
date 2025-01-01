#include "ft_printf.h"

void	ft_putstr_count(void *str2, int *count, int precision, int len)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)str2;
	if (len == 6 && !str)
	{
		if (precision < 6)
			return ;
		ft_putstr("(null)");
		*count += 6;
		return ;
	}
	if (precision)
	{
		while (i < precision && str[i])
		{
			write(1, &str[i], 1);
			*count += 1;
			i++;
		}
	}
	else
		while (str[i])
		{
			write(1, &str[i], 1);
			*count += 1;
			i++;
		}
}
