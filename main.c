#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MemoryManager/Include/MemoryManager.h"

void print_help() {
    printf("Commands:\n");
    printf("  help      Display this help message\n");
    printf("  hello     Greet the user with a slight intro\n");
    printf("  malloc    Allocate memory on the created memory manager.\n");
    printf("  free      free memory on the created memory manager.\n");
    printf("  dump      dump the memory manager to the console.\n");
    printf("  quit      quit the program\n");
}

void getMemorySize(int *value) {
    printf("Enter the amount of memory total you want: ");
    scanf("%d", value);
}

void getPointerToFree(void **ptr) {
    unsigned long long address;
    printf("Enter a memory address to free: ");
    scanf("%llx", &address);
    *ptr = (void *)address;
}

void greet_user() {
    printf("Hello, I am a memory manager simulation. I can show you how your operating systems\n "
           "memory manager will manage your memory of applications running.\n");
}

void handle_free(LIST *memoryManager) {
    void *pointer;
    getPointerToFree(&pointer);
    freeMemoryLocation(memoryManager, pointer);
    DumpMemoryList(memoryManager);
}

void handle_malloc(LIST *memoryManager, char *token) {
    char *endptr;
    size_t second_arg = strtoul(token, &endptr, 10);
    printf("Memory address: 0x%llx\n", (unsigned long long)Malloc(memoryManager, second_arg));
    DumpMemoryList(memoryManager);
}

int main() {
    const int MAX_COMMAND_LENGTH = 100;
    char command[MAX_COMMAND_LENGTH];
    int value;

    getMemorySize(&value);
    LIST *memoryManager = initMemory(value, false);

    while (1) {
        setvbuf(stdout, NULL, _IONBF, 0);
        printf(">: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // remove trailing newline

        char cmd[20];
        sscanf(command, "%s", cmd); // extract first word

        char* token = strtok(command, " ");
        token = strtok(NULL, " ");

        if (strcmp(cmd, "hello") == 0) {
            greet_user();
        }
        else if (strcmp(cmd, "free") == 0) {
            handle_free(memoryManager);
        }
        else if (strcmp(cmd, "malloc") == 0) {
            handle_malloc(memoryManager, token);
        }
        else if (strcmp(cmd, "dump") == 0) {
            DumpMemoryList(memoryManager);
        }
        else if (strcmp(cmd, "help") == 0) {
            print_help();
        }
        else if (strcmp(cmd, "quit") == 0) {
            freeMemory(memoryManager);
            break;
        }
        else {
            printf("Unknown command: %s\n", cmd);
        }
    }

    return 0;
}
