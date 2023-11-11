#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

#include "macros.h"

/**
 * struct ProgramData - Structure to hold various program data
 * @program_name: Name of the program
 * @input_line: Input line read by getline
 * @command_name: Name of the command
 * @exec_counter: Execution counter
 * @file_descriptor: File descriptor for input commands
 * @tokens: Array of tokens
 * @env: Environment variables
 * @alias_list: Array of aliases
 */
typedef struct ProgramData {
	char *program_name, *input_line, *command_name;
	int exec_counter, file_descriptor;
	char **tokens, **env, **alias_list;
} ProgramData;

/**
 * struct Builtin - Structure to define built-in commands and their functions
 * @built_in: Name of the built-in command
 * @function: Function pointer for the built-in command
 */
typedef struct Built_in {
	char *built_in;
	int (*function)(ProgramData *data);
} Built_in;

/* Function prototypes */

void initialize_data(ProgramData *data, int argc, char *argv[], char **env);
void run_shell(char *prompt, ProgramData *data);
void handle_ctrl_c(int opr UNUSED);
int get_line(ProgramData *data);
int check_logic_ops(char *array_commands[], int i, char array_operators[]);
void expand_variables(ProgramData *data);
void expand_alias(ProgramData *data);
int buffer_add(char *buffer, char *str_to_add);
void tokenize(ProgramData *data);
char *strtok_custom(char *line, char *delim);
int execute(ProgramData *data);
int run_builtins(ProgramData *data);
char **tokenize_path(ProgramData *data);
int find_program(ProgramData *data);
void free_array_of_pointers(char **directories);
void free_recurrent_data(ProgramData *data);
void free_all_data(ProgramData *data);
int print_str(char *str);
int print_error(int error_code, ProgramData *data);
char *env_get_key(char *name, ProgramData *data);
int env_set_key(char *key, char *value, ProgramData *data);
int env_remove_key(char *key, ProgramData *data);
void print_environ(ProgramData *data);
int str_length(char *str);
char *str_duplicate(char *str);
int str_compare(char *str1, char *str2, int number);
char *str_concat(char *str1, char *str2);
void str_reverse(char *str);
void long_to_string(long number, char *str, int base);
int atoi_custom(char *s);
int count_characters(char *str, char *character);
int print_alias(ProgramData *data, char *alias);
char *get_alias(ProgramData *data, char *alias);
int set_alias(char *alias_string, ProgramData *data);

#endif /* SHELL_H */
