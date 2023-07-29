#include <stdio.h>
#include <cs50.h>

int main(void){
    int l = 0;
    do{
        printf("Height: ");
        scanf("%i", &l);
    }while(l > 8 || l < 1);
    int start = l;
    for (int i = 0 ; i < l; i++){
        for (int j = 0; j < start-1; j++){
            printf(" ");
        }
        for (int p = 0; p < i+1; p++){
            printf("#");
        }
        printf("  ");
        for (int z = 0; z < i+1; z++){
            printf("#");
        }
        printf("\n");
        start--;
    }
}