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

    while (1) {
        printf(">: ");
        fgets(command, 100, stdin);
        command[strcspn(command, "\n")] = 0; // remove trailing newline

        if (strcmp(command, "hello") == 0) {
                printf("Hello, I am a memory manager simulation. I can show you how your operating systems\n "
                       "memory manager will manage your memory of applications running.\n");
        }
        else if (strcmp(command, "free") == 0) {
            freeNode(NODE* H); // need to get user input
        }
        else if (strcmp(command, "malloc") == 0) {
            Malloc(0x1000);
        }
        else if (strcmp(command, "dump") == 0) {
            DumpMemoryList();
        }
        else if (strcmp(command, "help") == 0) {
            print_help();
        }
        else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}

re
