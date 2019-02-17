
CS201 Spring 2019
Assignment #3: Priority Queue
Due 11:59 pm Monday, Feb. 25th
15 points

A priority queue is a FIFO list, maintained in sorted priority order. For this assignment, keep the list in
ascending priority order (so that nodes having lower priority go in the front of the queue).
Define these structs:

        typedef struct {
         int id;
         char name[32];
        } StudentRecord;
        typedef struct PQueueStruct {

         int priority;
         void *data;
         struct PQueueStruct *next;
        } PQueueNode;

Implement the following functions

        int enqueue(PQueueNode **pqueue, int priority, void *data)
        void *dequeue(PQueueNode **pqueue)
        void *peek(PQueueNode *pqueue)
        void printQueue(PQueueNode *pqueue, void (printFunction)(void*))
        int getMinPriority(PQueueNode *pqueue)
        int queueLength(PQueueNode *pqueue)
        void printStudentRecord(void *data)

