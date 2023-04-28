#include "shell.h"
void mode_run(char *av0)
{
	char *prompt = "#cisfun$ ", /* *c,  */*input, **argv;
	int status;

	if (!isatty(0))
	{
		while ((input = getinput()) != NULL )
		{
			argv = parser(input);
			execute_command(argv, av0, input, &status /* , c */);
		}
		free(input);
		exit(status);
	}
	else
	{
		print_prompt(prompt);
		input = getinput();
		argv = parser(input);
		execute_command(argv, av0, input, &status/* , c */);
	}

}
