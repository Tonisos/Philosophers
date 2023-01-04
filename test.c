#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

void *routine(void *arg)
{
	printf("<<%d>>\n", (int)arg);
	return (NULL);
}


int main()
{
	// int i = 3;
	pthread_t tab[5];
	pthread_create(&tab[1], NULL, routine, (void *)3);
	pthread_create(&tab[2], NULL, routine, (void *)4);
	usleep(1000);
	return(0);
}