
/************************/
/*	GROUP 4B	*/
/************************/

#include <stdio.h>
#include <string.h>

#define MAXSTRING 15  //The maximum number of characters for a string
#define LOCATIONS 12  //The number of cites on i26.

// Location node
typedef struct Location{
        char name[MAXSTRING];
        struct Location *east;
        struct Location *west;
        struct Location *north;
        struct Location *south;
}Location;


Location initializeMap(Location map[])
{
        char *eastToWestList[] = {"Sandy","Boring","Gresham","East Portland","i5","West Portland","Sylvan","Beaverton","Tanasbourne","Hillsboro","North Plains","Mountaindale"};
	//Initializing nodes
        for (int i = 0; i< LOCATIONS; i++){
                strcpy(map[i].name,eastToWestList[i]);
                if(i == 0){
                        map[i].east = NULL;
                        map[i].west = &map[1];
                        map[i].south = NULL;
                        map[i].north = NULL;
                }else if(i == 11){
                        map[i].east = &map[10];
                        map[i].west = NULL;
                        map[i].south = NULL;
                        map[i].north = NULL;
                }else{
                        map[i].east = &map[i-1];
                        map[i].west = &map[i+1];;
                        map[i].south = NULL;
                        map[i].north = NULL;
                }
        }

}

// Function which checks user input to make sure it is valid
void inputCheck(char message[], char input[MAXSTRING], Location Map[]){//lookup struct name
        int condition = 1;
        while(condition != 0){
                printf("\n %s ", message);
                fgets(input, MAXSTRING, stdin);
                input[strcspn(input, "\n")] = '\0';
                for(int i = 0; i < LOCATIONS; ++i){
                        condition = strcmp(input, Map[i].name);
                        if(condition == 0) break;
                }
                if(condition == 0) return;
                printf("Invalid input. Try again. \n");
        }
}

// Function which executes the search for route between two cities
void printRoute(char *From, char *To, Location cities[]){
	int east = 0, e = 0; //  0 implies that eastern side hasn't been traversed yet, 1 implies the opposite
  	int west = 0, w = 0; //  0 implies that western side hasn't been traversed yet, 1 implies the opposite
  	char route[LOCATIONS][MAXSTRING];  // This stores all the cities between origin and destination
	int totalCities = 0;
	int destinationFound = 0; // 0 implies that destination hasn't been found yet, 1 implies the opposite 
  	Location *origin; // Origin
	if(strcmp(To,From) == 0){
        	destinationFound = 1;
        	printf("\n You're at the destination, duh!\n");
		printf("\n");
        	return;
	}
 	for (int i = 0; i < LOCATIONS; i++){
		if (strcmp(From, cities[i].name) == 0){
        		origin = &cities[i];
        		break;
    		}
 	 }

   	while(destinationFound == 0){
     		Location *currentNode;
     		currentNode = origin;

    		while(east == 0){
      			strcpy(route[e], currentNode->name);
			totalCities += 1;
      			if (strcmp(currentNode->name, To) == 0){
        			destinationFound = 1;
        			break;
      			}
      			if(currentNode->east == NULL){
        			east = 1;
				//Given destinationFound is 0, if it's an end node, this resets the route list
        			if(destinationFound == 0){
          				for(int a = 0; a < LOCATIONS; a++){
            					for (int b = 0; b < MAXSTRING; b++){
							route[a][b] = '\0';
						}
          				}
        			}
				currentNode = origin;
				totalCities = 0;
        			break;
      			}
      			currentNode = currentNode->east;
      			e += 1;
    		}

    		while(west == 0 && destinationFound == 0){
      			strcpy(route[w], currentNode->name);
			totalCities += 1;
      			if (strcmp(currentNode->name, To) == 0){
        			destinationFound = 1;
        			break;
      			}
      			if(currentNode->west == NULL){
        			west = 1;
      			}
      			currentNode = currentNode->west;
      			w += 1;
    		}
   	}
	printf("\n");
	printf("Here is the route from %s to %s\n", From, To);
	for(int z = 0; z <totalCities; z++){
		printf("%s    ",route[z]);
	}
	printf("\n");
}

void main(void){
        Location eastWestMap[LOCATIONS]; // An array of city nodes
	char origin[MAXSTRING];
	char destination[MAXSTRING];

	initializeMap(eastWestMap);
        inputCheck("Hello!, please enter the origin: ", origin, eastWestMap);
        inputCheck("Please enter the destination: ", destination, eastWestMap);
       	printRoute(origin, destination, eastWestMap); //Function which prints cities between origin and destination

}

