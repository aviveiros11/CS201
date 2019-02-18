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
               start->next->priority < priority) {
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
    free(temp);

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
    return 0;
}

int queueLength(PQueueNode *pqueue){
    return 0;
}

void printStudentRecord(void *data){
    StudentRecord *node = (StudentRecord *) data;
    printf("id = %d , name = %s\n", node->id, node->name);

}
