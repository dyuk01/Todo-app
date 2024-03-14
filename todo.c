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
    if (list->count < MAX_TASK) {
        strcpy(list->tasks[list->count].desc, task);
        list->count++;
    }
    else {
        printf("List is full!\n");
    }
}

void removeTask(struct List *list, const char *task) {
    int flag = 0;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->tasks[i].desc, task) == 0) {
            strcpy(list->tasks[i].desc, "");
            list->tasks[i].isDone = 0;
            flag++;
        }
    }
    if (flag == 0) {
        printf("Task cannot be found!\n");
    }    
}

void mark(struct List *list, int index) {
    if (index > 0 && index < list->count) {
        if (!list->tasks[index].isDone) {
            list->tasks[index].isDone = 1;
            printf("Task marked : %s\n", list->tasks[index].desc);
        }
        else {
            printf("Task already marked!\n");
        }
    }
    else {
        printf("Incorrect Index!\n");
    }
}

void unMark(struct List *list, int index) {
    if (index > 0 && index < list->count) {
        if (list->tasks[index].isDone) {
            list->tasks[index].isDone = 0;
            printf("Task unmarked : %s\n", list->tasks[index].desc);
        }
        else {
            printf("Task already unmarked!\n");
        }
    }
    else {
        printf("Incorrect Index!\n");
    }
}