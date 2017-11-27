/************************/
/*	GROUP 4B	*/
/************************/

#include <stdio.h>
#include <string.h>
#include "stack.h"
#include <stdlib.h>

#define MAXSTRING 20  //The maximum number of characters for a string
#define LOCATIONS 12  //The number of cites on i26.

// Location node
typedef struct Location{
        char name[MAXSTRING];
        struct Location *east;
        struct Location *west;
        struct Location *north;
        struct Location *south;
}Location;

// Function which checks user input to make sure it is valid
void inputCheck(char message[], char input[MAXSTRING], Location Map1[], Location Map2[]){
	int condition = 1;
	while(condition != 0){
		printf("\n %s ", message);
		fgets(input, MAXSTRING, stdin);
		input[strcspn(input, "\n")] = '\0';
		for(int i = 0; i < LOCATIONS; ++i){
			condition = strcmp(input, Map1[i].name);
			if(condition == 0) break;
		}
		if(condition == 0) return;
		for(int i = 0; i < LOCATIONS; ++i){
                        condition = strcmp(input, Map2[i].name);
                        if(condition == 0) break;
                }
		if(condition == 0) return;
		printf("Invalid input. Try again. \n");
	}
}

// Function which executes the search for route between two cities
void printRoute(char *From, char *To, Location ewCities[], Location nsCities[], STACK *stack1){
	int east = 0, e = 0; //  0 implies that eastern side hasn't been traversed yet, 1 implies the opposite
  	int west = 0, w = 0; //  0 implies that western side hasn't been traversed yet, 1 implies the opposite
	int north = 0, n = 0; //  0 implies that northern side hasn't been traversed yet, 1 implies the opposite
        int south = 0, s = 0; //  0 implies that southern side hasn't been traversed yet, 1 implies the opposite
	int isEWOrigin = 0;
	int isNSOrigin = 0;
	int indexOfJunction = 0;
	char directionOfJunction;
	int isJunctionFound = 0;
	Location *EWJunction = &ewCities[4];
	Location *NSJunction = &nsCities[2];	
  	char route[2*LOCATIONS][MAXSTRING];  // This stores all the cities between origin and destination
	int totalCities = 0; 
	int destinationFound = 0; // 0 implies that destination hasn't been found yet, 1 implies the opposite 
  	Location *origin; // Origin
	if(strcmp(To,From) == 0){
		destinationFound = 1;
        	printf("\n You're at the destination, duh!\n");
		printf("\n");
        	return;

	}
 	if( (strcmp(EWJunction->name,From) == 0 || strcmp(NSJunction->name,From) == 0) && (strcmp(EWJunction->name,To) == 0 || strcmp(NSJunction->name,To) == 0) ){
		destinationFound = 1;
		printf("\n You're at the destination, duh!\n");
		return;
	} 
	for (int i = 0; i < LOCATIONS; i++){
		if (strcmp(From, ewCities[i].name) == 0){
        		origin = &ewCities[i];
			isEWOrigin = 1;
        		break;
    		}
		if (strcmp(From, nsCities[i].name) == 0){
                        origin = &nsCities[i];
			isNSOrigin = 1;
                        break;
                }  
 	 }
   	while(destinationFound == 0){
		printf("The big loop");
     		Location *currentNode;
     		currentNode = origin;
		if (isEWOrigin == 1){		
    			while(east == 0){
      				strcpy(route[e], currentNode->name);
				if(strcmp(currentNode->name, EWJunction->name) == 0){
					isJunctionFound = 1;
					directionOfJunction = 'e';
				}
				totalCities += 1;
      				if (strcmp(currentNode->name, To) == 0){
        				destinationFound = 1;
        				break;
      				}	
      				if(currentNode->east == NULL){
        				east = 1;
					//Given destinationFound is 0, if it's an end node, this resets the route list
        				if(destinationFound == 0){
          					for(int a = 0; a < 2*LOCATIONS; a++){
            						for (int b = 0; b < MAXSTRING; b++){
								route[a][b] = '\0';
							}
          					}
        				}
					currentNode = origin;
					totalCities = 0;
					e = 0;
        				break;
      				}
      				currentNode = currentNode->east;
      				e += 1;
    			}	
    			while(west == 0 && destinationFound == 0){
      				strcpy(route[w], currentNode->name);
				if(strcmp(currentNode->name, EWJunction->name) == 0){
					isJunctionFound = 1;
					directionOfJunction = 'w';
                        	}
				totalCities += 1; 
      				if (strcmp(currentNode->name, To) == 0){
        				destinationFound = 1;
        				break;
      				}
      				if(currentNode->west == NULL){
        				west = 1;
					//Given destinationFound is 0, if it's an end node, this resets the route list
                                	if(destinationFound == 0){
                                        	for(int a = 0; a < 2*LOCATIONS; a++){
                                                	for (int b = 0; b < MAXSTRING; b++){
                                                        	route[a][b] = '\0';
                                                	}
                                        	}
                                	}
                                	currentNode = origin;
                                	totalCities = 0;
					isJunctionFound = 0;
					w = 0;
                                	break;
      				}
      				currentNode = currentNode->west;
      				w += 1;
    			}
			while(isJunctionFound == 0 && destinationFound == 0){
				if(directionOfJunction == 'e'){
					strcpy(route[e], currentNode->name);
					totalCities += 1;
                                	if(strcmp(currentNode->name, EWJunction->name) == 0){
                                        	isJunctionFound = 1;
						indexOfJunction = e;
                                        	currentNode = currentNode->north;
                                        	break;
                                	}
					e += 1;
					currentNode = currentNode->east;	
				}else{
					strcpy(route[w], currentNode->name);
					totalCities += 1;
                                        if(strcmp(currentNode->name, EWJunction->name) == 0){
                                                isJunctionFound = 1;
						indexOfJunction = w;
                                                currentNode = currentNode->north;
                                                break;
                                        }
					w += 1;
					currentNode = currentNode->west;
				}
			}
			while(north == 0 && destinationFound == 0){
				strcpy(route[n+indexOfJunction+1], currentNode->name);
				totalCities += 1;
				n += 1;
				if (strcmp(currentNode->name, To) == 0){
                                        destinationFound = 1;
                                        break;
                                }
				if(currentNode->north == NULL){
                                        north = 1;
                                        //Given destinationFound is 0, if it's an end node, this resets the route list
                                        if(destinationFound == 0){
                                                for(int a = 2*LOCATIONS; a <indexOfJunction ; a--){
                                                        for (int b = 0; b < MAXSTRING; b++){
                                                                route[a][b] = '\0';
                                                        }
                                                }
                                        }
                                        currentNode = EWJunction->south;
                                        totalCities = totalCities-n;
                                        break;
                                }
				currentNode = currentNode->north;		
			}
			while(south == 0 && destinationFound == 0){
                                strcpy(route[s+indexOfJunction+1], currentNode->name);
                                totalCities += 1;
				s += 1;
                                if (strcmp(currentNode->name, To) == 0){
                                        destinationFound = 1;
                                        break;
                                }
                                if(currentNode->south == NULL){
                                        south = 1;
                                        //Given destinationFound is 0, if it's an end node, this resets the route list
                                        if(destinationFound == 0){
                                                for(int a = 2*LOCATIONS; a <indexOfJunction ; a--){
                                                        for (int b = 0; b < MAXSTRING; b++){
                                                                route[a][b] = '\0';
                                                        }
                                                }
                                        }
                                        currentNode = EWJunction;
                                        totalCities = totalCities-s;
                                        break;
                                }
                                currentNode = currentNode->south;
                        }
		}else{
			while(north == 0){
                                strcpy(route[n], currentNode->name);
                                if(strcmp(currentNode->name, NSJunction->name) == 0){
                                        isJunctionFound = 1;
                                        directionOfJunction = 'n';
                                }
                                totalCities += 1;
                                if (strcmp(currentNode->name, To) == 0){
                                        destinationFound = 1;
                                        break;
                                }
                                if(currentNode->north == NULL){
                                        north = 1;
                                        //Given destinationFound is 0, if it's an end node, this resets the route list
                                        if(destinationFound == 0){
                                                for(int a = 2*LOCATIONS - 1; a >= 0; a--){
                                                        for (int b = 0; b < MAXSTRING; b++){
                                                                route[a][b] = '\0';
                                                        }
                                                }
                                        }
                                        currentNode = origin;
                                        totalCities = 0;
                                        n = 0;
                                        break;
                                }
                                currentNode = currentNode->north;
                                n += 1;
                        }
                        while(south == 0 && destinationFound == 0){
                                strcpy(route[s], currentNode->name);
                                if(strcmp(currentNode->name, NSJunction->name) == 0){
                                        isJunctionFound = 1;
                                        directionOfJunction = 's';
                                }
                                totalCities += 1;
                                if (strcmp(currentNode->name, To) == 0){
                                        destinationFound = 1;
                                        break;
                                }
                                if(currentNode->south == NULL){
                                        south = 1;
                                        //Given destinationFound is 0, if it's an end node, this resets the route list
                                        if(destinationFound == 0){
                                                for(int a = 0; a < 2*LOCATIONS; a++){
                                                        for (int b = 0; b < MAXSTRING; b++){
                                                                route[a][b] = '\0';
                                                        }
                                                }
                                        }
                                        currentNode = origin;
                                        totalCities = 0;
                                        isJunctionFound = 0;
                                        s = 0;
                                        break;
                                }
                                currentNode = currentNode->south;
                                s += 1;
                        }
                        while(isJunctionFound == 0 && destinationFound == 0){
                                if(directionOfJunction == 'n'){
                                        strcpy(route[n], currentNode->name);
					totalCities += 1;
                                        if(strcmp(currentNode->name, NSJunction->name) == 0){
                                                isJunctionFound = 1;
                                                indexOfJunction = n;
                                                currentNode = currentNode->east;
                                                break;
                                        }
                                        n += 1;
                                        currentNode = currentNode->north;
                                }else{
                                        strcpy(route[s], currentNode->name);
					totalCities += 1;
                                        if(strcmp(currentNode->name, NSJunction->name) == 0){
                                                isJunctionFound = 1;
                                                indexOfJunction = s;
                                                currentNode = currentNode->east;
                                                break;
                                        }
                                        s += 1;
                                        currentNode = currentNode->south;
                                }
                        }
                        while(east == 0 && destinationFound == 0){
                                strcpy(route[e+indexOfJunction+1], currentNode->name);
                                totalCities += 1;
                                if (strcmp(currentNode->name, To) == 0){
                                        destinationFound = 1;
                                        break;
                                }
                                if(currentNode->east == NULL){
                                        east = 1;
                                        //Given destinationFound is 0, if it's an end node, this resets the route list
                                        if(destinationFound == 0){
                                                for(int a = 2*LOCATIONS; a < indexOfJunction ; a--){
                                                        for (int b = 0; b < MAXSTRING; b++){
                                                                route[a][b] = '\0';
                                                        }
                                                }
                                        }
                                        currentNode = NSJunction->west;
                                        totalCities = totalCities-e;
                                        break;
                                }
                                currentNode = currentNode->east;
                                e += 1;
                        }
                        while(west == 0 && destinationFound == 0){
                                strcpy(route[w+indexOfJunction+1], currentNode->name);
                                totalCities += 1;
                                if (strcmp(currentNode->name, To) == 0){
                                        destinationFound = 1;
                                        break;
                                }
                                if(currentNode->west == NULL){
                                        west = 1;
                                        //Given destinationFound is 0, if it's an end node, this resets the route list
                                        if(destinationFound == 0){
                                                for(int a = 2*LOCATIONS; a <indexOfJunction ; a--){
                                                        for (int b = 0; b < MAXSTRING; b++){
                                                                route[a][b] = '\0';
                                                        }
                                                }
                                        }
                                        currentNode = NSJunction;
                                        totalCities = totalCities-w;
                                        break;
                                }
                                currentNode = currentNode->west;
                                w += 1;
                        }

		}
   	}
	printf("\n");
	printf("Here is the route from %s to %s\n", From, To);
	for(int z = 0; z <totalCities; z++){
		Push(stack1,route[z]);
	}
	printf("\n");  
}  

void main(void){
	void printRoute(char *To, char *From, Location ewCities[], Location nsCities[], STACK *stack1);
        char *eastToWestList[] = {"Sandy","Boring","Gresham","East Portland","i5","West Portland","Sylvan","Beaverton","Tanasbourne","Hillsboro","North Plains","Mountaindale"};
	char *northToSouthList[] = {"Vancouver","North Portland","Hwy 26","South Portland","Tigard","Lake Oswego","Tualatin","Stafford","Wilsonville","Aurora","Hubbard","Woodburn"};
	Location eastWestMap[LOCATIONS]; // An array of east to west city nodes
	Location northSouthMap[LOCATIONS]; // An array of north to south city nodes
	char origin[MAXSTRING];
	char destination[MAXSTRING];
	STACK *stack1;
	STACK *stack2;
	stack1 = malloc(sizeof(STACK_ELEMENT));
	stack2 = malloc(sizeof(STACK_ELEMENT));
	STACK_ELEMENT tempNode;
	createStack(stack1);
	createStack(stack2);	
	//Initializing nodes
        for (int i = 0; i< LOCATIONS; i++){
                strcpy(eastWestMap[i].name,eastToWestList[i]);
		strcpy(northSouthMap[i].name,northToSouthList[i]);
                if(i == 0){
                        eastWestMap[i].east = NULL;
                        eastWestMap[i].west = &eastWestMap[1];
                        eastWestMap[i].south = NULL;
                        eastWestMap[i].north = NULL;
			
			northSouthMap[i].east = NULL;
                        northSouthMap[i].west = NULL;
                        northSouthMap[i].south = &northSouthMap[1];
                        northSouthMap[i].north = NULL;
                }else if(i == LOCATIONS-1){
                        eastWestMap[i].east = &eastWestMap[LOCATIONS-2];
                        eastWestMap[i].west = NULL;
                        eastWestMap[i].south = NULL;
                        eastWestMap[i].north = NULL;
			
			northSouthMap[i].east = NULL;
                        northSouthMap[i].west = NULL;
                        northSouthMap[i].south = NULL;
                        northSouthMap[i].north = &northSouthMap[LOCATIONS-2];
                }else{
                        eastWestMap[i].east = &eastWestMap[i-1];
                        eastWestMap[i].west = &eastWestMap[i+1];;
                        eastWestMap[i].south = NULL;
                        eastWestMap[i].north = NULL;

			northSouthMap[i].east = NULL;
                        northSouthMap[i].west = NULL;
                        northSouthMap[i].south = &northSouthMap[i+1];
                        northSouthMap[i].north = &northSouthMap[i-1];
                }
        }

	//Merging two maps
	eastWestMap[4].south = northSouthMap[2].south;
        eastWestMap[4].north = northSouthMap[2].north;
	northSouthMap[2].east = eastWestMap[4].east;
        northSouthMap[2].west = eastWestMap[4].west;
	
	//Takes input from the user
	inputCheck("Hello!, please enter the origin: ", origin, eastWestMap, northSouthMap);
	inputCheck("Please enter the destination: ", destination, eastWestMap, northSouthMap);
       	printRoute(origin, destination, eastWestMap, northSouthMap, stack1); //Function which prints cities between origin and destination
	while (stack1->head->prev != NULL){
		tempNode = Pop(stack1);
		Push(stack2, tempNode.name);
	}
	while (stack2->head->prev != NULL){
                tempNode = Pop(stack2);
                printf("%s\n", tempNode.name);
        }
}

