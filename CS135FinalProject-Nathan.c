//Project Design Testing

#include <stdio.h>

#define STRMAX 50
#define SIZEMAX 25
//#define fileName "image.txt"

int readFile(int rows, int cols, char img[][cols],int* rcount,FILE* ptr);
void displayImage(int cols, char img[][cols], FILE* ptr);

int main(){
	char fileName[STRMAX];
	char image[SIZEMAX][SIZEMAX],edit[SIZEMAX][SIZEMAX];
	int rowCount, charCount;
	
	FILE* fptr;
	
	printf("What is the name of your file? [example.txt]\n");
	fgets(fileName,STRMAX,stdin);
	
	for(int i=0; fileName[i] != '\0'; i++){
		if(fileName[i] == '\n'){
			fileName[i] = '\0';
		}
	}

	
	fptr = fopen(fileName,"r");
	
	if(fptr == NULL){
		printf("File could not be opened.\n");
		return 0;
	}
	
	charCount = readFile(SIZEMAX,SIZEMAX,image,&rowCount,fptr);
	
	fclose(fptr);
	
	displayImage(SIZEMAX,image,stdout);
	
	printf("%d\n", charCount);
	
	printf("%d\n", rowCount);
	
	
	
	return 0;
}

//void 
//	printf("What is the name of your file? [example.txt]\n");
//		fgets(fileName,STRMAX,stdin);
//	
//	for(int i=0; fileName[i] != '\0'; i++){
//		if(fileName[i] == '\n'){
//			fileName[i] = '\0';
//		}
//	}

int readFile(int rows, int cols, char img[][cols],int* rcount, FILE* ptr){
	int ccount=0;
	for(int rowI=0;rowI<SIZEMAX;rowI++){
		fgets(img[rowI],SIZEMAX,ptr);
	}

	for(int rowI=0;rowI<SIZEMAX;rowI++){
		for(int strI=0;img[rowI][strI] != '\0';strI++){
			*rcount = rowI+1;
			ccount = strI-1;
		}
	}
	
	return ccount;
}

void displayImage(int cols, char img[][cols], FILE* ptr){
	for(int rowI=0;rowI<SIZEMAX;rowI++){
		for(int strI=0;img[rowI][strI] != 0;strI++){
			fprintf(stdout,"%c",img[rowI][strI]);
		}
	}
}

void cropImage(int cols, char img[][cols], FILE* ptr){
	for(int rowI=0;rowI<SIZEMAX;rowI++){
		for(int strI=0;img[rowI][strI] != 0;strI++){
			if(rowI+TopBot < 0){
				edit[rowI][strI]=img[rowI][strI]
			}
			else if(strI+LeftRi < 0){
				edit[rowI][strI]=img[rowI][strI]
			}
			
			img[rowI][strI]=img[rowIndex+TopBot][strI+LeftRi]
		}
	}
	
	displayImage(SIZEMAX,edit[][cols]
}
	




