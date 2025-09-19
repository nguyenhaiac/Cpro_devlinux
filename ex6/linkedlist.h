#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#define TEXT_LENGTH 50

typedef struct TaskNode {
    char description[TEXT_LENGTH];
    struct TaskNode *nextNode;
} TaskNode_t;

void queue_add_task(const char *description);

void print_queue();
TaskNode_t *get_next_task();
void peak_queue();
#endif // LINKEDLIST_H_
