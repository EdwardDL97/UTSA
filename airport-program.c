  /*
    airport-program.c
    Project 1
    Edward Diaz Lopez

    This is the driver for the airport program. It displays the main menu presenting a selection of options 
    for the user to get information about the airports in the system. The main function will then call functions
    in airport.c to calculate and retrieve information, which will then be printed here.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "airport-program.h"
#include "airport.h"

/*
    printMenu
    ---------------------------
    This function prints the main menu.
    Returns: Nothing
*/
void printMenu()
{
    printf( "\n#########################################\n" );
    printf( "\tAirport Program Menu\n" );
    printf( "#########################################\n" );
    printf( "\t1 - Get Airport Information\n" );
    printf( "\t2 - Get Airport Listing\n" );
    printf( "\t3 - Get Distance Between Two Airports\n" );
    printf( "\t4 - Find Airports Within Range\n" );
    printf( "\t0 - Quit\n" );
    printf( "Enter your selection: " );
}

/*
    main
    ---------------------------
    This is the main driver of your program. See the comments below on how to complete the driver.
    Returns: 0
*/
int main( int argc, char *argv[] )
{
    Airport airport;
    Airport airports [MAX];
    fillAirports(airports);
    char userCode[4];
    int choice;
    int length = 14;
    int code;
    Airport a1;
    Airport a2;
    double distance;
    int range;
    Airport origin;
    Airport output [MAX];
    int* resultsLength;

    while( TRUE )
    {
        /* call the function to print the menu */
        printMenu();
        scanf( "%d", &choice );

        switch( choice )
        {
            case 1:
                /* 1. Ask the user to enter a 3-letter airport code.*/
                  printf("Enter airport code: ");
                  scanf("%s", userCode);

                   /* 2. Call findAirport() */
                   airport = findAirport(airports, length, userCode);

                    /*
                    3. If either airport's latitude or longitude of -99999, that means the airport was not found.
                    In that case, print out an error.
                    */
                    if (airport.longitude == -99999 || airport.latitude == -99999)
                    {
                      printf("Error: Airport not found\n");
                    } else {
                    /*4. Print the airport information */
                     printAirport(airport);
                    }

                break;
            case 2:

                /* Call the printAirports() function */
                printAirports(airports, length);
                break;

            case 3:
                /*1. Ask the user to enter a 3-letter airport code.*/
                printf("Enter airport 1 code: ");
                scanf("%s", userCode);

                a1 = findAirport(airports, length, userCode);

                  /*
                    3. If either airport's latitude or longitude of -99999, that means the airport was not found.
                    In that case, print out an error. Otherwise, call the calculateDistance() function.
                  */
                if (a1.longitude == -99999 || a1.latitude == -99999)
                    {
                      printf("Error: Airport not found\n");
                      break;
                    }

                /*2. Ask the user to enter another 3-letter airport code.*/
                printf("Enter airport 2 code: ");
                scanf("%s", userCode);

                a2 = findAirport(airports, length, userCode);
                distance = calculateDistance(a1, a2);

                   /*
                    3. If either airport's latitude or longitude of -99999, that means the airport was not found.
                    In that case, print out an error. Otherwise, call the calculateDistance() function.
                  */
                if (a2.longitude == -99999 || a2.latitude == -99999)
                    {
                      printf("Error: Airport not found\n");
                    }else {


                  /*4. Print out the distance. */
                      printf("The distance between %s and %s is %.2lf miles.\n", a1.name, a2.name, distance);
                    }

                break;
            case 4:

                   /* 1. Ask the user to enter a 3-letter airport code,*/
                    printf("Enter airport code: ");
                    scanf("%s", userCode);

                    if (airports.longitude == -99999 || airports.latitude == -99999)
                    {
                      printf("Error: Airport not found\n");
                      break;
                    }
                    /*2. Ask the user to enter a range in miles (integer)*/
                    printf("Enter range in miles:");
                    scanf("%d", &range);

                    /*3. Call findAirport() to find the struct for that Airport */
                    origin = findAirport(airports, length, userCode);

                    /*4. Call findInRange() to get an array of Airports within the range*/
                    findInRange(airports, length, origin, range, output, &resultsLength);

                    /*5. Print the return array of Airport, if the array's length is empty state that no airports were found*/
                    printAirports(output, resultsLength);

                break;
            case 0:
                printf( "Good-bye!\n" );
                return 0;
        }
    }

    return 0;
}
