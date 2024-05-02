//Project Design Testing int version (bruh)

#include <stdio.h>

#define STRMAX 50
#define SIZEMAX 40
//#define fileName "image.txt"

void getFilename(char name[]);
int readFile(int rows, int cols, int img[][cols],int* rcount, FILE* ptr);
void displayImage(int rCount, int cCount, int cols, int img[][cols], FILE* ptr);
void cropImage(int TopBot, int LeftRi, int rowsize, int charsize, int cols,int img[][cols],int* newRowSize,int* newCharSize);

int main(){
	char fileName[STRMAX];
	int image[SIZEMAX][SIZEMAX], rowSize=0, colSize=0;
	FILE* fptr;
	
	getFilename(fileName);
	
	fptr = fopen(fileName,"r");
	
	if(fptr == NULL){
		printf("File could not be opened.\n");
		return 0;
	}
	
	
	colSize = readFile(SIZEMAX,SIZEMAX,image,&rowSize,fptr);
	
	
	fclose(fptr);
	
	displayImage(rowSize,colSize,SIZEMAX,image,stdout);
	
	printf("%d\n", colSize);
	printf("%d\n", rowSize);
	
	
	
	return 0;
}

void getFilename(char name[]){
	printf("What is the name of your file? [example.txt]\n");
	fgets(name,STRMAX,stdin);
	
	for(int i=0; name[i] != '\0'; i++){
		if(name[i] == '\n'){
			name[i] = '\0';
		}
	}
}

int readFile(int rows, int cols, int img[][cols],int* rcount, FILE* ptr){
	char temp = '0';
	int cCount ,colI;
	for(int rowI=0;rowI<rows;rowI++){
		colI = 0;
		while(fscanf(ptr,"%c",&temp)==1 && temp != '\n'){
			img[rowI][colI]=temp-'0';
			colI++;
			cCount = colI;
			*rcount = rowI+1;
		}
	}
	return cCount;
}

void displayImage(int rCount, int cCount, int cols, int img[][cols], FILE* ptr){
	for(int rowI=0;rowI<rCount;rowI++){
		for(int colI=0;colI<cCount;colI++){
			fprintf(ptr,"%d",img[rowI][colI]);
		}
		fprintf(ptr,"\n");
	}
}
				





