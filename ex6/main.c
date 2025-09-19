#include "linkedlist.h"
#include "stdlib.h"

int main() {
    print_queue();
    queue_add_task("test node 1");
    queue_add_task("test node 2");
    queue_add_task("test node 3");
    queue_add_task("test node 4");
    queue_add_task("test node 5");
    print_queue();
    TaskNode_t *task1 = get_next_task();
    TaskNode_t *task2 = get_next_task();
    free(task1);
    free(task2);
    print_queue();
    peak_queue();
    TaskNode_t *task3 = get_next_task();
    TaskNode_t *task4 = get_next_task();
    TaskNode_t *task5 = get_next_task();
    free(task3);
    free(task4);
    free(task5);
    print_queue();
    peak_queue();
}
