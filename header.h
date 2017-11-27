#include <stdio.h>
#include <string.h>
#include "string_compare.c"



#define MAXSTRING 15 //The maximum number of character for a string
#define LOCATIONS 12 //the numbers of cities on i26

//Location Node
typedef struct Location{
	char name[MAXSTRING];
	struct Location *east;
	struct Location *west;
	struct Location *north;
	struct Location *south;
}Location;

//Function Prototypes

int string_compare(char[], char[]);
void inputCheck(char[], char[], Location[]);
void initializeMap(Location[]);
void printRoute (*char, *char, Location[]);




