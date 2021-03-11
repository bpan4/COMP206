/*
 * Purpose: creates a linked list used to store polynomials of arbitrary length
***************************************************************************
* Author        Dept            Date            Notes
***************************************************************
* Belle P       Science         Apr 11 2020     Iinitial version
* Belle P       Science         Apr 11 2020     Fixed struct pointer issues with updating fields
* Belle P	Science		Apr 13 2020	Fixed logic issue with addPolyTerm, finished displayPolynomials function
* Belle P	Science		Apr 13 2020	Finished evaluatePolynomial function
* Belle P	Science		Apr 13 2020	Fixed format of printed strings in displayPolynomial
*/
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


struct PolyTerm{
	int coeff;
	int expo;
	struct PolyTerm *next;
} *head; //global variable used to keep track of the linked list


int addPolyTerm(int co, int ex){
	struct PolyTerm *term=(struct PolyTerm*)malloc(sizeof(struct PolyTerm));
	if (term==NULL){
		return -1;
	}
	term->coeff = co;
	term->expo = ex;
	if (head==NULL){
		head=term;
	} else if (head!=NULL && head->expo > term->expo) {
		term->next=head;
		head=term;
	} else{
		struct PolyTerm* temp; //used to store info from the current head
		temp=head;
		while (temp->next!=NULL && temp->next->expo <= term->expo) {
			if (temp->next->expo==term->expo){
				temp->next->coeff+=term->coeff;
				return 0;
			}
			temp=temp->next;
		}
		term->next=temp->next;
		temp->next=term;
	}
	return 0;

}

void displayPolynomial(){
	struct PolyTerm* curr = head;
	while(curr!=NULL){
		printf("%dx%d",curr->coeff,curr->expo);
		if (curr->next!=NULL && curr->next->coeff>=0){
			printf("+");
		}else if (curr->next==NULL){
			printf("\n");
		}
		curr=curr->next;
	}
}

int evaluatePolynomial(int x){
	struct PolyTerm* curr = head;
	int total=0;
	while(curr!=NULL){
		total+=(curr->coeff)*(powi(x,curr->expo));
		curr=curr->next;
	}
	return total;
}


