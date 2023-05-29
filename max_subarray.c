#include <stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL)
        {
        printf("Failed to open file\n");
        return 1;
    }

    int n;
    fscanf(fp, "%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);

    int dp[n];
    dp[0] = arr[0];
    int max_sum = dp[0];

    for (int i = 1; i < n; i++)
        {
        dp[i] = (arr[i] > arr[i] + dp[i-1]) ? arr[i] : arr[i] + dp[i-1];
        if (dp[i] > max_sum)
        {
            max_sum = dp[i];
        }
    }

    fp = fopen("output.txt", "w");
    if (fp == NULL)
        {
        printf("Failed to open file\n");
        return 1;
    }

    fprintf(fp, "Maximum subarray sum: %d", max_sum);

    fclose(fp);

    return 0;
}

