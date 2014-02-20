// define left shift operation for strings: move characters at the head of a string to the end of string
// for example: adcdef => cdefab
// implement a function to do left shift operation for strings, time complexity must be O(n), and space complexity is O(1).
//

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

static int naive_left_shift(char *str, uint32_t str_len, uint32_t shift_len);

int main(void)
{
    const char *example_str = "abcdefghijklmn";
    char *my_str = NULL;
    uint32_t str_len = 0;
    uint32_t shift_len = 0;
    int retcode = 0;

    printf("s0000: string left shift operation\n");

    str_len = strlen(example_str);
    my_str = (char*)malloc(str_len);
    if (!my_str){
         printf("s0000: memory allocation failed!");
         return 1;
    }

    strcpy(my_str, example_str);

    printf("old str %s, len %u\n", my_str, str_len);

    shift_len = 15;
    shift_len = shift_len % str_len;
    retcode = naive_left_shift(my_str, str_len, shift_len);

    printf("new str %s, len %u, shift len %u\n", my_str, str_len, shift_len);

    if (!my_str)
        free(my_str);
    my_str = NULL;

    return retcode;
}

static int naive_left_shift(char *str, uint32_t str_len, uint32_t shift_len)
{
    uint32_t i, j;
    char c_tmp;

    for (i = 0; i < shift_len; i++){

        c_tmp = str[0];
        for (j = 0; j < (str_len-1); j++){
            str[j] = str[j+1];
        }
        str[str_len-1] = c_tmp;
    }

    return 0;
}
