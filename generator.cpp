#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){

	if(!strcmp(argv[1],"plane")){
		createPlane(argv[2],argv[3]);
	}
	else printf("Argumentos inválidos.\n");


	return 0;
}

void createPlane(int size, char* file_name){
}

void printFile(char* file_name){
	FILE* file;
	file = fopen(file_name,"w");


	fclose(file);
}