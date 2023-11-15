#include "shell.h"

/**
 * long_to_string - Converts a numeric value to its string representation.
 * @number: The number to be converted into a string.
 * @str: The buffer to store the resulting string.
 * @base: The base for the conversion (e.g., 10 for decimal, 16 for hexadecimal).
 *
 * Return: Nothing.
 */
void long_to_string(long number, char *str, int base)
{
	int index = 0, inNegative = 0;
	long cociente = number;
	char letters[] = {"0123456789abcdef"};

	if (cociente == 0)
		str[index++] = '0';

	if (str[0] == '-')
		inNegative = 1;

	while (cociente)
	{
		if (cociente < 0)
			str[index++] = letters[-(cociente % base)];
		else
			str[index++] = letters[cociente % base];
		cociente /= base;
	}
	if (inNegative)
		str[index++] = '-';

	str[index] = '\0';
	str_reverse(str);
}


/**
 * atoi_custom - Converts a string to an integer.
 *
 * @s: Pointer to the original string.
 * Return: The integer value of the string or 0.
 */
int atoi_custom(char *s)
{
	int sign = 1;
	unsigned int number = 0;
	/*1- analisys sign*/
	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		if (*s == '+')
			sign *= +1;
		s++;
	}

	/*2 - extract the number */
	while ('0' <= *s && *s <= '9' && *s != '\0')
	{

		number = (number * 10) + (*s - '0');
		s++;
	}
	return (number * sign);
}

/**
 * count_characters - Determines the frequency of a specific character in a string.
 *
 * @str: Pointer to the original string.
 * @character: String containing the character to be counted.
 * Return: The count of occurrences.
 */
int count_characters(char *str, char *character)
{
	int i = 0, counter = 0;

	for (; str[i]; i++)
	{
		if (str[i] == character[0])
			counter++;
	}
	return (counter);
}
