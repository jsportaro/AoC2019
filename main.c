#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) 
{
    FILE *fuel = NULL;
    char *fuel_count = NULL;
    size_t fuel_length = 0;
    ssize_t read = 0;
    int32_t sum = 0;

    if ((fuel = fopen("input.txt", "r")) == NULL)
    {
        printf("Welp, messed that up...\n");

        exit(1);
    }

    while ((read = getline(&fuel_count, &fuel_length, fuel)) != -1 )
    {   
        printf("%s", fuel_count);

        sum += (atof(fuel_count) / 3.0F) - 2;
    }

    fclose(fuel);

    printf("%d\n", sum);

    exit(EXIT_SUCCESS);
}
