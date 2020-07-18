#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct nodeInt
{
    int n;
    struct nodeInt* next;
}nodeInt;

typedef struct nodeChar
{
    char n;
    struct nodeChar* next;
}nodeChar;

//lista de numeros
nodeInt* lista1 = NULL;
//lista de operadores o parentesis
nodeChar* lista2 = NULL;

void pushInt(int numero){

  nodeInt* newptr = (nodeInt*) malloc(sizeof(nodeInt));

  newptr->n = numero;
  newptr->next = NULL;

  if (lista1 == NULL){
    lista1 = newptr;
  }
  else{
    newptr->next = lista1;
    lista1 = newptr;
  }
}

void pushChar(char opopa){ //OP-erador-O PA-rentesis

  nodeChar* newptr = (nodeChar*) malloc(sizeof(nodeChar));

  newptr->n = opopa;
  newptr->next = NULL;

  if (lista2 == NULL){
    lista2 = newptr;
  }
  else{
    newptr->next = lista2;
    lista2 = newptr;
  }
}

void popInt(void)
{
  nodeInt* temp=lista1;
  if(temp!=NULL){ //si existe una pila
    if(temp->next!=NULL){ //si sigue existiendo una pila
      lista1=temp->next;
    }
    else{ //si pila queda vacia
      lista1=NULL;
    }
    free(temp);
  }
  else{
    printf("Pila vacia\n");
  }
}

void popChar(void)
{
  nodeChar* temp=lista2;
  if(temp!=NULL){ //si existe una pila
    if(temp->next!=NULL){ //si sigue existiendo una pila
      lista2=temp->next;
    }
    else{ //si pila queda vacia
      lista2=NULL;
    }
    free(temp);
  }
  else{
    printf("Pila vacia\n");
  }
}

int peekInt(){
  nodeInt* ptr = lista1;
  if(ptr != NULL){
    return ptr->n;
  }
  else{
    printf("Pila vacia");
    return 0;
  }
  printf("\n");
}

char peekChar(){
  nodeChar* ptr = lista2;
  if(ptr != NULL){
    return ptr->n;
  }
  else{
    printf("Pila vacia");
    return 0;
  }
  printf("\n");
}


int isemptyInt(){
  if(lista1 != NULL){ //si no esta vacia
    return 0;
  }
  else{ //si esta vacia
    return 1;
  }
}

int isemptyChar(){
  if(lista2 != NULL){ //si no esta vacia
    return 0;
  }
  else{ //si esta vacia
    return 1;
  }
}

int switchcase(char ch){
  switch (ch){
    case '(': 
      return 1;
	  case '+':
	  case '-':
      return 2;
    case '*':
    case '/':
      return 3;
    case '^':
      return 4;
  }
  return -1;
}

int calculate(char op, int l , int r){
	if(op == '+'){
		return l + r;
	}
	else if(op == '-'){
		return l - r;
	}
	else if(op == '*'){
		return l * r;
	}
	else if(op == '/'){
		if(r > 0){
			return l/r;
		}
		return 0;
	}
	else if(op == '^'){
		return l ^ r;
	}
	return -1;
}

void menu(char expresion[]){
  int i = 0;
	while(expresion[i] != '\0'){
		if(expresion[i] == '('){
			pushChar('(');
		}
		else if(expresion[i] == ')'){
			while(peekChar() != '('){
				int numeroDerecha = peekInt();
				popInt();
				int numeroIzquierda = peekInt();
				popInt();
				int resultado = calculate(peekChar(), numeroIzquierda, numeroDerecha);
				pushInt(resultado);
			  popChar(); 
			}
			popChar();
		}
		else if(expresion[i] == '+' || expresion[i] == '-' || expresion[i] == '*' || expresion[i] == '/' || expresion[i] == '^'){
			int p = switchcase(expresion[i]);
			while(isemptyChar()==0 && switchcase(peekChar())>= p){
				int numeroDerecha = peekInt();
				popInt();
				int numeroIzquierda = peekInt();
				popInt();
				int resultado = calculate(peekChar(),numeroIzquierda,numeroDerecha);
				pushInt(resultado);
				popChar(); 
			}
			pushChar(expresion[i]);
		}
		else{
			pushInt((expresion[i])- 48); //transforma Char (numero en ASCII)  a Int
		}
		i++;
	}
	while(isemptyChar()==0){
		int numeroDerecha = peekInt();
		popInt();
		int numeroIzquierda = peekInt();
	  popInt();
		int re = calculate(peekChar(),numeroIzquierda,numeroDerecha);
		pushInt(re);
		popChar(); 
	}

}


int main(int argc, char *argv[]){
  
  //PONER EL ARGUMENTO ENTRE '' CUANDO SE USA ()
  
  if (argc < 2){
	    printf("No ingresó ninguna expresión por consola.\n");
	    return 0;
	}

  menu(argv[1]);
	printf("Result: %i", peekInt());
	
	return 0;
}