#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack{

  stack_elem elem;

  struct _s_stack *next;
};

stack stack_empty(){
  stack s=NULL;
  return s;

}

stack stack_push(stack s,stack_elem e){

  struct _s_stack * p = NULL;
  p = malloc(sizeof(struct _s_stack));
  p->elem=e;
  p->next=s;
  s=p;
  return s;
} 

stack stack_pop(stack s){

  struct _s_stack * p = NULL;
  p = malloc(sizeof(struct _s_stack));
  p=s;
  s=s->next;
  free(p);
  return s;

}

unsigned int stack_size(stack s){

  struct _s_stack  * p = NULL;
  p = malloc(sizeof(struct _s_stack));
  unsigned int i=0;
  p=s;

  while (p!=NULL)
  { 
    p=p->next;
    i++;
  }
  return i;

}

stack_elem stack_top(stack s){

  assert(!stack_is_empty(s));

  return  s->elem;

}

bool stack_is_empty(stack s){
    bool b;
    b=(s==NULL);
    return b;
}

stack_elem *stack_to_array(stack s){

  stack_elem *a = calloc(stack_size(s), sizeof(struct _s_stack));

  unsigned int tam=stack_size(s);
  
for (unsigned int i = 0; i < tam; i++)
{
   a[tam-i-1]=s->elem;
   s=s->next;
   
}

  return a;

}

stack stack_destroy(stack s){

  struct _s_stack * p = NULL;

  p = malloc(sizeof(struct _s_stack));

  p=s;

  while (p->next!=NULL)
  { s=stack_pop(s);
    p=s;
    
  }
  free(p);
  p=NULL;
  s=NULL;
  return s;
}
