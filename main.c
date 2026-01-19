#include<stdio.h>
#include "include/object.h"



int main(void){
	object_t *x = new_integer(3) ; 
	object_t *s = new_string("Hello world\n");
	printf("%s" , s->data.v_string) ; 

	return 0 ; 
}
