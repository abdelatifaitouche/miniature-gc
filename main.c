#include<stdio.h>
#include "include/object.h"



int main(void){
	
	object_t *s = new_string("hello ") ; 
	object_t *z = new_string("world") ; 
	
	object_t *cc = add(s , z) ; 

	printf("%s" , cc->data.v_string) ; 

	return 0 ; 
}
