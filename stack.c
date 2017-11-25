#include <stdio.h>                                
#include <string.h>                               
#include <stdlib.h>                               
                                                  
                                                  
typedef struct STACK_ELEMENT {                    
        char name[15];                            
        struct STACK_ELEMENT *prev;               
}STACK_ELEMENT;                                   
                                                  
                                                  
typedef struct stack {                            
        struct STACK_ELEMENT *head;               
}stack;                                           
                                                  
                                                  
void createStack(stack *s) {                      
        STACK_ELEMENT *head;                      
        head = malloc(sizeof(STACK_ELEMENT));     
        head->prev = NULL;                        
        strcpy(head->name, "STOP");               
        s->head = head;                           
}                                                 
                                                  
void push (stack *s, char newItem[]){             
        STACK_ELEMENT *temp;                      
        temp = s->head;                           
        s->head = malloc(sizeof(STACK_ELEMENT));  
        s->head->prev = temp;                     
        strcpy(s->head->name, newItem);           
}                                                 
                                                  
struct STACK_ELEMENT  pop(stack *s){              
        STACK_ELEMENT returnName;                 
        STACK_ELEMENT *temp;                      
        temp = s->head;                           
        s->head = temp->prev;                     
        returnName = *temp;                       
        free(temp);                               
        return returnName;                        
}                                                 
                                                  
                                                  
~                                                 
~                                                 
~                                                 
~                                                 
~                                                 
