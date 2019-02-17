//
// Created by Austin Viveiros on 2/16/19.
//

#ifndef ASSIGNMENT_3_PQUEUE_AVIVEIRO_H
#define ASSIGNMENT_3_PQUEUE_AVIVEIRO_H

typedef struct {
    int id;
    char name[32];
} StudentRecord;

typedef struct PQueueStruct {
    int priority;
    void *data;
    struct PQueueStruct *next;
} PQueueNode;


int enqueue(PQueueNode **pqueue, int priority, void *data);

void *dequeue(PQueueNode **pqueue);

void *peek(PQueueNode *pqueue);

void printQueue(PQueueNode *pqueue, void (printFunction)(void*));

int getMinPriority(PQueueNode *pqueue);

int queueLength(PQueueNode *pqueue);

void printStudentRecord(void *data);



#endif //ASSIGNMENT_3_PQUEUE_AVIVEIRO_H
