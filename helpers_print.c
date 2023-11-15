#include "shell.h"

/**
 * _print_str - Outputs an array of characters to the standard output.
 * @str: Pointer to the array of characters.
 * Return: The number of bytes written.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _print_str(char *str)
{
	return (write(STDOUT_FILENO, string, str_length(str)));
}
/**
 * _printe_str - Outputs an array of characters to the standard error.
 * @str: Pointer to the array of characters.
 * Return: The number of bytes written.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printe_str(char *str)
{
	return (write(STDERR_FILENO, str, str_length(str)));
}

/**
 * print_error - Outputs an error message to the standard error, based on the provided error code.
 * @error_code: The error code to print.
 * @data: Pointer to the program's data.
 * Return: The number of bytes written.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_error(int error_code, ProgramData *data)
{
	char n_as_string[10] = {'\0'};

	long_to_string((long) data->exec_counter, n_as_string, 10);

	if (error_code == 2 || error_code == 3)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->tokens[0]);
		if (error_code == 2)
			_printe(": Illegal number: ");
		else
			_printe(": can't cd to ");
		_printe(data->tokens[1]);
		_printe("\n");
	}
	else if (error_code == 127)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": not found\n");
	}
	else if (error_code == 126)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": Permission denied\n");
	}
	return (0);
}
