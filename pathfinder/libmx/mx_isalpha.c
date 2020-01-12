#include <stdbool.h>
#include <stdio.h>

bool mx_isalpha(int c){
	int returned_bool;
	
	if((c > 64 && c < 91) || (c > 96 && c < 123 )){
		returned_bool = 1;
	}else{
		returned_bool = 0;
	}
	
	return returned_bool;
}
