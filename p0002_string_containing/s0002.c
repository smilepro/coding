// Problem 2: http://blog.csdn.net/v_JULY_v/article/details/6347454
// Problem Statement
// Assume there are two strings String 1 and String 2 consisting of letters of an alphabet, but the number of letters in B is less than that in A.
// Is there a quick way to determine whether all the letters of B are also included in B?
// Examples:
// String 1: ABCDEFGHLMNOPQRS
// String 2: DCGSRQPO
// Answer is True
//
// String 1: ABCDEFGHLMNOPQRS
// String 2: DCGSRQPZ
// Answer is False, since Z in String 2 is not included in String 1
//
//
//
//
// Lei Tian, <leitian.hust@gmail.com>
//

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

static uint32_t naive_containing_test(char *str_a, char *str_b);
static uint32_t map_containing_test(char *str_a, char *str_b);


int main(void)
{
	char *a_str = "abcdefghijklmn";
	char *b_str = "ghijkz";
	uint32_t ret_code;

	ret_code = naive_containing_test(a_str, b_str);
	printf("A: %s, B: %s, INCLUDED: %s\n", a_str, b_str, (ret_code==0) ? "False" : "True");

    ret_code = map_containing_test(a_str, b_str);
	printf("A: %s, B: %s, INCLUDED: %s\n", a_str, b_str, (ret_code==0) ? "False" : "True");

    return 0;
}

static uint32_t naive_containing_test(char *str_a, char *str_b)
{
    int i, j;

    for (i = 0; i < strlen(str_b); i++){
        for (j = 0; j < strlen(str_a); j++){
            if (str_b[i] != str_a[j])
                continue;
            else
                break;
        }
        if (j >= strlen(str_a))
            return 0;
    }

	return 1;
}

static uint64_t str_2_map(char *str)
{
    int i;
    int offset;
    uint64_t map = 0;

    for (i = 0; i < strlen(str); i++){
        offset = str[i] - 'a';
        assert(offset >= 0);

        map = map | (1 << offset);
    }

    return map;
}

// the basic idea behind this method, is to map the characters to different bits in an integer
// then we can use a comparison of two mapped integers to determine whether or not a contains b
// overhead: requires two map operations, comparison of two integers is easy.
static uint32_t map_containing_test(char *str_a, char *str_b)
{
    uint64_t a_map = 0, b_map = 0;

    a_map = str_2_map(str_a);
    b_map = str_2_map(str_b);

    printf("str a map: %llu str b map: %llu\n", a_map, b_map);
    return (((a_map | b_map) == a_map)? 1 : 0);
}
