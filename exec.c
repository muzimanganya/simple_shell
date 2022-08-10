#include "main.h"
/**
 * exec - Creates a new child process,
 * executes a command and wait for the child process
 * to update the status
 * @arguments: Array of inputs by the user
 * Return: 0 if success
 */
int exec(char **arguments)
{
	pid_t pid = 0;/**Child process id*/
	int stat = 0, exe_stat = 0;/**indica el status del child process*/

	pid = fork();/**Crear process*/
	if (pid == -1)/**Fail all clear*/
		_printp("failed\n", 7);
	else if (pid == 0)/**It's its child...*/
	{
		exe_stat = execve(arguments[0], arguments, environ);/**Ejecuta el comando*/
		if (exe_stat == -1)
		{
			exe_stat = 126;
			perror("hsh");
			exit(exe_stat);
		} /**Terminate the child process with exit*/
		exit(0);
	}
	else /**It's the parent*/
		wait(&stat);/**It stops the execution of the father until the child finishes*/
	exe_stat = WEXITSTATUS(stat);
	return (exe_stat);
	}
