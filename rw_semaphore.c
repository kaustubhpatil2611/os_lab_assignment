#include<stdio.h>
#include<pthread.h>//header file for threads
#include<semaphore.h>//header file for semaphore

sem_t w;//define semaphore w with data type sem_t
pthread_mutex_t mutex;//define mutex mutex
int reader_count=0;//readers count
int data=0;//data read/write

void *writer(void *wno)//writer function
{
	sem_wait(&w);//acquire lock on semaphore
	data=data+1;//update data
	printf("Writer %d incremented the value by 1 to %d",*((int *)wno),data);
	printf("\n");
	sem_post(&w);//release lock
}

void *reader(void *rno)//reader function
{
	pthread_mutex_lock(&mutex);//acquire lock on read count
	reader_count=reader_count+1;//increment reader count
	if(reader_count==1)//if first reader 
	{
		sem_wait(&w);	//lock write semaphore
	}
	pthread_mutex_unlock(&mutex);//release lock
	
	//perform read operation
	printf("Reader %d is reading value %d",*((int *)rno),data);
	printf("\n");
	
	pthread_mutex_lock(&mutex);//aquire lock before updating and leaving readers section
	reader_count=reader_count-1;//decrement
	if(reader_count==0)
	{
		sem_post(&w);//if readers=0 then release lock on semaphore
	}
	pthread_mutex_unlock(&mutex);//release lock
}

int main()
{
	sem_init(&w,0,1);//initialize semaphore
	pthread_t read[10],write[5];//initialilze threads
	pthread_mutex_init(&mutex,NULL);//initialize mutex
	
	int num[10] = {1,2,3,4,5,6,7,8,9,10};//reader writers count
	
	printf("Readers- Writer problem using semaphore \n\n");
	
	for(int i=0;i<10;i++)//create read threads
	{
		pthread_create(&read[i], NULL, (void *)reader, (void *)&num[i]);
	}
	for(int i = 0; i < 5; i++) //create write threads
	{
        	pthread_create(&write[i], NULL, (void *)writer, (void *)&num[i]);
    	}	
    	for(int i = 0; i < 10; i++) //join threads
    	{
        	pthread_join(read[i], NULL);
    	}
    	for(int i = 0; i < 5; i++) //join threads
    	{
        	pthread_join(write[i], NULL);
    	}

    	pthread_mutex_destroy(&mutex);//terminate mutex
    	sem_destroy(&w);//terminate semaphore

    return 0;
}
