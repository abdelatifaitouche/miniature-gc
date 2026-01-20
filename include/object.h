#include<stdlib.h>

typedef struct Object object_t ; 


typedef enum ObjectType{
	INTEGER , 
	FLOAT , 
	STRING , 
	ARRAY , 
	VECTOR3
}object_type_t ;

typedef struct Array{
	size_t size ; 
	object_t **collection ; 
}array_t;


typedef union ObjectData{
	int v_int ; 
	float v_float ; 
	char *v_string ; 
	array_t v_array ; 
}object_data_t ; 


struct Object{
	object_type_t type ;
	object_data_t data ; 
};



object_t *new_integer(int value) ;
object_t *new_float(float value) ; 
object_t *new_string(char *string) ; 
object_t *new_array(size_t size) ; 

int set_array_value(object_t *arr , object_t *value , unsigned int index) ;
object_t *get_array_value(object_t *arr , unsigned int index) ; 
int len(object_t *obj);
object_t *add(object_t *a , object_t *b) ; 

