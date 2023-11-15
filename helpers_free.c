#include "shell.h"

/**
 * free_recurrent_data - Releases the resources associated with the fields used in each loop iteration.
 * @data: Structure containing the program's data.
 * Return: Nothing.
 */
void free_recurrent_data(ProgramData *data)
{
	if (data->tokens)
		free_array_of_pointers(data->tokens);
	if (data->input_line)
		free(data->input_line);
	if (data->command_name)
		free(data->command_name);

	data->input_line = NULL;
	data->command_name = NULL;
	data->tokens = NULL;
}

/**
 * free_all_data - Releases all resources associated with the fields in the data structure.
 * @data: Struct containing the program's data.
 * Return: Nothing.
 */
void free_all_data(ProgramData *data);
{
	if (data->file_descriptor != 0)
	{
		if (close(data->file_descriptor))
			perror(data->program_name);
	}
	free_recurrent_data(data);
	free_array_of_pointers(data->env);
	free_array_of_pointers(data->alias_list);
}

/**
 * free_array_of_pointers - Releases the memory occupied by each pointer in an array of pointers,
 *                          and then frees the array itself.
 * @directories: Array of pointers to be freed.
 * Return: Nothing.
 */
void free_array_of_pointers(char **directories)
{
	int i;

	if (array != NULL)
	{
		for (i = 0; array[i]; i++)
			free(array[i]);

		free(array);
		array = NULL;
	}
}
