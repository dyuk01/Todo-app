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

void listTask(const struct List *list) {
    if (list->count == 0) {
        printf("List is empty!\n");
    } 
    else {
        printf("Todo list : \n");
        for (int i = 0; i < list->count; i++) {
            printf("%d, [%s] %s\n", i + 1, list->tasks[i].isDone ? 
                "Done" : "", list->tasks[i].desc);
        }
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
    index -= 1;
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

void main() {
    struct List list;
    init(&list);
    int choice;
    char task[MAX_TASK_LENGTH];
    int index;

    while(1) {
        printf("\nTodo list Application\n");
        printf("1. List Task\n");
        printf("2. Add Task\n");
        printf("3. Remove Task\n");
        printf("4. Mark Task\n");
        printf("5. Unmark Task\n");
        printf("6. Quit Application\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            listTask(&list);
            break;
        case 2:
            printf("Enter the task description : ");
            getchar();
            fgets(task, sizeof(task), stdin);
            task[strcspn(task, "\n")] = '\0';
            addTask(&list, task);
            break;
        case 3:
            printf("Enter the task description : ");
            getchar();
            fgets(task, sizeof(task), stdin);
            removeTask(&list, task);
            break;
        case 4:
            printf("Enter the index number to mark : ");
            scanf("%d", &index);
            mark(&list, index);
            break;
        case 5:
            printf("Enter the index number to unmark : ");
            scanf("%d", &index);
            unMark(&list, index);
            break;
        case 6:
            printf("Quitting...\n");
            exit(0);
        default:
            printf("Incorrect choice! Try again.\n");
            break;
        }
    }
}