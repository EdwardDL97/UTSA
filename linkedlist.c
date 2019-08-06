#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itinerary.h"

Destination *create( char *code )
{
  Destination *ptr = (Destination *)malloc( sizeof(Destination) );
  strcpy(ptr->airportCode, code);
  ptr->next = NULL;

  return ptr;
}

Destination *insertAfter( Destination *head, Destination *node, char *key )
{
  Destination *ptr;
  if(strcmp(key,"ZZZ") == 0)
  {
      strcpy(key, node->airportCode);
      node->next = head;
      head = node;

      return head;
  }
  if( head == NULL )
  {
    head = node;
  }
  else
  {
  for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
      if (strcmp(ptr->airportCode, key) == 0)
      {
        node->next = ptr->next;

        ptr->next = node;
      }
    }
  }
  return head;
}

Destination *find( Destination *head, char *key )
{
  Destination *ptr;

  for( ptr = head; ptr != NULL; ptr = ptr->next )
  {
    if ( strcmp(ptr->airportCode, key) == 0 )
    {
	return ptr;
    }
  }
  return NULL;
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
  printf("\n");
}

void printItinerary( Destination *head )
{
  Destination *i;
  int counter = 0;

  for (i = head; i != NULL; i = i->next )
  {
    if(i->next->airportCode == NULL)
    {
        break;
    }
        printf( "%s-%s\n", i->airportCode, i->next->airportCode );
    counter ++;
  }
  printf("Total Segments: %d\n", counter);
}

Destination *destruct( Destination *head )
{
    Destination *temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;

        free(temp);
    }
return NULL;
}

