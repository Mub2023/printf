#include "main.h"
/**
 * get_precision - calculates the precision for printing
 * @format: formatted string in which to print the arguments
 * @i:list of arguments to printed
 * @list: list of list argument
 * Return: precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	int x = *i + 1;
	int p = -1;

	if (format[x] != '.')
		return (p);

	p = 0;

	for (x += 1; format[x] != '\0'; x++)
	{
		if (is_digit(format[x]))
		{
			p *= 10;
			p += format[x] - '0';
		}

	else if (format[x] == '*')
	{
		x++;
		p = va_arg(list, int);
		break;
	}
	else
		break;
	}
	*i = x - 1;
	return (p);
}
