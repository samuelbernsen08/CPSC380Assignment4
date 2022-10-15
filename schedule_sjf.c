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
        struct task* shortestTask = tempTask;


        //struct node* tempNode0 = head;
        
        while (tempNode->next != NULL)
        {
            tempNode = tempNode->next;
            tempTask = tempNode->task;
            if(shortestTask->burst > tempTask->burst)
            {
                shortestTask = tempTask;
            }
        }

        run(shortestTask, shortestTask->burst);
        delete(&head, shortestTask);
        }
    }
