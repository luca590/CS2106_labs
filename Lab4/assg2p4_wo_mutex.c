/*
 * =====================================================================================
 *
 *       Filename:  assg2p4.c
 *
 *    Description:  Lab 4 program
 *
 *        Version:  1.0
 *        Created:  03/18/2018 00:39:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int glob;
pthread_t thread[10];

void *child (void* t) {
	//Increment glob by 1, wait for 1 second, then increment by 1 again
	printf("Child %d entering. Glob is currently %d\n", t, glob);
	glob++;
	sleep(1);
	glob++;
	printf("Child %d exiting. Glob is currently %d\n", t, glob);
	pthread_exit(NULL);
}

int main() {
	int i;
	glob = 0;

	for (i = 0; i < 10; i ++)
		pthread_create(&thread[i], NULL, child, (void*) i);

	for (i = 0; i < 10; i ++)
		pthread_join(thread[i], NULL);

	printf("Final value of glob is %d\n", glob);
	return 0;
}

