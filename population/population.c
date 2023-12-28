#include <cs50.h>
#include <stdio.h>

int main() {
    int starting_population, ending_population;
    int population = 0;
    int years = 0;


    while (1) {
        printf("Enter the starting population size: ");
        if (scanf("%d", &starting_population) == 1 && starting_population >= 9) {
            break;
        } else {
            printf("Population size must be at least 9. Please try again.\n");
            // Clear the input buffer
            while (getchar() != '\n');
        }
    }


    while (1) {
        printf("Enter the ending population size: ");
        if (scanf("%d", &ending_population) == 1 && ending_population >= starting_population) {
            break;
        } else {
            printf("Ending population size must be greater than or equal to the starting population size. Please try again.\n");

            while (getchar() != '\n');
        }
    }


    population = starting_population;
    while (population < ending_population) {
        population += population / 3 - population / 4;
        years++;
    }

    printf("Years: %d\n", years);

    return 0;
}
