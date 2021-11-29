#include "headers.h"

int main()
{
    total_nodes = 0;
    int num_ver;
    ptrgraph G;
    int chosen;

    printf("Hi there!\nPlease follow the commands\n\n");

    printf("Do you want to create a new graph from scratch (0) or want to check the functionalities using a pre-build default graph (1)\nEnter 0 or 1: ");

    scanf("%d", &chosen);

    if (chosen == 0)
    {
        printf("Enter the size of graph you want to create (no.of vertices)\n");

        scanf("%d", &num_ver);

        if (num_ver <= 0)
        {
            printf("Please execute the file again and enter a valid number greater than equal to zero\nThank you\n");
        }

        G = createGraph(num_ver);

        total_nodes = num_ver;

        printf("A graph with vertices ");

        for (int i = 0; i < num_ver; i++)
        {
            printf("%d ", i);
        }

        printf("is created\n\n");
    }
    else if (chosen == 1)
    {
        G = createGraph(5);
        total_nodes = 5;
        printf("The default graph is as follows\n");
        printGraph(G);
    }
    else
    {
        printf("Run the program again and enter a valid number\n");
    }

    for (;;)
    {
        printf("\n\n");
        printf("Available functions are the follwing:\n");
        printf("1. Show the graph (print it on the screen)\n");
        printf("2. Create a unidirectional edge\n");
        printf("3. Create a bidirectional edge\n");
        printf("4. Delete a unidirectional edge\n");
        printf("5. Delete a bidirectional edge\n");
        printf("6. Add a node (vertex)\n");
        // printf("7. Delete a node(vertex)\n");
        printf("7. Run DFS for the whole graph\n");
        printf("8. Run DFS starting from a vertex\n");
        printf("9. Run BFS for the whole graph\n");
        printf("10. Run BFS starting from a vertex\n");
        printf("11. Run Dijkstra from a vertex\n");
        printf("12. Run Bellman ford from a vertex\n");
        printf("13. Exit function\n");
        printf("\nEnter command no. : ");

        int inp;

        scanf("%d", &inp);

        printf("\n\n");

        if (inp == 1)
        {
            printGraph(G);
        }
        else if (inp == 2)
        {
            int src, dest, weight;
            printf("Enter the source vertex: ");
            scanf("%d", &src);
            printf("Enter the destination vertex: ");
            scanf("%d", &dest);
            printf("Enter the weight of the edge: ");
            scanf("%d", &weight);
            newEdge(G, src, dest, weight);
        }
        else if (inp == 3)
        {
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
        else if (inp == 4)
        {
            int src, dest, weight;
            printf("Enter the source vertex: ");
            scanf("%d", &src);
            printf("Enter the destination vertex: ");
            scanf("%d", &dest);
            deleteEdge(G, src, dest);
        }
        else if (inp == 5)
        {
            int src, dest, weight;
            printf("Enter the first vertex: ");
            scanf("%d", &src);
            printf("Enter the second vertex: ");
            scanf("%d", &dest);
            deleteEdge(G, src, dest);
            deleteEdge(G, dest, src);
        }
        else if (inp == 6)
        {
            int choice;
            printf("Do you want to create a vertex with ID %d. Enter 0 or 1", total_nodes);
            scanf("%d", &choice);
            if (choice == 1)
            {
                newVertex(G, total_nodes);
            }
            // else
            // {
            //     int num;
            //     printf("Enter the vertex ID you previously deleted and want to crete again: ");
            //     scanf("%d", &num);
            //     if (num < 0 || num >= total_nodes || G->gr[num].status != -1)
            //     {
            //         printf("Enter proper vertex ID\n");
            //     }
            //     else
            //     {
            //         G->gr[num].status = 0;
            //     }
            // }
        }
        // else if (inp == 7)
        // {
        //     int num;
        //     printf("Enter the vertex ID: ");
        //     scanf("%d", &num);
        //     if(num == 0)
        //     {
        //         printf("You cannot delete vertex number 0. Try deleting another vertex\n");
        //     }
        //     else
        //     {
        //         deleteVertex(G, num);
        //     }
        // }
        else if (inp == 7)
        {
            dfs_init(G);
        }
        else if (inp == 8)
        {
            int num;
            printf("Enter the vertex ID from which you want to start DFS: ");
            scanf("%d", &num);
            dfs_init2(G, num);
        }
        else if (inp == 9)
        {
            bfs_init(G);
        }
        else if (inp == 10)
        {
            int num;
            printf("Enter the vertex ID from which you want to start DFS: ");
            scanf("%d", &num);
            bfs_init2(G, num);
        }
        else if (inp == 11)
        {
            int num;
            printf("Enter the vertex ID from which you want to start Dijkstra: ");
            scanf("%d", &num);
            if (num < 0 || num >= total_nodes || G->gr[num].status == -1)
            {
                printf("Enter proper vertex ID\n");
            }
            else
            {
                dijkstra(G, num);
            }
        }
        else if (inp == 12)
        {
            int num;
            printf("Enter the vertex ID from which you want to start Bellman ford algorithm: ");
            scanf("%d", &num);
            if (num < 0 || num >= total_nodes || G->gr[num].status == -1)
            {
                printf("Enter proper vertex ID\n");
            }
            else
            {
                bellman_ford(G, num);
            }
        }
        else if (inp == 13)
        {
            exitFunction(G);
        }
        else
        {
            printf("Enter a valid number. Please try again\n");
        }
    }
    return (0);
}
