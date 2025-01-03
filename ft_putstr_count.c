#include "ft_printf.h"

void	ft_putstr_count(void *str2, int *count, t_format *new, int len)
{
	int		i;
	char	*str;
	int precision = 0;
	i = 0;
	str = (char *)str2;
	precision = len - new->precision;
	if (len == 6 && !str)
	{
		if (new->precision > 0 && new->precision < 6)
			return ;
		ft_putstr("(null)");
		*count += 6;
		return ;
	}
	if(new->precision < len)
	{
		while(precision && str[i])
		{
			ft_putchar_count(str[i++],count);
			precision--;
		}
	}
	else
	{
		while(str[i])
		{
			ft_putchar_count(str[i],count);
			i++;
		}
	}
}