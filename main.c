#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MemoryManager/Include/MemoryManager.h"
#include "MemoryManager/DataStructures/Include/LinkedList.h"

void print_help() {
    printf("Commands:\n");
    printf("  help         Display this help message\n");
    printf("  hello        Greet the user with a slight intro\n");
    printf("  malloc {0}   Allocate memory on the created memory manager.\n");
    printf("  free {0}     free memory on the created memory manager.\n");
    printf("  dump         dump the memory manager to the console.\n");
    printf("  quit         quit the program\n");
}


int main() {
    char command[100];
    LIST *memoryManager = initMemory(30000);
    NODE *tempHolder;
    while (1) {
        printf(">: ");
        fgets(command, 100, stdin);
        command[strcspn(command, "\n")] = 0; // remove trailing newline

        if (strcmp(command, "hello") == 0) {
                printf("Hello, I am a memory manager simulation. I can show you how your operating systems\n "
                       "memory manager will manage your memory of applications running.\n");
        }
        else if (strcmp(command, "free") == 0) {
            freeMemoryLocation(memoryManager,h); // need to get user input
        }
        else if (strcmp(command, "malloc") == 0) {
           tempHolder = Malloc(memoryManager,0x1000);
           printf("Memory Address: %p", tempHolder);
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
