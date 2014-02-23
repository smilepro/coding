// define left shift operation for strings: move characters at the head of a string to the end of string
// for example: adcdef => cdefab
// implement a function to do left shift operations for strings, time complexity must be O(n), and space complexity must be O(1).
//

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

static int naive_left_shift(char *str, uint32_t str_len, uint32_t shift_len);
static int swap_left_shift(char *str, uint32_t str_len, uint32_t shift_len);

int main(void)
{
    const char *example_str = "abcdefghijklmn";
    char *my_str = NULL;
    uint32_t str_len = 0;
    uint32_t shift_len = 0;
    int ret_code = 0;

    printf("s0000: string left shift operation\n");

    str_len = strlen(example_str);
    my_str = (char*)malloc(str_len);
    if (!my_str){
         printf("s0000: memory allocation failed!");
         return 1;
    }

    shift_len = 12;
    shift_len = shift_len % str_len;
    if (shift_len == 0)
        return 0;

    strcpy(my_str, example_str);
    printf("old str %s, len %u, shift len %u\n", my_str, str_len, shift_len);
    ret_code = naive_left_shift(my_str, str_len, shift_len);
    printf("naive shift: new str %s, len %u, char shift num %u\n", my_str, str_len, ret_code);

    strcpy(my_str, example_str);
    ret_code = swap_left_shift(my_str, str_len, shift_len);
    printf("swap shift: new str %s, len %u, char shift num %u\n", my_str, str_len, ret_code);

    if (!my_str)
        free(my_str);
    my_str = NULL;

    return 0;
}

static int naive_left_shift(char *str, uint32_t str_len, uint32_t shift_len)
{
    uint32_t i, j, num_shift_ops;
    char c_tmp;

    num_shift_ops = 0;
    for (i = 0; i < shift_len; i++){

        c_tmp = str[0];
        for (j = 0; j < (str_len-1); j++){
            str[j] = str[j+1];
            num_shift_ops++;
        }
        str[str_len-1] = c_tmp;
        num_shift_ops += 1;
    }

    return num_shift_ops;
}

static int swap_two_strings(char *a_str, uint32_t a_len, char *b_str, uint32_t b_len, char **new_a_str, uint32_t *pnew_a_len, char **new_b_str, uint32_t *pnew_b_len)
{
    char c_tmp;
    uint32_t num_shift_ops = 0;
    uint32_t i, swap_len, offset;

    swap_len = (a_len >= b_len) ? b_len: a_len;
    if (a_len >= b_len)
        offset = 0;
    else
        offset = b_len - a_len;
    for (i = 0; i < swap_len; i++){
        c_tmp = b_str[i+offset];
        b_str[i+offset] = a_str[i];
        a_str[i] = c_tmp;
        num_shift_ops++;
    }

    if (a_len == b_len){
        *new_a_str = NULL;
        *new_b_str = NULL;
        *pnew_a_len = 0;
        *pnew_b_len = 0;
    }else {
        if (a_len > b_len){
            *new_a_str = a_str + swap_len;
            *new_b_str = b_str;
            *pnew_a_len = a_len - swap_len;
            *pnew_b_len = swap_len;
        } else {
            *new_a_str = a_str;
            *new_b_str = a_str + swap_len;
            *pnew_a_len = swap_len;
            *pnew_b_len = b_len - swap_len;
        }
    }

    return num_shift_ops;
}

static int swap_left_shift(char *str, uint32_t str_len, uint32_t shift_len)
{
    uint32_t num_shift_ops = 0;
    char *p_a, *p_b, *p_new_a, *p_new_b;

    uint32_t a_len, b_len, new_a_len, new_b_len;

    p_a = str;
    p_b = str + (shift_len);
    a_len = shift_len;
    b_len = str_len - shift_len;
    p_new_a = NULL;
    p_new_b = NULL;
    new_a_len = 0;
    new_b_len = 0;

    while (1){
        num_shift_ops += swap_two_strings(p_a, a_len, p_b, b_len, &p_new_a, &new_a_len, &p_new_b, &new_b_len);
        printf("%u %u %s\n", new_a_len, new_b_len, str);
        if (p_new_a == NULL || p_new_b == NULL)
            break;

        p_a = p_new_a;
        p_b = p_new_b;
        a_len = new_a_len;
        b_len = new_b_len;
        p_new_a = NULL;
        p_new_b = NULL;
        new_a_len = 0;
        new_b_len = 0;
    }

    return num_shift_ops;
}


