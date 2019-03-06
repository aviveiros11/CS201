#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pqueue.aviveiro.h"

int enqueue(PQueueNode **pqueue, int priority, void *data){

    // Create new Node
    PQueueNode *newNode;
    newNode = (PQueueNode *) malloc(sizeof(PQueueNode));
    newNode->priority = priority;
    newNode->data = data;


    if ((*pqueue) == NULL) {
        // Insert New Node before head
        newNode->next = *pqueue;
        (*pqueue) = newNode;
    }
    else if ((*pqueue)->priority > priority) {

        // Insert New Node before head
        newNode->next = *pqueue;
        (*pqueue) = newNode;
    }
    else {

        PQueueNode* start = (*pqueue);

        // Traverse the list and find a
        // position to insert new node
        while (start->next != NULL &&
               start->next->priority <= priority) {
            start = start->next;
        }

        // Either at the ends of the list
        // or at required position
        newNode->next = start->next;
        start->next = newNode;
    }
    return 0;
}

void *dequeue(PQueueNode **pqueue){
    PQueueNode* temp = *pqueue;
    (*pqueue) = (*pqueue)->next;
    return temp->data;

}

void *peek(PQueueNode *pqueue){
    return (pqueue)->data;

}

void printQueue(PQueueNode *pqueue, void (printFunction)(void*)){
    PQueueNode *node;
    if (pqueue == NULL)
        printf("(list is empty)\n");
    else {
        node = pqueue;
        while (node != NULL) {
            printf("priority = %d ", node->priority);
            printFunction(node->data);
            node = node->next;
        }
    }

}

int getMinPriority(PQueueNode *pqueue){
    if(pqueue == NULL){
        return pqueue->priority;
    }
    else{
        while(pqueue != NULL){
            if(pqueue->priority){
                return pqueue->priority;
            }
            pqueue = pqueue->next;
        }
    }

}

int queueLength(PQueueNode *pqueue){
    int length = 0;

    while(pqueue != NULL){
        length+=1;
        pqueue = pqueue->next;

    }
    return length;
}

void printStudentRecord(void *data){
    StudentRecord *node = (StudentRecord *) data;
    printf("data = %s, %d\n", node->name, node->id);

}
