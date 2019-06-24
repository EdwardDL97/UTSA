/* airport.h
   Project 1
   Edward Diaz Lopez
*/
#ifndef AIRPORT_H
#define AIRPORT_H
#define MAX 50
#define PI 3.14159

typedef struct Airport
{
  char code [4];
  char name [50];
  double latitude;
  double longitude;
}Airport;

void printAirports (Airport [MAX], int);
void printAirport(Airport);
Airport findAirport(Airport[MAX] , int, char [4]);
double calculateDistance(Airport, Airport);
void findInRange(Airport [MAX], int, Airport, int, Airport[MAX], int*);
int fillAirports(Airport[MAX]);

#endif
