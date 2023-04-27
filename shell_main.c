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
	char *prompt = "#cisfun$ ", *c, i_buf[100], error_message[200];
	char *input = NULL, **argv;
	size_t n = 0, message_length, i = 0;

	while (1)
	{
		print_prompt(prompt);
		getinput(&input, &n);
		argv = parser(input);
		if (!argv)
			continue;
		if (_envv(argv))
			continue;
		_exitt(argv, input);
		c = getpath(argv[0]);
		if (!c)
		{
			_memset(i_buf, 0, sizeof(i_buf));
			_memset(error_message, 0, sizeof(error_message));
			_strcpy(error_message, av[0]);
			_strcat(error_message, ": ");
			_strcat(error_message, itoa(++i, i_buf));
			_strcat(error_message, ": ");
			_strcat(error_message, argv[0]);
			_strcat(error_message, ": ");
			_strcat(error_message, "not found");
			message_length = strlen(error_message);
			write(STDERR_FILENO, error_message, message_length);
			write(STDERR_FILENO, "\n", _strlen("\n"));
			free_argv(argv);
			continue;
		}
		execute_command(argv, av[0], input, c);
	}
	return (0);
}
