#include <stdio.h>
    int numberOfVertices;

void printGraph(int adjMatrix[][numberOfVertices]){
    for(int i = 0; i < numberOfVertices;i++){
        for(int j = 0; j < numberOfVertices; j++){
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    
    int source,destination;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numberOfVertices);
    int adjMatrix [numberOfVertices][numberOfVertices]; // example 4by4 matrix
    
    // initializing the adjacency matrix by 0
    for(int i = 0; i < numberOfVertices ; i++)
        for (int j = 0 ; j<numberOfVertices ; j++)
            adjMatrix[i][j] = 0;
    
    while (source != -1 && destination !=-1)
    {
        printf("Enter source and destination vertices (-1 -1 to stop): ");
        scanf("%d %d", &source, &destination);

        adjMatrix[source][destination] = 1;       //Only this  for DirectedGraph
        // adjMatrix[destination][source] = 1;    //its for unDirectedGraph   
        }
 
    printGraph(adjMatrix);
    return 0;
}