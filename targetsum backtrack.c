#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int numbers[SIZE];
int solution[SIZE];
int size;
int target_sum;

int backtrack(int index, int current_sum)
 {
    if (current_sum == target_sum)
        {
        printf("Solution: ");
        for (int i = 0; i < index; i++)
         {
            printf("%d ", solution[i]);
        }
        printf("\n");
        return 1;
    }

    if (index == size)
        {
        return 0;
    }

    solution[index] = numbers[index];
    if (backtrack(index + 1, current_sum + numbers[index])) {
        return 1;
    }

    solution[index] = 0;
    if (backtrack(index + 1, current_sum))
        {
        return 1;
    }

    return 0;
}

int main()
 {
    FILE *file;
    int found = 0;

    file = fopen("numbers.txt", "r");
    if (file == NULL)
        {
        printf("Error: Unable to open file\n");
        return 1;
    }

    // Read numbers from file
    while (!feof(file))
        {
        fscanf(file, "%d", &numbers[size++]);
    }
    size--;

    fclose(file);

    // Set target sum
    target_sum = 10;

    // Find first solution
    found = backtrack(0, 0);

    if (!found)
        {
        printf("No solution found\n");
    }

    return 0;
}
