#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

Node *insertNode( Node *head, Node * newNode )
{
    Node *ptr;
    Node *previous = NULL;

    if ( head == NULL )
    {	
	return newNode;
    }

    for( ptr = head; ptr != NULL; ptr = ptr->next )
    {
	if( strcmp( ptr->name, newNode->name ) > 0)
	{
	    newNode-> next = ptr;
	    if (previous == NULL )
	    {
	        previous->next = newNode;
		return head;
	    }
	    else
	    {
		return newNode;
	    }
		

    }
	previous = ptr;
  }
   
}

Node *findNode( Node *head, int key )
{
    Node *ptr;
    
    for( ptr = head; ptr != NULL; ptr = ptr->next )
    {
        if( ptr->number == key )
	{
	  return ptr;
	}
    }
    return NULL;
}

void print( Node *h )
{
    Node *ptr;
   
    for( ptr = h; ptr != NULL; ptr = ptr->next )
    {
        printf( "Value: %d %s\n", ptr->number, ptr->name );
    }
}

Node * createNode( int number, char *name )
{
  Node *n = (Node *) malloc( sizeof( Node ) );
  n ->number = number;
  strcpy( n->name, name );
  n->next = NULL;

  return n;
}

void printReverse( Node *n )
{
  if( n == NULL )
  {
    return;
  }

  printReverse( n->next );
  printf("%s\n", n->name );
}
