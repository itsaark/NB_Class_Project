#include<stdio.h>
#include<string.h>

typedef struct Location{
	char name[80];
	struct Location *east;
	struct Location *west;
	struct Location *north;
	struct Location *south;
}Location;

void getRoute(char *from, char *to, struct Location map){
	int route[12] = {0};
	for (int i = 0, i < 12, i++){
		if(strcmp(from,map[i].name) == 0){
			route[i] = 1;
			break;	
		}
	}
} 

void main(void){
	void getRoute(char *from, char *to, struct Location map);
	char *eastToWestList[] = {"Sandy","Boring","Gresham","East Portland","i5","West Portland","Sylvan","Beaverton","Tanasbourne","Hillsboro","North Plains","Mountaindale"};
	Location eastWestMap[12];
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

}
