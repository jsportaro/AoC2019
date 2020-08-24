#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t fuel_by_weight(double weight)
{
    return floor((weight / 3.0F)) - 2;
}

int main(void) 
{
    FILE *fuel = NULL;
    char *fuel_count = NULL;
    size_t fuel_length = 0;
    ssize_t read = 0;
    int32_t sum = 0;

    if ((fuel = fopen("DayOne_Input.txt", "r")) == NULL)
    {
        printf("Welp, messed that up...\n");

        exit(1);
    }

    double module_fuel = 0;
    double fuel_fuel = 0;
    while ((read = getline(&fuel_count, &fuel_length, fuel)) != -1 )
    {   
        double module_fuel = fuel_by_weight(atof(fuel_count));
        sum += module_fuel;
        fuel_fuel = module_fuel;
        while ((fuel_fuel = fuel_by_weight(fuel_fuel)) > 0)
        {
            sum += fuel_fuel;
        }
    }

    fclose(fuel);

    printf("%d\n", sum);

    exit(EXIT_SUCCESS);
}
