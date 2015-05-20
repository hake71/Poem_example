/* Poems c-harjoitus
	main.c 
		main function
	
	20.05.2015 
	Hannu Harju
*/

#include <stdio.h>
#include <string.h>

#include "poems.h"

int main(int argc, char *argv[]){

//Check the number of command line arguments should be 2
	if(argc < 2){
		printf("Usage of application is: app.exe -switch\n");
		printf("Switches are:\n");
		printf("-p name_of_poem : This will load the poem with the given name for you\n");
		printf("-l list :all poems in application.");
		return 0;
	}
    
	loadPoems();
    
	if(strcmp(argv[1],"-p") == 0){
		if(3 > argc){
			printf("The name of the poem must be also given!\n");
			return 0;
		}
		else{
			printPoem(argv[2]);
		}
	}
	else if(strcmp(argv[1],"-l") == 0){
		printf("List all poems:\n");
		printPoemList();
	}
	else{
		printf("No such switch in this application\n");
	}
    
	return 0;
}

/*  End of File */
