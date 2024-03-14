#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASK 100
#define MAX_TASK_LENGTH 100

struct Task {
    char desc[MAX_TASK_LENGTH];
    int isDone;
};

struct List {
    struct Task tasks[MAX_TASK];
    int count;
};

void init(struct List *list) {
    list->count = 0;
    for (int i = 0; i < MAX_TASK; i++) {
        list->tasks[i].isDone = 0;
    }
}

void addTask(struct List *list, const char *task) {

}