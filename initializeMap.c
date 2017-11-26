#include "header.h"


void  initializeMap(Location map[])
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
