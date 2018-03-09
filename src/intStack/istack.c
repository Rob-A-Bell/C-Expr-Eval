#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "istack.h"
#include <limits.h>

node_2t* makeNode(int val)
{
   node_2t* new_node = malloc(sizeof(node_2t));
   assert(new_node != NULL);
   new_node->data = val;
   new_node->next = NULL;
   return new_node; 

}
/*
 * Constructor - return a new, empty stack 
 * POST: istackIsEmpty(stack)
 */
IntStack_t istackCreate( )
{
	IntStack_t stack;
	node_2t* dummy = makeNode(INT_MIN);
	//stack.head = dummy;
	stack.top = NULL;
	return stack;
}

/*
 * Destructor - empty stack and free all associated memory
 */
 void istackDestroy( IntStack_t *stack )
 {
 	node_2t* cur = stack->top;
 	while (stack->top != NULL){
 		stack->top = stack->top->next;
 		free(cur);
 		cur = stack->top;
 	}
 }

/*
 * Print a text representation of this stack on STDOUT
 */
void istackPrint( IntStack_t stack  )
{
   node_2t* cur = stack.top;
   if (cur != NULL){
      printf("\nHERE ARE THE VALUES IN THE STACK\n");
      while(cur != NULL){
         printf("[%d]--> ", cur->data );
         cur = cur->next;
      }
   }
   else{
      printf("There is nothing in that list\n");
   }
   printf("\n");
}

/*
 * Return true iff the stack is empty
 */
bool istackIsEmpty( IntStack_t stack )
{
	return (stack.top == NULL) ? true : false;
}

/*
 * Return true iff the stack is full  !! OPTIONAL -- for static array stack implementations only !! 
 */
bool istackIsFull( IntStack_t stack )
{
    return false;
}

/*
 * Examine the item at the top of the stack
 * PRE: ! istackIsEmpty( stack )
 */
int istackTop( IntStack_t stack )
{
	assert(!istackIsEmpty(stack));
	return stack.top->data;
}

/*
 * Pop the item from the top of the stack 
 * PRE: ! istackIsEmpty( stack )
 */
int istackPop( IntStack_t *stack )
{
	assert(!istackIsEmpty(*stack));
	node_2t* cur = stack->top;
	stack->top = stack->top->next;
	int popped = cur->data;
	free(cur);
	return popped;
}

/*
 * Push given item on the top of the stack 
 * PRE: ! istackIsFull( stack )
 * POST: istackTop( stack ) == item
 */
int istackPush( IntStack_t *stack, int item)
{
	node_2t* new_node = makeNode(item);
	new_node->next = stack->top;
	stack->top = new_node;
}
