#include "shell.h"

/**
 * builtins_list - Searches for a match and executes the associated builtin.
 * @data: Struct for the program's data.
 * Return: Returns the return value of the executed function if there is a match,
 * otherwise returns -1.
 **/
int builtins_list(data_of_program *data)
{
	int iterator;
	builtins options[] = {
		{"exit", builtin_exit},
		{"help", builtin_help},
		{"cd", builtin_cd},
		{"alias", builtin_alias},
		{"env", builtin_env},
		{"setenv", builtin_set_env},
		{"unsetenv", builtin_unset_env},
		{NULL, NULL}
	};

	/* Iterate through the array of builtins */
	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{
		/* Check if there is a match between the given command and a builtin */
		if (str_compare(options[iterator].builtin, data->command_name, 0))
		{
			/* Execute the function and return its return value */
			return options[iterator].function(data);
		}
	}

	/* Return -1 if there is no match */
	return -1;
}
