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


object_t *new_array(size_t size){
	object_t *obj = (object_t*)malloc(sizeof(object_t)) ; 
	if(!obj) return NULL ; 
	
	obj->type = ARRAY ; 
	
	object_t **collection = (object_t**)calloc(size , sizeof(object_t*)) ; 

	if(!collection){
		free(obj) ; 
		return NULL ; 
	}

	obj->data.v_array.collection = collection ; 
	obj->data.v_array.size = size ; 

	return obj ; 
}


int set_array_value(object_t *arr , object_t *value , unsigned int index){
	if(!arr || !value) return 1 ; 

	if(arr->type != ARRAY) return 1 ; 

	if(index >= arr->data.v_array.size) return 1 ; 

	arr->data.v_array.collection[index] = value ;

	return 0 ; 
}


object_t *get_array_value(object_t *arr , unsigned int index){
	if(!arr) return NULL ; 

	if(index >= arr->data.v_array.size) return NULL ; 
	
	object_t *obj = arr->data.v_array.collection[index] ; 

	return obj ; 

}



