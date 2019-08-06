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
 	char input[4];
 	Destination *node = NULL;
 	Destination *temp;
 	Destination *locate;
    char key[4];


	while( TRUE )
	{
		printMenu();

        /* adapt the scanf() to handle invalid input */
        scanf( "%d", &choice );

        switch( choice )
        {
            case 1:
                /* 1) ask the user to enter the airport code */
                printf("Enter the airport code for the destination: ");
                scanf("%s", input);

                locate = find(node, input);
                /* 2) check to see if the airport code exists in the list, if it does, print an error and break; */
                if (locate != NULL)
                {
                    printf("ERROR: Destination already exists.\n");
                    break;
                }
                /* 2) if the list is empty, call create() and insertAfter() to create and insert it into the linked list */
                if (node == NULL)
                {
                 temp = create(input);
                 node = insertAfter(node, temp, input);
                }
                 /*  3) if the list is not empty, ask the user where in the list they want to add the node. The user will enter the airport code in which this new node will be added AFTER in the linked list.
                 Then, call create() and insertAfter() to create and insert it into the linked list.
                 Note that if the user enters ZZZ as the airport code, it will add the new node to the beginning and if the user enters an airport code, it adds the new node to the end. */
                 else
                 {
                     printf("Enter the airport code for which new destination is added after. Enter ZZZ to add to beginning of list: ");
                     scanf("%s", key);

                     temp = create(input);
                     node = insertAfter(node, temp, key);
                 }
                /*   4) Print a message saying the destination was added */
                printf("%s added\n", input);
                break;
            case 2:
                /* 1) ask the user to enter an airport code */
                printf("Enter the airport code for the destination: ");
                scanf("%s", input);
                /* 2) check to see if the airport code exists in the list with find(),
                if it does not exist, print an error and break; */
                locate = find(node, input);
                if (locate == NULL)
                {
                    printf("ERROR: Destination does not exist.\n");
                    break;
                }
                  /* 3) call remove() the airport code from the list */
                  else{
                    remove(node);
                  }
                  /* 4) print a message saying the destination was removed */
                  printf("%s was removed.\n", input);

                break;
            case 3:
                /* call print() */
                printf("\nDestinations in Itinerary\n");
                print(node);
                break;
            case 4:
                /* call printItinerary() */
                printf("\nItinerary\n");
                printItinerary(node);
                break;
            case 5:
                /* call destruct() */
                node = destruct(node);
                node = NULL;
                printf("Itinerary cleared.\n");

                break;
            case 0:
                /* print a farewell message and call destruct() */
                printf("Good-bye!\n");
                return 1;
            default:
                /* print a message saying that the input choice was not valid */
                printf("Invalid input.\n");
                break;
        }
	}

    return 0;
}
