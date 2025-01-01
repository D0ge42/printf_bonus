#include "ft_printf.h"

int	count_digits(long long num2, char format)
{
	int	num;
	int	count;

	if (format == 'i')
		num = (int)num2;
	else
		num = (unsigned long long)num2;
	count = 0;
	if (num == -2147483648)
		return (11);
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = -num;
		count += 1;
	}
	while (num > 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}

int	count_hex_digits(unsigned long long num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		count++;
		num /= 16;
	}
	return (count);
}

int	count_memory_address_length(void *ptr)
{
	uintptr_t	address;
	int			count;

	address = (uintptr_t)ptr;
	count = 0;
	if (address == 0)
		return (3);
	while (address > 0)
	{
		count++;
		address /= 16;
	}
	return (count + 2);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}