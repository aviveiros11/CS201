//
// Created by The Flash on 3/4/19.
//
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <zconf.h>
#include <sys/wait.h>
#include <ctype.h>

#define BUFFER_SIZE 32

int main(int argc, char *argv[]) {

    char* words[] = {"now", "is", "the", "time", "for", "all", "good", "men"};
    int numwords = 8;

    int i;
    int j;
    int pid;
    int memid;
    int key = 35;
    char *ptr;
    char buffer[BUFFER_SIZE];


    memid = shmget(key, BUFFER_SIZE, IPC_CREAT | 0666);
    if (memid < 0) {
        printf("shmget() failed\n");
        return(8);
    }

    pid = fork();
    if (pid < 0) {
        printf("fork failed\n");
        return(8);
    }

    if (pid > 0) {
        // this is the parent
        printf("I am the parent, and my pid is %d\n", getpid());

        ptr = (char *) shmat(memid, 0, 0);
        if (ptr == NULL) {
            printf("shmat() failed\n");
            return(8);
        }

        for(i=0;i<numwords;i++){
            strcpy(buffer, words[i]);
            printf("(P) writing '%s' to the shared memory\n", buffer);
            strcpy(ptr, buffer);

            usleep(700000);

            printf("(P) read '%s' from the shared memory\n", ptr);

        }
        wait(NULL);


    } else {
        // this is the child
        pid = getpid();
        printf("I am the child, and my pid is %d\n", pid);
        ptr = (char *) shmat(memid, 0, 0);
        if (ptr == NULL) {
            printf("shmat() in child failed\n");
            return(8);
        }

        for(i=0;i<numwords;i++){

            printf("(C) read this from the shared memory: '%s'\n", ptr);
            for(j=0;j<strlen(ptr);j++) {
                ptr[j] = toupper(ptr[j]);
            }

            printf("(C) write this to the shared memory '%s'\n", ptr);


            usleep(1050000);

        }
        shmdt(ptr);
        return(0);

    }
    shmdt(ptr);
    shmctl(memid, IPC_RMID, NULL);
    return(0);

}
//---------- Explanation ----------
/*
 * In oder to successfully use and modify the shared resources between the Parent and the Child we must implement
 * a new system containing locks and signals or flags.  The current usleep call simply tells the parent and the child
 * to sleep arbitrarily with little knowledge of each others processes.  To solve this rather than implementing usleep,
 * we can implement a mutex lock or a semaphore signalling to each respective process their status. This will allow the
 * parent to complete its process -> unlock -> child completes its process -> unlock -> and so forth.
 *
 */

