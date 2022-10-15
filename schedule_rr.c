#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "schedulers.h"
#include "cpu.h"
#include "list.h"

struct node* head = NULL;
struct node* tail = NULL;


void add(char *name, int priority, int burst)
{
    struct task* rr = malloc(sizeof(struct task));
    rr->name = name;
    rr->priority = priority;
    rr->burst = burst;

    insert(&head, rr);
}


void schedule()
{
    // loop until the list is empty

    while (head != NULL)
    {
        struct node* tempNode = head;
        struct task* tempTask = tempNode->task;

        // CPU runs job and then removes it from the list
        if (tempTask->burst > QUANTUM)
        {
            run(tempTask,QUANTUM);
            tempTask->burst = tempTask->burst - 10;
            delete(&head, tempTask);
            add(tempTask->name, tempTask->priority, tempTask->burst);
        }
        else if (tempTask->burst <= QUANTUM)
        {
            run(tempTask, tempTask->burst);
            delete(&head, tempTask);
        }
    }
    
}