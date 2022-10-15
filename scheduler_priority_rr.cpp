#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "schedulers.h"
#include "cpu.h"
#include "list.h"

struct node* head = NULL;


void add(char *name, int priority, int burst)
{
    struct task* temp = malloc(sizeof(struct task));
    temp->name = name;
    temp->priority = priority;
    temp->burst = burst;
        
    insert(&head, temp);
}

void swapNodes(struct node* node1, struct node* node2)
{
    struct node* swapNode = node1;
    node1 = node2;
    node2 = swapNode;
}


void schedule()
{
    while (head != NULL)
    {
        struct node* tempNode = head;
        struct task* tempTask = head->task;
        struct task* highestPriorityTask = tempTask;

        // find the highest priority job from the list
        while (tempNode->next != NULL)
        {
            tempNode = tempNode->next;
            tempTask = tempNode->task;
            if (highestPriorityTask->priority < tempTask->priority)
            {
                highestPriorityTask = tempTask;
            }
        }
        if (highestPriorityTask->burst > QUANTUM)
        {
            highestPriorityTask->burst -= QUANTUM;
            run (highestPriorityTask, QUANTUM);
        }
        else
        {
            run(highestPriorityTask, highestPriorityTask->burst);
            delete(&head, highestPriorityTask);
        }
    }

}
