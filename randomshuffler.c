#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int arr[], int n)
{
    srand(time(NULL)); // seed the random number generator with the current time
    for (int i = n - 1; i > 0; i--)
        {
        int j = rand() % (i + 1); // generate a random index between 0 and i (inclusive)
        int temp = arr[i]; // swap arr[i] with arr[j]
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main()
 {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    shuffle(arr, n);

    printf("Shuffled array: ");
    for (int i = 0; i < n; i++)
        {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

