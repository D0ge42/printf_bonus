#include "ft_printf.h"

void	ft_putstr_count(void *str2, int *count, t_format *new, int len)
{

	int		i;
	char	*str;
	i = 0;
	str = (char *)str2;
	if (len == 6 && !str)
	{
		if (new->precision > 0 && new->precision < 6)
			return ;
		ft_putstr("(null)");
		*count += 6;
		return ;
	}
	if(new->precision && new->precision != -1)
	{
		while((new->precision) && str[i])
		{
			ft_putchar_count(str[i++],count);
			new->precision--;
		}
	}
	else
	{
		while(str[i])
		{
			ft_putchar_count(str[i++],count);
		}
	}
}
