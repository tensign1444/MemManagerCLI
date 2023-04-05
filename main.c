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


int main() {
    char command[100];
    LIST *memoryManager = initMemory(300050);
    while (1) {
        printf(">: ");
        fgets(command, 100, stdin);
        command[strcspn(command, "\n")] = 0; // remove trailing newline

        char cmd[20];
        sscanf(command, "%s", cmd); // extract first word

        char* token = strtok(command, " ");
        token = strtok(NULL, " ");

        size_t second_arg = strtoul(token, NULL, 10);
        if (strcmp(cmd, "hello") == 0) {
                printf("Hello, I am a memory manager simulation. I can show you how your operating systems\n "
                       "memory manager will manage your memory of applications running.\n");
        }
        else if (strcmp(cmd, "free") == 0) {
            freeMemoryLocation(memoryManager, second_arg);
        }
        else if (strcmp(cmd, "malloc") == 0) {
            Malloc(memoryManager,second_arg);
        }
        else if (strcmp(cmd, "dump") == 0) {
            DumpMemoryList();
        }
        else if (strcmp(cmd, "help") == 0) {
            print_help();
        }
        else if (strcmp(cmd, "quit") == 0) {
            break;
        } else {
            printf("Unknown command: %s\n", cmd);
        }
    }

    return 0;
}
