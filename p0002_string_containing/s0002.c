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


static uint32_t naive_containing_test(char *str_a, char *str_b);

int main(void)
{
	const char *a_str = "abcdefghijklmn";
	const char *b_str = "ghijk";
	uint32_t ret_code;

	ret_code = naive_containing_test(a_str, b_str);
	printf("A: %s, B: %s, INCLUDED %s\n", a_str, b_str, (re_code==0) ? "False" : "True");

	return 0;
}

static uint32_t naive_containing_test(char *str_a, char *str_b)
{
	return 0;
}