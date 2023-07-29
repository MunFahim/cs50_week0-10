#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int years = 0;
    int start = 0;
    int end = 0;
    // TODO: Prompt for start size
    while(start < 9){
        start = get_int("Start size: ");
    }
    // TODO: Prompt for end size
    while(end < start){
        end = get_int("End size: ");
    }
    // TODO: Calculate number of years until we reach threshold
    while(start < end){
        start = start + (start/3) - (start/4);
        years++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", years);
}
