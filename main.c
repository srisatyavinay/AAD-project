#include "headers.h"

int main()
{
    num_ver = 0;
    ptrgraph G;

    printf("Hi there!\nPlease follow the commands\n\n");

    printf("Enter the size of graph you want to create (no.of vertices)\n");

    scanf("%d", &num_ver);

    if(num_ver <= 0) {
        printf("Please execute the file again and enter a valid number greater than equal to zero\nThank you\n");
    }

    G = createGraph(num_ver);

    printf("A graph with vertices ");

    for(int i = 0; i < num_ver; i++) {
        printf("%d ", i);
    }

    printf("is created\n\n");

    for(;;) {
        printf("Available functions are the follwing:\n");
        printf("1. Show the graph (print it on the screen)");
        printf("2. Create a unidirectional edge\n");
        printf("3. Create a bidirectional edge\n");
        printf("4. Delete an edge\n");
        printf("5. Add a node (vertex)\n");
        printf("6. Delete a node(vertex)\n");
        printf("7. Exit function\n");

        int inp;

        scanf("%d", &inp);

        if(inp == 1) {
            
        }
        else if (inp == 2) {

        }
        else if (inp == 3) {

        }
        else if (inp == 4) {

        }
        else if (inp == 5) {

        }
        else if (inp == 6) {

        }
        else if (inp == 7) {

        }
        else {

        }
    }

    return(0);

}
