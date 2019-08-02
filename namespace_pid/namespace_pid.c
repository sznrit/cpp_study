#define _GNU_SOURCE	// 必须包含

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sched.h>

#define STACK_SIZE (1024 * 1024)

static char child_stack[STACK_SIZE];

char * const child_args[] = {
	"/bin/bash",
	NULL
};

int child_main(void *args)
{
	printf("in child process..\n");
	sethostname("child", sizeof("child"));
	execv(child_args[0], child_args);
	return 0;
}

int main(void)
{
	printf("process begin\n");
	int child_pid = clone(child_main, child_stack + STACK_SIZE, 
						  CLONE_NEWPID | CLONE_NEWIPC | CLONE_NEWUTS | SIGCHLD, NULL);
	waitpid(child_pid, NULL, 0);
	printf("process exit\n");
	
	return 0;
}
