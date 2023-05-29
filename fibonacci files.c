#include <stdio.h>

int main()
{
    int n, i, a = 0, b = 1, c;
    FILE *fptr;


    fptr = fopen("fibonacci.txt", "w+");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    fprintf(fptr, "Fibonacci Series: ");

    for (i = 1; i <= n; i++)
        {
        fprintf(fptr, "%d, ", a);
        c = a + b;
        a = b;
        b = c;
    }


    fclose(fptr);

    return 0;
}
