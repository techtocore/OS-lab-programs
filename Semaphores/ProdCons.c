#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <pthread.h>
#include <stdlib.h>

#define BUFSIZE 10

#define MUTEX 0
#define FULL 1
#define EMPTY 2

int semid;

int sem_create(int nsems) { 
	int  id;
	key_t key = 1234;
        // int semget(key_t key, int nsems, int semflg); 
        // nsems : number of semaphores to create
	id = semget(key, nsems, IPC_CREAT | 0666);
	if(id < 0)
	{
		perror("semget:");
		exit (1);
	}
	return id;
}

void sem_initialise(int semno, int val) {
	union semun {
		int val;
		struct semid_ds *buf;
		ushort * array;
	} un;
	un.val = val;

        //  int semctl(int semid, int semnum, int cmd, union semun); 
        // here semno 0(MUTEX) is set with val 1
        // here semno 1(FULL) is set with val 0
        // here semno 2(EMPTY) is set with val 10

	if(semctl(semid, semno, SETVAL, un) < 0)
	{
	//	printf("%d\n", semno);
		perror("semctl:");
		exit(2);
	}
}

void *producer(void *id);
void *consumer(void *id);

void waitsem(int semno);
void signalsem(int semno);

int buffer[BUFSIZE], data;
int in = 0;
int out = 0;

int i = 20;
int j = 20;

int main(int argc,char	*argv[])	{
	semid = sem_create(3);
	sem_initialise(MUTEX, 1);
	sem_initialise(FULL, 0);
	sem_initialise(EMPTY, 10);

	pthread_t prod, cons;	
	
	pthread_create(&prod, NULL, producer, (void *)semid);
	pthread_create(&cons, NULL, consumer, (void *)semid);
	
	pthread_exit(NULL);
	return	0;
}

void *producer(void *id) {
	int semid = (int) id;
	data = 0;
	while(i--) {
		waitsem(EMPTY);
		waitsem(MUTEX);

		/** Critical Section **/
		buffer[in] = data;
		printf("P:%d\n", data);
		in = (in + 1) % BUFSIZE;
		data = (data + 1) % BUFSIZE;
		//printf("P\n");
		signalsem(MUTEX);
		signalsem(FULL);
	}
	pthread_exit(NULL);
}

void *consumer(void *id) {
	int semid = (int) id;
	while(j--)
	{
	waitsem(FULL);
	waitsem(MUTEX);
	
	/** Critical Section 	**/	
	data = buffer[out];
	printf("C:%d\n", data);
	out = (out + 1) % BUFSIZE;
	/** 			**/
	
	signalsem(MUTEX);
	signalsem(EMPTY);
	}	
	
	pthread_exit(NULL);
}

void waitsem(int semno) {
	struct sembuf buf;
	buf.sem_num = semno;
	buf.sem_op = -1;
	buf.sem_flg = 0;
	if(semop(semid, &buf, 1) < 0) {
		perror("semop:");
		exit(2);
	}
}

void signalsem(int semno) {
	struct sembuf buf;
	buf.sem_num = semno;
	buf.sem_op = 1;
	buf.sem_flg = 0;
	if(semop(semid, &buf, 1) < 0)
	{
		perror("semop:");
		exit(2);
	}
}
