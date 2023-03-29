#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_help() {
    printf("Commands:\n");
    printf("  help      Display this help message\n");
    printf("  hello     Greet the user\n");
    printf("  quit      quit the program\n");
}


int main() {
    char command[100];

    while (1) {
        printf(">: ");
        fgets(command, 100, stdin);
        command[strcspn(command, "\n")] = 0; // remove trailing newline

        if (strcmp(command, "hello") == 0) {
                printf("Hello World.\n");
        }
        else if (strcmp(command, "help") == 0 || strcmp(command, "h") == 0) {
            print_help();
        }
        else if (strcmp(command, "quit") == 0 || strcmp(command, "q") == 0) {
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}
