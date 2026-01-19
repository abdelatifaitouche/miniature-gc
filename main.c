#include<stdio.h>
#include "include/object.h"



int main(void){
	object_t *arr = new_array(3) ; 
	
	object_t *x = new_integer(0) ; 
	object_t *y = new_integer(1) ; 
	object_t *z = new_integer(2) ; 

	set_array_value(arr , x , 0) ; 
	set_array_value(arr , y , 1) ; 
	set_array_value(arr , z , 2) ; 

	for(int i=0 ; i<3 ; i++){
		printf("%d\n" , get_array_value(arr , i)->data.v_int) ; 
	}

	return 0 ; 
}
