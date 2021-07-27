#include <stdlib.h>
#include "holberton.h"

/**
 * check_for_specs - checks for valid format specifiers
 * @format: format of specifiers
 *
 * Return: pointer to function or NULL
 */
static int (*check_for_specs(const char *format))(va_list)
{
	unsigned int i;
	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_d},
		{NULL, NULL}
	};

	for (i = 0; p[i].t != NULL; i++)
	{
		if (*(p[i].t) == *format)
		{
			break;
		}
	}
	return (p[i].f);
}

/**
 * print_f - prints everything
 * @format: list of arguments
 *
 * Return: number of characters passed
 */
int _printf(const char *format, ...)
