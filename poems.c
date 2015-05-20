/* Poems c-harjoitus
	poems.c 
		Actual poems handling functions
	
	20.05.2015 
	Hannu Harju
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH  80

char line[MAX_LINE_LENGTH];

FILE *file;

/**
  *This function loads the file poems.txt for later use
  *
  */
void loadPoems(void){
    
	file = fopen("poems.txt","r+");
    
	//Did we get the file pointer?
	if(NULL == file){
		//No print error message and return
		printf("Failed to open file poems.txt for reading.\n");
		return;
	}    
}

void printPoem(char * poem_name){
	int found = 0;
    
	while(fgets(line,MAX_LINE_LENGTH,file) != NULL){

		if(strncmp(line,poem_name,strlen(poem_name)) == 0){
			//printf("%s",line);
			found = 1;
		}
        
		if(found == 1){
			if(strncmp(line,"end",strlen("end")) == 0){
				break;
			}

			printf("%s",line);
		}/* If(found == 1) */

	} /* while() */

} /* End of function */
/* *********************************
  ** List all Poem names  ****
  ********************************** */
char Poem_name[MAX_LINE_LENGTH];

void printPoemList(void){
	char No_Poem = 1;

	while(fgets(Poem_name,MAX_LINE_LENGTH,file) != NULL){
		unsigned char line_len;
		line_len = strlen(Poem_name);

		if((line_len > 1) && (No_Poem)){
		//	printf(" %d -> %s", line_len, Poem_name);
			printf(" %s", Poem_name);			
			No_Poem = 0;
		}

		if(strncmp(Poem_name,"end",strlen("end")) == 0){
			No_Poem = 1;
		}
	} /* While() */

}
/* *********************************
  ** Add new poem   ****
  ********************************** */
char Poem_line[MAX_LINE_LENGTH];


void AddPoem(char * poem_name){
	char Poem_continue;
	/* Open file for writing */
//	file = fopen("poems.txt","a");
	Poem_continue = 1;
	printf(" Enter new poem \"%s\", write \"end\" to finish poem  \n", poem_name);
	do{
		char loppu_merkki;
		scanf("%s", Poem_line);
	//	scanf("%79[^\r\n]", Poem_line);

		if(strncmp(Poem_line,"end",strlen("end")) == 0){
			Poem_continue = 0;
		}
		
		printf("%s ", Poem_line);

	}while(Poem_continue);
//fprintf(fp, "This is testing...\n");
		printf(" DONE!");


}

/* End of file */
