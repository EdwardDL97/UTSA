#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QueueNode *enqueue( QueueNode *front, QueueNode *newNode )
{
    QueueNode *qn;
    if( front == NULL )
    {
	return newNode;
    }

    for( qn = front; qn->next != NULL; qn = qn->next )
    {
	
    }

    qn->next = newNode;
    return front; 
   
}
QueueNode *dequeue( QueueNode *front, int *t )
{
    QueueNode *temp = front;
    if( front == NULL )
    {
	return NULL;
    }

    front = front->next;
    *t = temp->number;

    free( temp );
    return front;
}

void print( QueueNode *front)
{
    QueueNode *qn;
   
    for( qn = front; qn != NULL; qn = qn->next )
    {
        printf( "%d\t", qn->number );
    }
}

QueueNode *create( int v )
{
    QueueNode *t = (QueueNode *) malloc( sizeof( QueueNode ) );
    t->number = v;
    t->next = NULL;

    return t;
}
