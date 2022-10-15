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
    struct task* sjf = malloc(sizeof(struct task));
    sjf->name = name;
    sjf->priority = priority;
    sjf->burst = burst;
        
    insert(&head, sjf);
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
        struct task* shortestTask;


        struct node* tempNode0 = head;
        int sizeOfList = 0;
        while (tempNode0->next != NULL)
        {
            sizeOfList++;
            tempNode0 = tempNode0->next;
        }

        for (int i = 0; i < sizeOfList - 1; i++)
        {
            for (int j = 0; j < sizeOfList - 1; j++)
            {
                if (tempNode->task->burst > tempNode->next->task->burst)
                {
                    swapNodes(tempNode, tempNode->next);
                    tempNode = tempNode->next;
                }
            }
        }
        shortestTask = head->task;

        run(shortestTask, shortestTask->burst);
        delete(&head, shortestTask);
        }
    }