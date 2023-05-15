#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t *q)
{
        if (q == NULL)
                return 1;
        return (q->size == 0);
}

void enqueue(struct queue_t *q, struct pcb_t *proc)
{
        /* TODO: put a new process to queue [q] */
        if (q == NULL)
        {
                perror("Queue is NULL !\n");
                exit(1);
        }
        if (q->size == MAX_QUEUE_SIZE)
        {
                perror("Queue is full !\n");
                exit(1);
        }
        q->proc[q->size] = proc;
        q->size++;
}

struct pcb_t *dequeue(struct queue_t *q)
{
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
        if (q == NULL || q->size == 0)
        {
                return NULL;
        }
        struct pcb_t *temp = q->proc[0];

#ifdef MLQ_SCHED
        int length = q->size - 1; 
        for (int i = 0; i < length; ++i)
        {
                q->proc[i] = q->proc[i + 1];
        }
        q->proc[length] = NULL;
        q->size--;
        return temp;
#else
        int index = 0;
        int length = q->size;
        for (int i = 1; i < length; ++i)
        {
                if (temp->priority < q->proc[i]->priority)
                {
                        temp = q->proc[i];
                        index = i;
                }
        }
        q->proc[index] = q->proc[length - 1];
        q->proc[length - 1] = NULL;
        q->size--;
        return temp;
#endif
}
