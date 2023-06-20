#include "libs.h"
/**
 * _print_int - prints an integer
 * @num: integer to print
 *@fd:file descriptor
 * Return: number of characters printed
 */
int _print_int(int fd, int num)
{
	int ncp = 0;

	if (num < 0)
	{
		_putchar(fd, '-');
		ncp++;
		num = -num;
	}

	ncp += _print_unsigned_int(fd, num);

	return (ncp);
}

/**
 * _print_unsigned_int - prints an unsigned integer
 * @num: unsigned integer to print
 *@fd:file descriptor
 * Return: number of characters printed
 */
int _print_unsigned_int(int fd, unsigned int num)
{
	int ncp = 0;

	if (num / 10)
	{
		ncp += _print_unsigned_int(fd, num / 10);
	}

	_putchar(fd, (num % 10) + '0');
	ncp++;

	return (ncp);
}


/**
 * _print_string - Prints a string from a variable argument list
 * @s: argument
 * @fd:file descriptor
 * Return: the length of the string.
 */

int _print_string(int fd, char *s)
{
	int len;

	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	len = _strlen(s);
	write(fd, s, len);
	return (len);
}


/**
 * check - checks for format specifiers
 * @mym: argument list
 * @ncp: number of characters printed
 * @format: format string
 * @fd:file descriptor
 *
 * Return: number of characters printed
 */
int check(int fd, va_list mym, int ncp, const char *format)
{

	if (*format == 'c')
	{
		char c = va_arg(mym, int);

		_putchar(fd, c);
		ncp++;
	}
	else if (*format == 's')
	{
		char *str = va_arg(mym, char *);

		if (str == NULL)
		{
			str = "(null)";
		}
			ncp += _print_string(fd, str);
	}
	else if (*format == '%')
	{
		_putchar(fd, '%');
		ncp++;
	}
	else if (*format == 'd' || *format == 'i')
	{
		int num = va_arg(mym, int);

		ncp += _print_int(fd, num);
	}
	else
	{
		_putchar (fd, '%');
		ncp++;
		_putchar(fd, *format);
		ncp++;
	}
	return (ncp);
}

/**
 * _printf - prints formatted output
 * @format: format string
 * @fd:file descriptor
 * Return: number of characters printed
 */
int _printf(int fd, const char *format, ...)
{
	va_list mym;
	int ncp = 0;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	else if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	else if (format == NULL)
		return (-1);
	va_start(mym, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			while (*format == ' ')
			{
				format++;
			}
		ncp = check(fd, mym, ncp, format);
		}
		else
			{
			_putchar(fd, *format);
			ncp++;
			}
		format++;
	va_end(mym);
	}
	return (ncp);
}

