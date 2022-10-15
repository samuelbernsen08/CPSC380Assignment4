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
    struct task* fcfs = malloc(sizeof(struct task));
    fcfs->name = name;
    fcfs->priority = priority;
    fcfs->burst = burst;

    insert(&head, fcfs);
}


void schedule()
{
    // loop until the list is empty

    while (head != NULL)
    {
        struct node* tempNode = head;
        struct task* tempTask = tempNode->task;

        // CPU runs job and then removes it from the list
        run(tempTask, tempTask->burst);
        delete(&head, tempTask);
    }
    
}