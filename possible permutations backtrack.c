#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char *str, int start, int end, FILE *fp)
{
    if (start == end)
        {
        fprintf(fp, "%s\n", str);
        return;
    }

    for (int i = start; i <= end; i++)
        {
        swap(&str[start], &str[i]);
        permute(str, start + 1, end, fp);
        swap(&str[start], &str[i]);
    }
}

int main()
 {
    char filename[100], str[100];
    int n;

    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r+");
    if (fp == NULL)
        {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(fp, "%s", str);
    n = strlen(str);
    permute(str, 0, n - 1, fp);

    fclose(fp);

    printf("Permutations written to %s.\n", filename);

    return 0;
}
