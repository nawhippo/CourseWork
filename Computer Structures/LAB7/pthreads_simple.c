#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define INCCNT 1000

void *appendExample(void *arg)
{
//cast void pointer to char pointer
    char *str = (char *)arg;
    //initialize buffer and concatenate string and example
    char buf[256];
    sprintf(buf, "%s%s", str, " Example ");

    //print concatenated string
    printf("Concat String: %s\n",  buf);

    //exit the thread
    pthread_exit(NULL);
}
//function is executed in the second thread
void *incrementNum(void *arg)
{
//arg is now integer pointer
    int *num = (int*)arg;
    for (int i = 0; i < INCCNT;  i++) {
        (*num)++;
    }

 //print final incremented value
    printf("Count: %d\n",*num);

    //exit thread
    pthread_exit(NULL);
}


int main(int argc, char *argv[])
{
  //check for valid numb of argument
    if (argc < 3) {
        perror("Invalid number of arguments");
        return -1;
    }

    char *str = argv[1];
    int num = atoi(argv[2]);
 //create two threads
    pthread_t tid[2];
   //makes the first thread and pass the string as the argument
    if (pthread_create(&tid[0], NULL, appendExample, str)) {
        perror("Error creating thread 1\n");
        return -1;
    }
  //create second thread and pass integer as argument
    if (pthread_create(&tid[1], NULL, incrementNum, &num)) {
        perror("Error creating thread 2\n");
        return -1;
    }
  //wait for threads to compleete
    pthread_join(tid[0],NULL);


    pthread_join(tid[1], NULL);
    //exit
    return 0;
}
                                      
                                                                        