#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

static void sighandler(int signo){

  if(signo == SIGINT) {
   int fd = open("record.txt", O_WRONLY | O_CREAT, 0644);
   char error[] =  "Exit due to SIGINT \n";
   int wf = write(fd, error, sizeof(error));
   close(fd);
   exit(0);
 }

 if (signo == SIGUSR1){
		printf("Parent PID: %d\n",getppid());
  }
}

int main(){

	signal(SIGINT,sighandler);
	signal(SIGUSR1,sighandler);

	while (1){
		printf("Current PID: %d \n",getpid());
		sleep(1);
	}

	return 0;
}
