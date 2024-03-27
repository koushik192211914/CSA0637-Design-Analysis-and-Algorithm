#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define N 4 // Number of agents/tasks (assuming square matrix)

// Function to find minimum cost assignment using Branch and Bound
void assignTask(int costMatrix[N][N], int assignment[N], bool assigned[N], int cost, int agent, int *minCost) {
    // Base case: All agents are assigned tasks
    if (agent == N) {
        if (cost < *minCost)
            *minCost = cost;
        return;
    }

    // Prune the branch if cost exceeds minimum cost found so far
    if (cost >= *minCost)
        return;

    // Try assigning the current agent to each task
    for (int task = 0; task < N; task++) {
        // Skip if the task is already assigned
        if (assigned[task])
            continue;

        // Mark the task as assigned and update the cost
        assigned[task] = true;
        int newCost = cost + costMatrix[agent][task];

        // Recursive call for the next agent
        assignTask(costMatrix, assignment, assigned, newCost, agent + 1, minCost);

        // Backtrack: Unmark the task
        assigned[task] = false;
    }
}

// Function to solve the Assignment Problem using Branch and Bound
int solveAssignmentProblem(int costMatrix[N][N]) {
    int assignment[N]; // To store the final assignment
    bool assigned[N];  // To keep track of assigned tasks
    int minCost = INT_MAX; // Initialize minimum cost with maximum value

    // Initialize assigned array
    for (int i = 0; i < N; i++)
        assigned[i] = false;

    // Start from the first agent
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
