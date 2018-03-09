/**
 *  Integer Stack ADT : public interface
 *    Choose your implementation of a stack
 *
 *  COMP220: Lab 7 Solution
 *  Original Author:  Joseph Fall 
 *  Modified by:  
 *  Date:    Mar. 6, 2018
 */


/*******************
 * PRIVATE TYPE DECLARATION
 ********************/




/*********************
 *  PUBLIC INTERFACE
 *********************/
typedef struct node_s node_2t;
struct node_s {   
   int data;       
   node_2t* next;   
};

typedef struct {
   node_2t* head;
   node_2t* top;
}IntStack_t;
 
 
/*
 * Constructor - return a new, empty stack 
 * POST: istackIsEmpty(stack)
 */
IntStack_t istackCreate( );

/*
 * Destructor - empty stack and free all associated memory
 */
 void istackDestroy( IntStack_t *stack ); 

/*
 * Print a text representation of this stack on STDOUT
 */
void istackPrint( IntStack_t stack  ); 

/*
 * Return true iff the stack is empty
 */
bool istackIsEmpty( IntStack_t stack );

/*
 * Return true iff the stack is full
 */
bool istackIsFull( IntStack_t stack );

/*
 * Examine the item at the top of the stack
 * PRE: ! istackIsEmpty( stack )
 */
int istackTop( IntStack_t stack );

/*
 * Pop the item from the top of the stack 
 * PRE: ! istackIsEmpty( stack )
 */
int istackPop( IntStack_t *stack );

/*
 * Push given item on the top of the stack 
 * PRE: ! istackIsFull( stack )
 * POST: istackTop( stack ) == item
 */
int istackPush( IntStack_t *stack, int item);
