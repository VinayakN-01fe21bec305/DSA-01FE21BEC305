#include <stdio.h>

#define MAX_SIZE 100

int maxSubArraySum(int arr[], int n)
{
    int max_so_far = -1e9, max_ending_here = 0;
    for (int i = 0; i < n; i++)
        {
        max_ending_here += arr[i];
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
        }
        if (max_so_far < max_ending_here)
         {
            max_so_far = max_ending_here;
        }
    }
    return max_so_far;
}

int main()
 {
    int arr[MAX_SIZE], n;
    FILE *in = fopen("input.txt", "r");
    fscanf(in, "%d", &n);
    for (int i = 0; i < n; i++)
        {
        fscanf(in, "%d", &arr[i]);
    }
    fclose(in);

    int max_sum = maxSubArraySum(arr, n);

    FILE *out = fopen("output.txt", "w");
    fprintf(out, "%d\n", max_sum);
    fclose(out);

    return 0;
}

