#include "main.h"
/**
 * fill_args - Fill an array with every input typed by the user
 * @entry: String with the input
 * @arguments: Array to be filled
 * Return: Length of the array
 */

int fill_args(char *entry, char **arguments)
{
	int i = 0;
	char *options, *aux = entry, *command;

	command = strtok(entry, "\n\t\r "); /**Extract the command 0 */
	arguments[i] = command; /**Store command 1 in args*/
	while (aux != NULL) /**As long as there are tokens*/
	{
		++i;
		options = strtok(NULL, "\n\t\r "); /**Store the nth argument in parameter*/
		aux = options;
		arguments[i] = options; /**stores parameter i in args[i]*/
	}
	arguments[i] = NULL; /**Mark the end of an array*/
	return (i); /**Return the length of args[]*/
}
