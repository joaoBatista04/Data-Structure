#include <time.h>
#include <stdio.h>

double get_timestamp()
{
    struct timespec now;
    timespec_get(&now, TIME_UTC);
    return now.tv_sec + (((double)now.tv_nsec) / 1e9);
}

int main(){
    double start = get_timestamp(); 

    // trecho que queremos medir

    double end = get_timestamp(); 

    // tempo passado entre os dois pontos do código
    double dt = (end - start);

    printf("Time: %lf\n", dt);

    return 0;
}