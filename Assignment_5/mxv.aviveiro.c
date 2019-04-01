//
// Created by Austin Viveiros on 3/27/19.
//
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N 8

double A[N][N];
double x[N], y[N];

typedef struct {
    double *row;
    double *v;
    double result;
} Info;

float bigSum = 0;
int count = 0;

void *multiply(void *data) {

    int f;
    Info *info = (Info *) data;
    // here's where you do the work
    for (f=0; f<N; ++f) {
        bigSum += info->row[f] * info->v[f];
    }
    info->result = bigSum;
    y[count] = bigSum;
    count+=1;

}


int main(int argc, char *argv[]) {

    int i = 0;
    int j = 0;

    for (i=0; i<N; ++i) {
        for (j=0; j<N; ++j) {
            A[i][j] = drand48() - 0.5;
        }
    }

    for (i=0; i<N; ++i) {
        x[i] = drand48() - 0.5;
    }

    Info info[N];
    pthread_t tid[N];
    for (i=0; i<N; ++i) {
        info[i].row = &A[i][0];
        info[i].v = &x[i];
        pthread_create(&tid[i], NULL, multiply, &info[i]);
    }
    for (i=0; i<N; ++i) {
        pthread_join(tid[i], NULL);
    }

    for (i=0; i<N; ++i) {
        printf("results = %f\n", y[i]);
    }

    return(0);
}