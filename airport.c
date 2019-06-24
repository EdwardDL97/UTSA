/*airport.c
  Project 1
  Edward Diaz Lopez
*/
#include <stdio.h>
#include <string.h>
#include "airport.h"
#include <math.h>


void printAirport (Airport airport)
{
  printf("%-10s", airport.code);
  printf("%-45s", airport.name);
  printf("%-15.6lf", airport.latitude);
  printf("%.6lf", airport.longitude);
  printf("\n");
  return;
}

void printAirports(Airport airports[MAX], int length)
{
  int i;
  for (i = 0; i < length; ++i)
  {
    printAirport(airports[i]);
  }
  return;
}

int fillAirports(Airport fill[MAX])
{
  strcpy(fill[0].code, "SAT");
  strcpy(fill[0].name, "San Antonio Intl");
  fill[0].latitude = 29.533958;
  fill[0].longitude = -98.469056;

  strcpy(fill[1].code, "BKK");
  strcpy(fill[1].name, "Bangkok Suvarnabhumi");
  fill[1].latitude = 13.681108;
  fill[1].longitude = 100.747283;

  strcpy(fill[2].code, "CDG");
  strcpy(fill[2].name, "Paris Charles De Gaulle");
  fill[2].latitude = 49.009722;
  fill[2].longitude = 2.547780;

  strcpy(fill[3].code, "GIG");
  strcpy(fill[3].name, "Rio De Janeiro Galeão");
  fill[3].latitude = -22.809999;
  fill[3].longitude = -43.250555;

  strcpy(fill[4].code, "HKG");
  strcpy(fill[4].name, "Hong Kong Intl");
  fill[4].latitude = 22.308889;
  fill[4].longitude = 113.914722;

  strcpy(fill[5].code, "JFK");
  strcpy(fill[5].name, "New York-JFK ");
  fill[5].latitude = 40.639926;
  fill[5].longitude = -73.778694;

  strcpy(fill[6].code, "JNB");
  strcpy(fill[6].name, "O.R. Tambo Johannesburg");
  fill[6].latitude = -26.133693;
  fill[6].longitude = 28.242317;

  strcpy(fill[7].code, "LAX");
  strcpy(fill[7].name, "Los Angeles Intl");
  fill[7].latitude = 33.942496;
  fill[7].longitude = -118.408048;

  strcpy(fill[8].code, "LHR");
  strcpy(fill[8].name, "London Heathrow ");
  fill[8].latitude = 51.477500;
  fill[8].longitude = -0.461388;

  strcpy(fill[9].code, "MEX");
  strcpy(fill[9].name, "Mexico City Benito Juarez");
  fill[9].latitude = 19.436303;
  fill[9].longitude = -99.072096;

  strcpy(fill[10].code, "SIN");
  strcpy(fill[10].name, "Singapore Changi");
  fill[10].latitude = 1.359211;
  fill[10].longitude = 103.989333;

  strcpy(fill[11].code, "NRT");
  strcpy(fill[11].name, "Tokyo Narita");
  fill[11].latitude = 35.765556;
  fill[11].longitude = 140.385556;

  strcpy(fill[12].code, "AUS");
  strcpy(fill[12].name, "Austin-Bergstrom Intl");
  fill[12].latitude = 30.1975;
  fill[12].longitude = -97.6664;

  strcpy(fill[13].code, "TXL");
  strcpy(fill[13].name, "Berlin Tegel Airport");
  fill[13].latitude = 52.5588;
  fill[13].longitude = 13.2884;

  strcpy(fill[14].code, "ERR");
  strcpy(fill[14].name, "Error");
  fill[14].latitude = -99999;
  fill[14].longitude = -99999;
  return 15;
}

Airport findAirport( Airport airports[ MAX ], int length, char code[4])
{
  int i;

  for (i = 0; i < length; ++i){

  if (strcmp(airports[i].code, code) == 0){
    return airports[i];
    break;
  } 
 }
 return airports[14];
}

double calculateDistance( Airport airport1, Airport airport2 )
{
  double distance;
  double dlat;
  double dlon;
  double a;
  double c;

  

  dlon = (airport2.longitude * PI / 180) - (airport1.longitude * PI / 180);
  dlat = (airport2.latitude * PI / 180) - (airport1.latitude * PI / 180);
  a = pow(sin(dlat/2),2) + cos(airport1.latitude * PI / 180) * cos(airport2.latitude * PI / 180) * pow(sin(dlon/2),2);
  c = 2 * atan2(sqrt(a), sqrt(1-a));
  distance = 3959 * c;

  return distance;
}

void findInRange( Airport airports[ MAX ], int length, Airport origin, int range, Airport output[ MAX ], int* resultsLength )
{
  int distance;
  int i;
  int j = 0;

  for (i = 0; i < length; ++i)
{
   distance = calculateDistance(origin, airports[i]);
  if ((distance <= range) && (distance > 0))
  {
    strcpy(output[j].code, airports[i].code);
    strcpy(output[j].name, airports[i].name);
    output[j].latitude = airports[i].latitude;
    output[j].longitude = airports[i].longitude;
    j += 1;
  } 
}
*resultsLength = j;
 return;
}
