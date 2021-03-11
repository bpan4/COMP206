
/*
Purpose: 
Function parse accepts a string two integer pointers as its argument. Parses a line that was retrieved using fgets from the main function and stores the coecient and exponent to the
address provided in the integer pointers.
Function powi accepts two integers as argument (x and exponent)and returns an integer which is x raised to the power of exponent
***************************************************************
* Author        Dept            Date            Notes
***************************************************************
* Belle P       Science         Apr 11 2020     Iinitial version
* Belle P       Science         Apr 13 2020     Fixed parse function by utilizing sscanf instead of atoi(strtok())
*/


#include<stdio.h>
#include <stdlib.h>
#include<string.h>


void parse(char *s,int *co, int *ex){
	sscanf(s,"%d %d", co, ex);
}

int powi(int x, int ex) {
	int result = 1;
	while (ex != 0) {
        	result *= x;
        	ex-=1;
	}
	return result;
}
