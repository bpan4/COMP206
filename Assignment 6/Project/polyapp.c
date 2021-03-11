/*
Purpose: receives a text as input and constructs a polynomial
***************************************************************
* Author        Dept            Date            Notes
***************************************************************
* Belle P       Science         Apr 11 2020     Iinitial version
* Belle P	Science		Apr 11 2020	Added function call parse from utils.h
* Belle P	Science		Apr 13 2020	Included poly.h and utilized functions displayPolynomial, addPolyTerm, and evaluatePolynomical
* Belle P	Science		Apr 13 2020	Fixed syntactic error with exit`
*/

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "poly.h"

int main(int argc, char *argv[]){
	if (argc == 1){
		fprintf(stderr,"Usage: ./polyapp FILENAME");
		exit(1);
	}
	head = (struct PolyTerm*)malloc(sizeof(struct PolyTerm));
	int first = 0;
	FILE *file = fopen(argv[1], "r+");
	char buf[100];
	int co, ex;
	while(fgets(buf,99,file)!=NULL){
		if (first==0){//initializes head if this is the first element passed to the while loop
			parse(buf,&co,&ex);
			head->coeff=co;
			head->expo=ex;
			head->next=NULL;
		} else {
			parse(buf,&co,&ex); //from utils.h
			if (addPolyTerm(co,ex)==-1){
				printf("Error: no memory left for this process");
				exit(1);
			}
		}
		first=1;
        }
	displayPolynomial();
	for (int i=-2;i<=2;i++){
		printf("for x=%d, y=%d\n", i, evaluatePolynomial(i));
	}
}
