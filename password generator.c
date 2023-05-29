#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int length, i;
    printf("Enter the length of the password: ");
    scanf("%d", &length);

    // Array of characters to use for generating the password
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+-=[]{}|;:,.<>?";

    // Get the number of characters available
    int num_characters = sizeof(characters) - 1;

    // Seed the random number generator
    srand(time(NULL));

    // Generate the password
    char password[length+1];
    for (i = 0; i < length; i++)
        {
        password[i] = characters[rand() % num_characters];
    }
    password[length] = '\0';

    // Print the password
    printf("Password: %s\n", password);

    return 0;
}

