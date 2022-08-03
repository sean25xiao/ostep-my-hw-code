#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  // getpid()

#define ONE_K 1024
#define MICRO_SEC 1000000

int main(int argc, char *argv[])
{
    printf("Hi, my PID is %d\n", getpid());

    // Early Return
    if ( argc != 3){
        printf("Error - Usage: ./a.out <NUM_MEGA_BYTES> <RUNNING_TIME_IN_SEC>\n");
        return 0;
    }

    int mem_use     = atoi(argv[1]);
    int running_sec = atoi(argv[2]);

    if ( (mem_use < 0) || (running_sec < 0) ){
        printf("Error - Input should be positive\n");
        return 0;
    }

    int num_chars = mem_use * ONE_K * ONE_K;

    char *p_alloc = (char *) malloc( num_chars * sizeof(char) );

    clock_t start_time = clock();
    int milli_sec = MICRO_SEC * running_sec;

    while( clock() < (start_time + milli_sec) )
    {
        for (int i = 0; i < num_chars; i++) {
            p_alloc[i] = 0;
        }
    }
    
    free(p_alloc);

    return 0;
}