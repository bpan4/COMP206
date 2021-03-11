/*
 * Program to implement a simple calculator
 ***********************************************************************
 * Author	Dept.		Date		Notes
 ***********************************************************************
 * Belle P	Science		Feb 18 2020	Initial version
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
	int min_num_arg=4;
	if (argc<min_num_arg) {
		puts("Error: Usage is simplecalc <x> <op> <y>");
		exit(1);
	}
	const int first=atoi(argv[1]);
	const char op=*argv[2];
	const int third=atoi(argv[3]);
	int value=0;
	switch(op) {
		case '+':;
			value=first+third;
			break;
		case '-':;
			value=first-third;
			break;
		case '*':;
			value=(first)*(third);
			break;
		case '/':;
			value=first/third;
			break;
		default :;
			printf("%s not a valid operator\n", &op);
			exit(2);
	}
	printf("%d\n", value);
	exit(0);
}

