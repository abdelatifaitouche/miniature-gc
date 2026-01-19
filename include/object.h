typedef struct Object object_t ; 


typedef enum ObjectType{
	INTEGER , 
	FLOAT , 
	STRING , 
	ARRAY , 
	VECTOR3
}object_type_t ;


typedef union ObjectData{
	int v_int ; 
	float v_float ; 
	char *v_string ; 
}object_data_t ; 


struct Object{
	object_type_t type ;
	object_data_t data ; 
};



object_t *new_integer(int value) ;
object_t *new_float(float value) ; 
object_t *new_string(char *string) ; 

