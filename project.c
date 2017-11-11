/************************/
/*	GROUP 4B	*/
/************************/

#include <stdio.h>
#include <string.h>

// Location node
typedef struct Location{
        char name[15];
        struct Location *east;
        struct Location *west;
        struct Location *north;
        struct Location *south;
}Location;

// Function which executes the search for route between two cities
void printRoute(char *From, char *To, Location cities[]){
	int east = 0, e = 0; //  0 implies that eastern side hasn't been traversed yet, 1 implies the opposite
  	int west = 0, w = 0; //  0 implies that eastern side hasn't been traversed yet, 1 implies the opposite
  	char route[12][15];  // This stores all the cities between origin and destination
	int totalCities = 0; 
	int destinationFound = 0; // 0 implies that destination hasn't been found yet, 1 implies the opposite 
  	Location *origin; // Origin
  
 	for (int i = 0; i < 12; i++){
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
          				for(int a = 0; a < 12; a++){
            					for (int b = 0; b < 15; b++){
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
		printf("%s\t",route[z]);
	}
	printf("\n");  
}

void main(void){
	void printRoute(char *To, char *From, Location cities[]);
        char *eastToWestList[] = {"Sandy","Boring","Gresham","East Portland","i5","West Portland","Sylvan","Beaverton","Tanasbourne","Hillsboro","North Plains","Mountaindale"};
        Location eastWestMap[12]; // An array of city nodes
	char origin[15];
	char destination[15];	
	//Initializing nodes
        for (int i = 0; i< 12; i++){
                strcpy(eastWestMap[i].name,eastToWestList[i]);
                if(i == 0){
                        eastWestMap[i].east = NULL;
                        eastWestMap[i].west = &eastWestMap[1];
                        eastWestMap[i].south = NULL;
                        eastWestMap[i].north = NULL;
                }else if(i == 11){
                        eastWestMap[i].east = &eastWestMap[10];
                        eastWestMap[i].west = NULL;
                        eastWestMap[i].south = NULL;
                        eastWestMap[i].north = NULL;
                }else{
                        eastWestMap[i].east = &eastWestMap[i-1];
                        eastWestMap[i].west = &eastWestMap[i+1];;
                        eastWestMap[i].south = NULL;
                        eastWestMap[i].north = NULL;
                }
        }
	
	printf("\n Hello!, please enter the origin: ");
	scanf("%s",origin);
	printf("\n Please enter the destination: ");
	scanf("%s",destination);
       	printRoute(origin, destination, eastWestMap); //Function which prints cities between origin and destination

}

