#include "headers.h"

int main()
{
    int num_ver;
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
        printf("\n\n");
        printf("Available functions are the follwing:\n");
        printf("1. Show the graph (print it on the screen)\n");
        printf("2. Create a unidirectional edge\n");
        printf("3. Create a bidirectional edge\n");
        printf("4. Delete a unidirectional edge\n");
        printf("5. Delete a bidirectional edge\n");
        printf("6. Add a node (vertex)\n");
        printf("7. Delete a node(vertex)\n");
        printf("8. Exit function\n");
        printf("\nEnter command no. : ");

        int inp;

        scanf("%d", &inp);

        printf("\n\n");

        if(inp == 1) {
            printGraph(G);
        }
        else if (inp == 2) {
            int src, dest, weight;
            printf("Enter the source vertex: ");
            scanf("%d", &src);
            printf("Enter the destination vertex: ");
            scanf("%d", &dest);
            printf("Enter the weight of the edge: ");
            scanf("%d", &weight);
            newEdge(G, src, dest, weight);
        }
        else if (inp == 3) {
            int src, dest, weight;
            printf("Enter the first vertex: ");
            scanf("%d", &src);
            printf("Enter the second vertex: ");
            scanf("%d", &dest);
            printf("Enter the weight of the edge: ");
            scanf("%d", &weight);
            newEdge(G, src, dest, weight);
            newEdge(G, dest, src, weight);
        }
        else if (inp == 4) {
            int src, dest, weight;
            printf("Enter the source vertex: ");
            scanf("%d", &src);
            printf("Enter the destination vertex: ");
            scanf("%d", &dest);
            deleteEdge(G, src, dest);
        }
        else if (inp == 5) {
            int src, dest, weight;
            printf("Enter the first vertex: ");
            scanf("%d", &src);
            printf("Enter the second vertex: ");
            scanf("%d", &dest);
            deleteEdge(G, src, dest);
            deleteEdge(G, dest, src);
        }
        else if (inp == 6) {

        }
        else if (inp == 7) {

        }
        else if (inp == 8) {
            exitFunction(G);
        }
        else {
            printf("Enter a valid number. Please try again\n");
        }
    }

    return(0);

}
