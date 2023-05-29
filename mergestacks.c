#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
 {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
     {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
        {
        if (L[i] <= R[j])
         {
            arr[k] = L[i];
            i++;
        } else
         {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
        {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
        {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r)
 {
    if (l < r)
        {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    char input_filename[100], output_filename[100];
    int arr[1000], n, i;

    printf("Enter the input filename: ");
    scanf("%s", input_filename);

    printf("Enter the output filename: ");
    scanf("%s", output_filename);

    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");

    if (input_file == NULL)
        {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    if (output_file == NULL)
        {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    fscanf(input_file, "%d", &n);
    for (i = 0; i < n; i++)
        {
        fscanf(input_file, "%d", &arr[i]);
    }

    fprintf(output_file, "The unsorted array is:\n");
    for (i = 0; i < n; i++)
        {
        fprintf(output_file, "%d ", arr[i]);
    }

    merge_sort(arr, 0, n - 1);

    fprintf(output_file, "\n\nThe sorted array is:\n");
    for (i = 0; i < n; i++)
        {
        fprintf(output_file, "%d ", arr[i]);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Sorting complete. Output written to %s.\n", output_filename);

    return 0;
}
