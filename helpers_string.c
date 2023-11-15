#include "shell.h"

/**
 * str_length - Computes the length of a string.
 * @str: Pointer to the string.
 * Return: Length of the string.
 */
int str_length(char *str)
{
	int length = 0;

	if (str == NULL)
		return (0);

	while (str[length++] != '\0')
	{
	}
	return (--length);
}

/**
 * str_duplicate - Creates a copy of the given string.
 * @str: The string to be duplicated.
 * Return: A pointer to the duplicated string.
 */
char *str_duplicate(char *str)
{
	char *result;
	int length, i;

	if (str == NULL)
		return (NULL);

	length = str_length(str) + 1;

	result = malloc(sizeof(char) * length);

	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (i = 0; i < length ; i++)
	{
		result[i] = str[i];
	}

	return (result);
}

/**
 * str_compare - Compares two strings.
 * @str1: The first string, assumed to be the shorter one.
 * @str2: The second string, assumed to be the longer one.
 * @number: Number of characters to compare (0 for an infinite comparison).
 * Return: 1 if the strings are equal, 0 if they differ.
 */
int str_compare(char *str1, char *str2, int number)
{
	int iterator;

	if (str1 == NULL && str2 == NULL)
		return (1);

	if (str1 == NULL || str2 == NULL)
		return (0);

	if (number == 0) /* infinite longitud */
	{
		if (str_length(str1) != str_length(str2))
			return (0);
		for (iterator = 0; str1[iterator]; iterator++)
		{
			if (str1[iterator] != str2[iterator])
				return (0);
		}
		return (1);
	}
	else /* if there is a number of chars to be compared */
	{
		for (iterator = 0; iterator < number ; iterator++)
		{
			if (str1[iterator] != str2[iterator])
			return (0);
		}
		return (1);
	}
}

/**
 * str_concat - Combines two strings.
 * @str1: String to be combined.
 * @str2: String to be combined.
 *
 * Return: Pointer to the resulting array.
 */
char *str_concat(char *str1, char *str2)
{
	char *result;
	int length1 = 0, length2 = 0;

	if (str1 == NULL)
		str1 = "";
	length1 = str_length(str1);

	if (str2 == NULL)
		str2 = "";
	length2 = str_length(str2);

	result = malloc(sizeof(char) * (length1 + length2 + 1));
	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	/* copy of str1 */
	for (length1 = 0; str1[length1] != '\0'; length1++)
		result[length1] = str1[length1];
	free(str1);

	/* copy of str2 */
	for (length2 = 0; str2[length2] != '\0'; length2++)
	{
		result[length1] = str2[length2];
		length1++;
	}

	result[length1] = '\0';
	return (result);
}


/**
 * str_reverse - Inverts the order of characters in a string.
 *
 * @str: Pointer to the string.
 * Return: Void.
 */
void str_reverse(char *str)
{

	int i = 0, length = str_length(str) - 1;
	char hold;

	while (i < length)
	{
		hold = str[i];
		str[i++] = str[length];
		str[length--] = hold;
	}
}
