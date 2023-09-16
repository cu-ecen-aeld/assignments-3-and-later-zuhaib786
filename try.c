#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main(int argc, char * argv[])
{
	printf("Trying the exec command\n");
	fflush(stdin);
	pid_t pid = fork();
	if(pid == -1)
	{
		printf("Error in running fork command");
	}
	if (pid == 0)
	{
		char * command[3];
		command[0] = "/bin/echo";
		command[1] = "Hello";
		command[2] = NULL;
		//Child process
		execv(command[0], command);
	}
	if(pid > 0)
	{
		// Parent process
		printf("I am in parent process\n");
		int status = waitpid(pid);
		if (status == 0)
		{
			printf("The task ran successfully %d \n", status);
		}
		else
		{
			printf("Some error in execution of the procees: %d \n", status);
		}
	}
}

