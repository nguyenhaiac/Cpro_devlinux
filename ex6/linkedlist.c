#include "linkedlist.h"
#include "stdio.h"
#include "stdlib.h"

static TaskNode_t *head;
static TaskNode_t *tail;

void queue_add_task(const char *description) {
    TaskNode_t *task = malloc(sizeof(TaskNode_t));
    snprintf(task->description, sizeof(task->description), description);
    task->nextNode = NULL;
    if (task == NULL) {
        perror("error in malloc");
        return;
    }
    if (head == NULL) {
        head = task;
        tail = task;
    } else {
        tail->nextNode = task;
        tail = task;
    }
}

void print_queue() {
    if (head == NULL) {
        printf("Error: empty queue\n'");
        return;
    }
    TaskNode_t *node;
    node = head;
    while (node) {
        printf("%s\n", node->description);
        node = node->nextNode;
    }
}

TaskNode_t *get_next_task() {
    if (head == NULL) {
        return NULL;
    }
    TaskNode_t *temp;
    temp = head;
    head = temp->nextNode;
    return temp;
}

void peak_queue() {
    if (head == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("the next task is: %s\n", head->description);
}
