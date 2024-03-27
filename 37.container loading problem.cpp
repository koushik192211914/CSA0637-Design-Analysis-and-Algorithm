#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

// Function to find the best combination of items that can be loaded into the container
void container_loader(int items[][3], int num_items, int container_capacity) {
    int best_combination[MAX_ITEMS];
    int best_remaining_space = container_capacity;
    int combination[MAX_ITEMS];

    // Generate all possible combinations of items
    for (int i = 0; i < num_items; i++) {
        for (int j = 0; j < num_items; j++) {
            for (int k = 0; k < num_items; k++) {
                // Calculate total volume of the combination
                int total_volume = items[i][0] + items[j][1] + items[k][2];
                int remaining_space = container_capacity - total_volume;

                // If total volume exceeds container capacity, skip this combination
                if (total_volume > container_capacity)
                    continue;

                // If remaining space is less than best remaining space, update best combination
                if (remaining_space < best_remaining_space) {
                    best_remaining_space = remaining_space;
                    best_combination[0] = items[i][0];
                    best_combination[1] = items[j][1];
                    best_combination[2] = items[k][2];
                }
            }
        }
    }

    // Print the best combination found
    printf("Best combination: [%d, %d, %d]\n", best_combination[0], best_combination[1], best_combination[2]);
}

int main() {
    int items[MAX_ITEMS][3] = {{2, 3, 4}, {1, 2, 3}, {3, 4, 5}};
    int num_items = 3;
    int container_capacity = 10;

    container_loader(items, num_items, container_capacity);

    return 0;
}
