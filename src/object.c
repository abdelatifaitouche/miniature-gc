#include<stdlib.h>
#include<stdio.h>
#include "../include/object.h"
#include<string.h>



object_t *new_integer(int value){
	//creating an Integer Object 
	//Type INTEGER
	//Data v_int value
	
	object_t *obj = (object_t*)malloc(sizeof(object_t)) ; 

	if(!obj) return NULL ; 

	obj->type = INTEGER ; 
	obj->data.v_int = value ; 

	return obj;

}


object_t *new_float(float value){
	//Creating a floating object
	//Type FLOAT
	//Data v_float
	
	object_t *obj = (object_t*)malloc(sizeof(object_t)) ; 
	if(!obj) return NULL ; 

	obj->type = FLOAT ; 
	obj->data.v_float = value ; 

	return obj ; 
}


object_t *new_string(char *string){
	
	object_t *obj = (object_t*)malloc(sizeof(object_t)) ; 
	if(!obj) return NULL ; 

	size_t len = strlen(string) + 1 ; //include the \O
	
	char *dst = (char*)malloc(sizeof(char) * len) ; //Allocating a memory space for the string
							
	
	if(!dst){
		free(obj);
		return NULL ; 
	}

	strcpy(dst , string) ; 
	obj->data.v_string = dst ; 
	obj->type = STRING ; 

	return obj ; 
}



