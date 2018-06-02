#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>


int main(){
int shmid;
int *num;
int key;
key = 1234;
	if((shmid = shmget(key, sizeof(int), IPC_CREAT | 0444)) < 0){
		printf("error creating shared memory\n");
		exit(1);
	}
	if ((num = shmat(shmid, NULL, 0)) == (int *) -1) {
		printf("error attaching shared memory\n");
		exit(1);
	}
	int val = *num;
	if(val % 3 == 0){
		printf("The number you entered is a multiple of 3!\n");
	}
	else{
		printf("The number you entered is not a multiple of 3!\n");
	}
	shmdt(num);
	shmctl(shmid, IPC_RMID, 0);

}
