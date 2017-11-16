# Final Project for NB Foundation class


## Getting Started
This program helps you find the route between two cities from the following list of following cities:

["Sandy", "Boring", "Gresham", "East Portland", "i5", "West Portland", "Sylvan", "Beaverton", "Tanasbourne", "Hillsboro", "North Plains", "Mountaindale"]

### Pseudo code.
Our approach to this program is pretty straightforward. We are using an array composed of structs of nodes defined by typedef:

```
typedef struct Location {
	char name[20];
	struct Location *east;
	struct Location *west;
	struct Location *north;
	struct Location *south;
}Location;
```
In our main function, we hardcode the city names into an array:

```

char *eastToWestList[] = {"Sandy", "Boring", "Gresham", "East Portland", "i5", "West Portland", "Sylvan", "Beaverton", "Tanasbourne",
				"Hillsboro", "North Plains", "Mountaindale"};

```

Then we take the names from the array and create an array of linked structs:

```

Location eastWestMap[12]; // An array of city nodes

for (int i = 0; i < 12; i++){
	strcpy(eastWestMap[i].name, eastToWestList[i]);
	if (i == 0){
		eastWestMap[i].east = NULL;
		eastWestMap[i].west = &eastWestMap[1];
		eastWestMap[i].south = NULL;
		eastWestMap[i].north = NULL;

```
We hardcode the first name on our eastToWestList as the head, so there is a null pointer to the east, and we set the pointer to the next name on the list.
For the remainder of the list, we set the east pointer to i-1, and the west pointer to i+1, except for the last name, where we set the west pointer to null.

Next in main, we run the function "inputCheck",  which takes user input stored as a char array named "origin" and our eastWestMap linked arrays.

```

inputCheck("Hello!, please enter the origin: ", origin, eastWestMap);

```

inputCheck checks to see if the user input is the same as a value on our list:

```
void inputCheck (char message[], char input[15], Location [Map])//lookup struct name
{
	int condition = 1;
	while (condition !=0)
	{
		printf("\n %s, message); 
		fgets(input, 15, stdin);
		input[strcspn(input, "\n")] = '\0';
		for(int i = 0; i < 12; ++i)
                {
                        condition = strcmp(input, Map[i].name);
                        if(condition == 0) break;
                }
                if(condition == 0) return;
                printf("Invalid input. Try again. \n");
        }
}

```

Once the user inputs a correct value, we search for the origin:

```
for (int i = 0; i < 12; i++){
	if (strcmp(From, cities[i].name) == 0) {
		origin = &cities[i];
		break;
	}
}
```

Then we look for the destination:

```

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

```
After a destination is found, we print out the list of cities:

```

printf("\n");
	printf("Here is the route from %s to %s\n", From, To);
	for(int z = 0; z <totalCities; z++){
		printf("%s\t",route[z]);
	}
	printf("\n");  

```

### Working with the code

The program runs on a case-sensitive code. So please input the names of cities according to the list provided above.


```
Hello!, please enter the origin:  Sandy

Please enter the destination:  South Portland

Here is the route from Sandy to South Portland
Sandy	Boring	Gresham	East Portland	i5	South Portland	
```

### Tests

Here are some test cases:

1. Traversing from west origin to east desination.

```

 Hello!, please enter the origin:  Boring

 Please enter the destination:  Sandy

Here is the route from Boring to Sandy
Boring  Sandy

```
2. Traversing from east origin to west destination.

```
 Hello!, please enter the origin:  Sandy

 Please enter the destination:  i5

Here is the route from Sandy to i5
Sandy   Boring  Gresham East Portland   i5

```

3. Origin and destination are the same.

```
 Hello!, please enter the origin:  Hillsboro

 Please enter the destination:  Hillsboro

Here is the route from Hillsboro to Hillsboro
Hillsboro

```
4. Name of origin or destination is misspelled.

```
Hello!, please enter the origin:  Hillsbord
Invalid input. Try again. 

 Hello!, please enter the origin:  Hillsboro   

 Please enter the destination:  Sandoops
Invalid input. Try again. 

 Please enter the destination:  Sandy

Here is the route from Hillsboro to Sandy
Hillsboro       Tanasbourne     Beaverton       Sylvan  West Portland   i5      East Portland   Gresham Boring  Sandy

```
## License

This project is licensed under the MIT License

## Acknowledgments

* Inspiration
