#include<stdlib.h>
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


int len(object_t *obj){
	if(!obj) return -1 ; 

	switch(obj->type){
		case INTEGER : 
			return 1 ; 
		case FLOAT : 
			return 1 ; 
		case STRING : 
			return strlen(obj->data.v_string);
		case ARRAY : 
			return obj->data.v_array.size ; 
		default : 
			return -1 ; 
	}
}


object_t *add(object_t *a , object_t *b){
	if(!a || !b) return NULL ;

	switch(a->type){
		case INTEGER : 
			switch(b->type){
				case INTEGER : 
					int sum = a->data.v_int + b->data.v_int ; 
					return new_integer(sum) ; 
				case FLOAT : 
					float fsum = a->data.v_int + b->data.v_float ;
					return new_float(fsum) ; 
				default : 
					return NULL ; 
			}
		case FLOAT : 
			switch(b->type){
				case FLOAT : 
					float sum = a->data.v_float + b->data.v_float;
					return new_float(sum);
				case INTEGER : 
					add(b , a) ; 
				default : 
					return NULL ; 
			}
		case STRING : 
			switch(b->type){
				case STRING : 
					size_t total_size = len(a) + len(b) + 1 ;
					char *buf = (char*)malloc(sizeof(char) * total_size) ; 
					if(!buf) return NULL ; 
					strcat(buf , a->data.v_string) ; 
					strcat(buf , b->data.v_string) ; 

					object_t *newstring = new_string(buf) ;
					free(buf); 
					return newstring ;
				default : 
					return NULL ; 
			}
		case ARRAY : 
			switch(b->type){
				case ARRAY :
					return NULL ;
				default : 
					return NULL ; 
			}
	}
}









