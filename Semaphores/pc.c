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


	if(semctl(semid, semno, SETVAL, un) < 0)
	{
		perror("semctl:");
		exit(2);
	}
}

int buffer[BUFSIZE], data;
int in = 0;
int out = 0;

int i = 20;
int j = 20;



void *producer(void *id) {
	int semid = (int) id;
	data = 0;
	while(i--) {
		waitsem(EMPTY);
		waitsem(MUTEX);

		buffer[in] = data;
		printf("P:%d\n", data);
		in = (in + 1) % BUFSIZE;
		data = (data + 1) % BUFSIZE;
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
		
	data = buffer[out];
	printf("C:%d\n", data);
	out = (out + 1) % BUFSIZE;
	
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
