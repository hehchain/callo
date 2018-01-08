#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

int list_length(list *head){
    return (head==NULL)?0:list_length(head->neighbours) + 1;
}

void list_add(list **head, char *name, char *ip, char *port, char protocol){
    list *element = (list*)malloc(list);
    element->ip = ip;
    element->name = name;
    element->port = port;
    element->protocol = protocol;
    *head =element;
}

list *list_find(list *head, char *name){

    list *tmp=head,result=NULL;

    while(tmp!=NULL){
        if(strcmp(tmp->name,name)==0){
            result = tmp;
            exit;
        }
        tmp = tmp->neighbours;
    }
    return result;
}
void list_destroy(list **head);//need more specification about this function 
void list_print(list *head);//need more specification about this function 
list *list_remove(list *head, list *element);//need more specification about this function 
