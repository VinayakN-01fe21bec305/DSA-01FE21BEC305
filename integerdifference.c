#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
 {
    // Open input file
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL)

        {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int num1, num2, min_num1, min_num2, min_diff = INT_MAX;
    while (fscanf(input_file, "%d", &num1) == 1)
        {
        // Compare num1 to each subsequent number in the file
        fseek(input_file, 0, SEEK_SET); // Move file pointer back to beginning
        while (fscanf(input_file, "%d", &num2) == 1)
        {
            if (num1 != num2)
             {
                int diff = abs(num1 - num2);
                if (diff < min_diff)
                {
                    min_num1 = num1;
                    min_num2 = num2;
                    min_diff = diff;
                }
            }
        }
    }

    // Close input file
    fclose(input_file);

    // Open output file
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL)
        {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write result to output file
    fprintf(output_file, "The pair of numbers with smallest absolute difference is %d and %d, with a difference of %d\n", min_num1, min_num2, min_diff);

    // Close output file
    fclose(output_file);

    return 0;
}

