#include "shell.h"
/**
 * mode_run - runs the shell in either interactive or non-interactive mode.
 * @av0: The name of the shell program.
 * @i: pointer to loop main loop counter.
 * Return: void.
 */
void mode_run(char *av0, int *i)
{
	char *prompt = "#cisfun$ ", *c, *input, **argv;
	int status = 0;

	if (!isatty(0))
	{
		while ((input = getinput()) != NULL)
		{
			if (_strlen(input) == 1)
			{
				free(input);
				continue;
			}
			argv = parser(input);
			if (!argv || !handle_builtin(i, argv, input, av0, &status))
				exit(EXIT_SUCCESS);
			c = getpath(argv[0]);
			if (!c)
				err_clean(i, av0, input, argv, &status);
			else
				execute_command(argv, av0, input, &status, c);
		}
		exit(status);
	}
	else
	{
		print_prompt(prompt);
		input = getinput();
		argv = parser(input);
		if (!argv || !handle_builtin(i, argv, input, av0, &status))
			return;
		c = getpath(argv[0]);
		if (!c)
			err_clean(i, av0, input, argv, &status);
		else
			execute_command(argv, av0, input, &status, c);
	}
}
