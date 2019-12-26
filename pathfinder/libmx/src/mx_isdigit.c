#include <stdbool.h>
#include <stdio.h>

bool mx_isdigit(int c){
	int returned_bool;
	
	if( c > 47 && c < 58 ){
		returned_bool = 1;
	}else{
		returned_bool = 0;
	}
	
	return returned_bool;
}
