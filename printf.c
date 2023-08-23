#include "main.h"

/**
 * _printf- function that print output according to the format
 * @format: variable handdler
 * @...: number of parameter
 *
 * Return: number of character
 */
int _printf(const char *format, ...)
{
	int i = 0;
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				write(STDOUT_FILENO, "%", 1); i++;
			}
			else if (*format == 'c')
			{
				int ch = va_arg(args, int);

				write(STDOUT_FILENO, &ch, 1); i++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				int len = strlen(str);

				write(STDOUT_FILENO, str, len); i += len;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int x = va_arg(args, int);
				char str[32];
				int len = sprintf(str, "%d", x);

				write(STDOUT_FILENO, str, len); i += len;
			}
		}
		else
		{
			write(STDOUT_FILENO, format, 1); i++;
		}
		format++;
	}
	va_end(args); return (i);
}
