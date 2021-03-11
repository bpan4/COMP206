//#include "poly.c"

struct PolyTerm{
	int coeff;
	int expo;
	struct PolyTerm *next;
} *head;
//linked list used to store polynomials of arbitrary length
//head hold the first element of the list
//next is used to traverse through the list
int addPolyTerm(int co, int ex); 
//assimilates a term with coefficient co and exponent ex into the linked list
//order of linked list is from lowest to highest degree
//polynomials with the same degree are summed and presesnted as one term
//function returns 0 if successful and -1 if not (not enough memory)
void displayPolynomial();
//displays the polynomial expression based on the order of the linked list
int evaluatePolynomial(int x);
//computes the value of the polynomial expression with x as the value of the variable using powi from utils.h
//returns the value determined
