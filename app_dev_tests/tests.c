#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//This is a test for Git conflict
int main(int argv, char* argc[]) {
    uint8_t* p_array, num;
    printf("please input the size of the array:");
    scanf("%hhu", &num);
    uint8_t array[num];
    p_array = (uint8_t*)calloc(5, sizeof(uint8_t));
    //      array = (uint8_t *)calloc(5,sizeof(uint8_t));

    for (uint8_t i = 0; i < 5; i++) {
        *(p_array + i) = i;
        array[i] = i;
        printf("p_array[%hhu] = %hhu | array[%hhu] = %hhu\n", i, *(p_array + i), i, array[i]);
    }
    return 0;
}