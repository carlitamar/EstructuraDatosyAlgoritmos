#define MAX 10
 
int ultimo=-1;
int pila[MAX];

void push()
{
  int nuevoElemento;
  
  if(ultimo==MAX-1)
  {
    printf("La pila está llena\n");
  }
  else
  {
    printf("Elija elemento para meter a la pila:\n");
    scanf("%d",&nuevoElemento);
    ultimo=ultimo+1;
    pila[ultimo]=nuevoElemento;
  }
}
 
void pop()
{
  if(ultimo==-1)
  {
    printf("La pila está vacía!\n");
  }
  else
  {
    printf("El elemento borrado es %d\n",pila[ultimo]);
    pila[ultimo]="\0";
    ultimo=ultimo-1;
  }
}
 
void peek_s()
{
  
  if(ultimo==-1)
  {
    printf("La pila está vacía!\n");
  }
  else
  {
    printf("El último elemento de la pila es %d\n",pila[ultimo]);
  }
}

int isempty_s(){
  if(ultimo==-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

