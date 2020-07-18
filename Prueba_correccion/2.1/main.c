#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct node {
	int n;
	struct node *next;
} node;

node *head = NULL;

void push(char parentesis) {
	// crea un nuevo nodo vacio
	node *newptr = (node *)malloc(sizeof(node));

	// inicialización del nodo
	newptr->n = parentesis;
	newptr->next = NULL;

	// Verificando si la lista esta vacia
	if (head == NULL) {
		head = newptr;
	}
	// insertar al inicio
	else {
		newptr->next = head;
		head = newptr;
	}
}

void pop(void) {
	node *temp = head;
	if (temp != NULL) {			  // si existe una pila
		if (temp->next != NULL) { // si sigue existiendo una pila
			head = temp->next;
		} else { // si pila queda vacia
			head = NULL;
		}
		free(temp);
	} else {
		printf("Pila vacia (desde pop)\n");
	}
}

int isempty() {
	if (head != NULL) // si no esta vacia
	{
		return 0;
	} else { // si esta vacia
		return 1;
	}
}

char peek() {
	node *ptr = head;
	if (ptr != NULL) {
		return ptr->n;
	} else {
		return 0;
	}
}

char type(){
    char c = peek();
    
    char pa = '(';
    char pe = '{';
    char pi = '[';
    char ca = ')';
    char ce = '}';
    char ci = ']';
    if (c == pa){
        return ca;
    }
    else if (c == pe){
        return ce;
    }
    else if (c == pi){
        return ci;
    }
}

bool ArePair(char opening, char closing) {
	if (opening == '(' && closing == ')') {
		return true;
	} else if (opening == '{' && closing == '}') {
		return true;
	} else if (opening == '[' && closing == ']') {
		return true;
	}

	return false;
}

int AreParanthesesBalanced(int length, char expresion[]) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (expresion[i] == '(' || expresion[i] == '{' || expresion[i] == '[') {
			push(expresion[i]);
		} else if (expresion[i] == ')' || expresion[i] == '}' || expresion[i] == ']') {
			if (isempty() == 1 || ArePair(peek(), expresion[i]) == false) {
				printf("Los paréntesis no están balanceados\n");
				printf("Sobra un paréntesis de tipo %c.\n", expresion[i]);
				count++;
			} else {
				pop();
			}
		}
	}
	if (count!=0 && isempty()==0){
	    return 0;
	}
	else if (count==0 && isempty()==1){
	    return 1;
	}
	else if (count==0 && isempty()==0){
	    return 0;
	}
	else if (count!=0 && isempty()==1){
	    return 2;
	}
	
}

int main(int argc, char *argv[]) {
    
    //PONER EL ARGUMENTO ENTRE '' CUANDO SE USA ()
    
	if (argc < 2){
	    printf("No ingresó ninguna expresión por consola.\n");
	    return 0;
	}
	
	int largo, balance;
	largo = strlen(argv[1]);
	
	balance = AreParanthesesBalanced(largo, argv[1]);
	if (balance==1) {
		printf("Los paréntesis están balanceados\n");
	} 
	else if (balance==0){
		printf("Los paréntesis no están balanceados\n");
		printf("Falta un paréntesis de tipo %c.\n", type());
	}
	else{
	    printf("No hay mas errores");
	}
	return 0;
}
