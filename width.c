#include "main.h"
/**
 * get_width - calculates the width for printing
 * @format: formatted string in which to print the arguments
 * @i: list of argument to be printed
 * @list: list of arguments
 * Return: the width
 */
int get_width(const char *format, int *i, va_list list)
{
	int x, width = 0;

	for (x = *i + 1; format[x] != '\0'; x++)
	{
		if (is_digit(format[x]))
		{
			width *= 10;
			width += format[x] - '0';
		}
		else if (format[x] == '*')
		{
			x++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = x - 1;
	return (width);
}
