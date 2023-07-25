#include <stdio.h>

int kmod10_hash(int num)
 {
    int hash = 0;

    while (num != 0)
        {
        hash = (hash * 10 + (num % 10)) % 10;
        num /= 10;
    }

    return hash;
}

int main()
 {
    int count;
    printf("Enter the number of input numbers: ");
    scanf("%d", &count);

    int numbers[count];
    printf("Enter the numbers:\n");
    for (int i = 0; i < count; i++)
    {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    printf("Calculating KMod10 hash...\n");
    for (int i = 0; i < count; i++)
    {
        int hash = kmod10_hash(numbers[i]);
        printf("Hash value for number %d: %d\n", numbers[i], hash);
    }

    return 0;
}
