#include<stdio.h>
#include "include/object.h"



int main(void){
	
	object_t *arr = new_array(2) ; 
	object_t *arl = new_array(2) ; 
	
	object_t *x = new_integer(0) ; 
	object_t *y = new_integer(1) ; 
	object_t *z = new_integer(2) ; 
	object_t *t = new_integer(3) ; 
	printf("setting up the values for first array\n");
	set_array_value(arr , x , 0 )  ; 
	set_array_value(arr , y , 1) ; 
	printf("setting up the values for second array\n");
	set_array_value(arl , z , 0) ; 
	set_array_value(arl , t , 1) ;
	printf("creating the add array") ; 
	object_t *adarr = add(arr , arl) ;
	
	for(int i=0 ; i<4 ; i++){
		printf("%d " , get_array_value(adarr , i)->data.v_int) ; 
	}

	printf("\n");

	return 0 ; 
}
