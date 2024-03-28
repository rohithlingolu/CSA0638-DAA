#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 4 
int findMin(int dist[], bool visited[]) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < N; v++)
        if (visited[v] == false && dist[v] <= min)
            min = dist[v], minIndex = v;
    return minIndex;
}
void printSolution(int assignment[], int cost) {
    printf("Minimum cost: %d\n", cost);
    printf("Assignments:\n");
    for (int i = 0; i < N; i++)
        printf("Worker %d -> Task %d\n", i, assignment[i]);
}
void minCost(int cost[N][N]) {
    int assignment[N]; 
    bool visited[N];   
    int dist[N];       
    for (int i = 0; i < N; i++)
        assignment[i] = -1;
    for (int i = 0; i < N; i++)
        visited[i] = false;
    int totalCost = 0;
    for (int i = 0; i < N; i++)
        dist[i] = INT_MAX;
    for (int count = 0; count < N; count++) {
        int u = findMin(dist, visited);
        visited[u] = true;
        for (int v = 0; v < N; v++) {
            if (!visited[v] && cost[u][v] < dist[v]) {
                dist[v] = cost[u][v];
                assignment[v] = u;
            }
        }
    }

   
    for (int i = 0; i < N; i++)
        totalCost += cost[assignment[i]][i];
    printSolution(assignment, totalCost);
}

int main() {
    
    int cost[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    minCost(cost);

    return 0;
}


