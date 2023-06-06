#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "stack.c"
#include <stdio.h>
int main(){

  stack p=stack_empty();

  stack_push(p,14);

  stack_push(p,1);

}