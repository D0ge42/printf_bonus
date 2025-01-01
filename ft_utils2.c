#include "ft_printf_bonus.h"

int count_digits(long long num2,char format)
{
    int num;
    if(format == 'i')
        num = (int)num2;
    else
        num = (unsigned long long)num2;
    int count = 0;

    if (num == -2147483648)
        return 10;
    if (num == 0)
        return 1;
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
    return count;
}

int count_hex_digits(unsigned long long num)
{
    int count = 0;
    if (num == 0)
        return 1;
    while (num > 0)
    {
        count++;
        num /= 16;
    }
    return count;
}

int count_memory_address_length(void *ptr)
{
    uintptr_t address = (uintptr_t)ptr;
    int count = 0;
    if (address == 0)
        return 3;
    while (address > 0)
    {
        count++;
        address /= 16;
    }
    return count + 2;
}

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}