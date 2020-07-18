#define MAX 10  
 
int ultimo=-1;
int primero=-1;
int fila[MAX];

void queue()
{
  int nuevoElemento;
  
  if(ultimo==MAX-1)
  {
    printf("No hay más espacio en la fila\n");
  }
  else
  {
    if (primero == - 1){
      primero = 0;
    }
    printf("¿Qué elemento quiere ingrasar en la fila?\n");
    scanf("%d", &nuevoElemento);
    ultimo = ultimo + 1;
    fila[ultimo] = nuevoElemento;
  }
}
 
void dequeue()
{
  if(primero==-1 || primero > ultimo)
  {
    printf("No se pueden eliminar más elemento en la fila\n");
  }
  else
  {
    printf("El elemento borrado es %d\n",fila[primero]);
    int temp=primero;
    for(int i = 0; i<=ultimo; i++){
    
      fila[i]=fila[temp+1];
      temp++;
    }
    fila[ultimo]="\0";
    ultimo=ultimo-1;
  }
}
 
void peek_q()
{
  if(primero==-1)
  {
    printf("La fila está vacía!\n");
  }
  else
  {
    printf("El primer elemento de la fila es %d\n",fila[primero]);
  }
}

int isempty_q(){
  if(primero==-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
