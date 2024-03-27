#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define N 4 
void assignTask(int costMatrix[N][N], int assignment[N], bool assigned[N], int cost, int agent, int *minCost) {
    if (agent == N) {
        if (cost < *minCost)
            *minCost = cost;
        return;
    }
    if (cost >= *minCost)
        return;
    for (int task = 0; task < N; task++) {
        if (assigned[task])
            continue;
        assigned[task] = true;
        int newCost = cost + costMatrix[agent][task];
        assignTask(costMatrix, assignment, assigned, newCost, agent + 1, minCost);
        assigned[task] = false;
    }
}
int solveAssignmentProblem(int costMatrix[N][N]) {
    int assignment[N]; // To store the final assignment
    bool assigned[N];  // To keep track of assigned tasks
    int minCost = INT_MAX; // Initialize minimum cost with maximum value
    for (int i = 0; i < N; i++)
        assigned[i] = false;
    assignTask(costMatrix, assignment, assigned, 0, 0, &minCost);
    return minCost;
}

int main() {
    int costMatrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };
    int minCost = solveAssignmentProblem(costMatrix);
    printf("Minimum cost of assignment: %d\n", minCost);
    return 0;
}
