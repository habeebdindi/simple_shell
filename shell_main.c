#include "shell.h"
void sigint_handler(int signo);
/**
 * main - main function for the shell.
 * @ac: argument count.
 * @av: ana array of pointers to the program.
 * Return: always 0 (succes).
 */

int main(__attribute__((unused)) int ac, char **av)
{
	char *prompt = "#cisfun$ ", *c, error_message[200], *input = NULL, **argv;
	size_t n = 0, message_length, i = 0;

	while (1)
	{
		print_prompt(prompt);
		getinput(&input, &n);
		argv = parser(input);
		if (!argv)
			continue;
		_exitt(argv, input);
		c = getpath(argv[0]);
		if (!c)
		{
			memset(error_message, 0, sizeof(error_message));
			snprintf(error_message, sizeof(error_message),
					"%s: %ld: %s: command not found\n", av[0], ++i, argv[0]);
			message_length = strlen(error_message);
			write(STDERR_FILENO, error_message, message_length);
			free_argv(argv);
			continue;
		}
		execute_command(argv, av[0], input, c);
	}
	return (0);
}
