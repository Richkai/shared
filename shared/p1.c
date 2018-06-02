#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>


int main(){
int shmid;
int *num;
int key;
key = 1234;
int x;
	if ((shmid = shmget(key, sizeof(int) , IPC_CREAT | 0666)) < 0) {	
		printf("error creating shared memory\n");
		exit(1);
	}
	if((num = shmat(shmid, NULL, 0)) == (int *) -1){
		printf("error attaching shared memory\n");
		exit(1);
	}

	printf("Please enter the number:");
	scanf("%d",&x);
	*num = x;
	shmdt(num);
}


