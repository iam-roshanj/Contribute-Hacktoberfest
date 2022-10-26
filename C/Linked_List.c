//Angelo Almeida Ferro(SIG)
// Bibliotecas-------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//Structs ------------------------------------------------------------------------------------------------
typedef struct node 
{
  long long value;
  struct node *next;
} Node;

typedef struct linkedList 
{
  Node *begin;
  Node *end;
  long long size;
} LinkedList;
// METODOS ------------------------------------------------------------------------------------------------
Node *create_node(long long value) 
{
  Node *newNode = malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

LinkedList *create_list() 
{
  LinkedList *newL = malloc(sizeof(LinkedList));
  newL->begin = NULL;
  newL->end = NULL;
  newL->size = 0;
  return newL;
}

int linkedList_isEmpty(LinkedList *L)
{
  return L->size == 0;
}

void insert_final_fast(LinkedList *L, long long value) 
{
  Node *newNode = create_node(value);

  if (linkedList_isEmpty(L))//Lista Vazia (primeiro caso)
  {
    L->begin = newNode;
    L->end = newNode;
  }
  else // Lista com 1 ou + (segundo caso)
  {
    L->end->next = newNode;
    L->end= newNode;
  }
  L->size++;
}

void insert_middle(LinkedList *L, long long p, long long e)
{
  Node *newNode = create_node(p);
  Node *aux = L->begin;

  if (linkedList_isEmpty(L))//Lista Vazia (primeiro caso)
  {
    L->begin = newNode;
    L->end = newNode;
  }
  else  // Lista com 1 ou +  (segundo caso)
  {
    while(aux != NULL)
    {
      if(aux->value == e)
      {
        newNode->next = aux->next;
        aux->next = newNode;
      }
      aux = aux->next;
    }
  }
  L->size++;
}

void remove_node(LinkedList *L, long long e)
{
  Node *aux = L->begin;
  Node *prev;

  if (aux != NULL && aux->value == e) // remove no inicio
  {
    L->begin = aux->next;
    L->size--;
    free(aux);
    return;
  }

  while (aux != NULL && aux->value != e)//percorre a lista
  {
    prev = aux;
    aux = aux->next;
  }

  if(aux == NULL) return;
  prev->next = aux->next;//remove no final
  L->size--;
  free(aux);
}

//Consulta e retorna a "quantidade de nos" entre o valor a e b
long long query_node(LinkedList *L, long long a, long long b)
{
  long long count=0;
  Node *auxA = L->begin;

  while (auxA->value != a)
  {
    auxA = auxA->next;
  }

  Node *auxB = auxA->next;
  while (auxB->value != b)
  {
    auxB = auxB->next;
    count++;
  }
  return count;  
}

void print_list(LinkedList *L)
{
  if(!linkedList_isEmpty(L))
  {
    Node *aux = L->begin;
    while(aux != NULL)
    {
      printf("%lld->", aux->value);
      aux = aux->next;
    }
    printf("\nTAM: %lld\n", L->size);
  }
}
//MAIN-----------------------------------------------------------------------------------------------
int main() 
{
  LinkedList *L = create_list();
  long long saida[50000];

  long long n;
  scanf("%lld", &n);
  while (n--) // 100 
  {    
    long long ini;
    scanf("%lld", &ini);
    insert_final_fast(L, ini);
  }

  long long Q, tamSaida = 0, i;
  scanf("%lld", &Q);
  while (Q--) //1000 
  {
    char letra;
    long long p, e;

    scanf(" %c", &letra);
    if (letra == 'I') 
    {
      scanf("%lld %lld", &p, &e);
      insert_middle(L, p, e);
    } 
    else if (letra == 'R')// 1 parametro 
    {
      scanf("%lld", &e); 
      remove_node(L, e);
    } 
    else if (letra == 'Q') // 2 parametros
    {
      scanf("%lld %lld", &p, &e); 
      long long count = query_node(L, p, e);
      saida[tamSaida++] = count;
    }
  }

  i=0;
  while (tamSaida--) printf("%lld\n", saida[i++]);

  return 0;
}