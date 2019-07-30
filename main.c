#include <stdio.h>
#include "itinerary.h"
#include "main.h"

/* 
    printMenu
    ---------------------------
    This function prints the main menu.
    Returns: Nothing
*/
void printMenu()
{
    printf( "\n#########################################\n" );
    printf( "#            Trip Planner Menu          #\n" );
    printf( "#########################################\n" );
    printf( " 1 - Insert a Destination\n" );
    printf( " 2 - Remove a Destination\n" );
    printf( " 3 - Print Destinations\n" );
    printf( " 4 - Print Itinerary\n" );
    printf( " 5 - Clear Itinerary\n" );
    printf( " 0 - Quit\n" );
    printf( "Enter your selection: " );
}

int main( void )
{
 	/* declare all your variables here */
 	int choice;
    
	while( TRUE )
	{ 
		printMenu();

        /* adapt the scanf() to handle invalid input */
        scanf( "%d", &choice );
        
        switch( choice )
        {
            case 1:
                /* 1) ask the user to enter the airport code
                   2) check to see if the airport code exists in the list, if it does, print an error and break;
                   2) if the list is empty, call create() and insertAfter() to create and insert it into the linked list
                   3) if the list is not empty, ask the user where in the list they want to add the node. The user will enter the airport code in which this new node will be added AFTER in the linked list. Then, call create() and insertAfter() to create and insert it into the linked list. Note that if the user enters ZZZ as the airport code, it will add the new node to the beginning and if the user enters an airport code, it adds the new node to the end. 
                   4) Print a message saying the destination was added
                */
                break;
            case 2:
                /* 1) ask the user to enter an airport code
                   2) check to see if the airport code exists in the list with find(), if it does not exist, print an error and break;
                   3) call remove() the airport code from the list  
                   4) print a message saying the destination was removed
                */
                break;
            case 3:
                /* call print() */
                break;
            case 4:
                /* call printItinerary() */
                break;
            case 5:
                /* call destruct() */
                break;
            case 0:
                /* print a farewell message and call destruct() */
                return 1;
            default:
                /* print a message saying that the input choice was not valid */
                break;
        }
	}

    return 0;
}
