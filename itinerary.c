#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itinerary.h"

Destination *create( char *code )
{
  Destination *ptr = (Destination *)malloc( sizeof(Destination) );
  strcpy(ptr->airportCode, code);
  strcpy(ptr->next, NULL);

  return ptr;
}
/*
Destination *insertAfter( Destination *head, Destination *node, char *key )
{
  Destination *ptr;
  Destination *previous = NULL;

  while( head == NULL )
  {
	return node;
  }
}
*/
Destination *find( Destination *head, char *key )
{
  Destination *ptr;
 
  for( ptr = head; ptr != NULL; ptr = ptr->next )
  {
    if ( strcmp(head, key) == 0 )  
    {
	return ptr;
    }
  }
}

Destination *removeNode( Destination *head, char *key )
{
  Destination *ptr;
  Destination *previous;

  for(ptr = head; ptr != NULL; ptr = ptr->next )
  {
    if( strcmp( ptr, key ) == 0 )
    {
	Destination *temp = ptr;
    
	if( ptr == head )
	{
	  head = head->next;
	}
        else
        {
	  previous->next = ptr->next;
        } 
        free( temp );
        return head;
    }
    previous = ptr;
  }
  return head;
}

void print( Destination *head )
{
  Destination *d;

  for ( d = head; d != NULL; d = d->next )
  {
    printf( "%s\n", d->airportCode );
  }
}

void printItinerary( Destination *head )
{
  Destination *i;

  for (i = head; i !=NULL; i = i->next )
  {
    printf( "%s-%s\n", i->airportCode, i->airportCode );
  }
}
