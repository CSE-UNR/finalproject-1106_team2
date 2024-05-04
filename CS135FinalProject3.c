//Project Design Testing int version (bruh)

#include <stdio.h>
#include <stdbool.h>

#define STRMAX 50
#define SIZEMAX 40
//#define fileName "image.txt"

void getFilename(char name[]);
int readFile(int rows, int cols, int img[][cols],int* rcount, FILE* ptr);
void printImage(int rCount, int cCount, int cols, int img[][cols], FILE* ptr);
void cropImage(int newL, int newR, int newTop, int newBot, int rCount, int cCount, int cols, int img[][cols], int edit[][cols]);
void imageBrightness(int rCount, int cCount, int cols, int img[][cols], int lvlFactor, int edit[][cols], FILE* ptr);
int main(){
	char fileName[STRMAX];
	int image[SIZEMAX][SIZEMAX]={0}, edit[SIZEMAX][SIZEMAX]={0}, rowSize=0, colSize=0, lvlFactor = 2;
	FILE* fptr;
	
	getFilename(fileName);
	
	fptr = fopen(fileName,"r");
	
	if(fptr == NULL){
		printf("File could not be opened.\n");
		return 0;
	}
	
	
	colSize = readFile(SIZEMAX,SIZEMAX,image,&rowSize,fptr);
	
	fclose(fptr);
	
	printImage(rowSize,colSize,SIZEMAX,image,stdout);

	///// crop menu will define these new size values
	
	//int newL=4, newR=18, newTop=2, newBot=11;
	
	//cropImage(newL,newR,newTop,newBot,rowSize,colSize,SIZEMAX,image,edit);
	
	imageBrightness(rowSize, colSize, SIZEMAX, image, lvlFactor, edit, stdout);
	
	printImage(rowSize, colSize,SIZEMAX,edit,stdout);
	
	//printf("%d\n", newBot-newTop);
	//printf("%d\n", newR-newL);
	
	//printf("%d\n", colSize);
	//printf("%d\n", rowSize);
	
	getFilename(fileName);
	
	fptr = fopen(fileName,"w");
	
	if(fptr == NULL){
		printf("Upload File could not be opened.\n");
		return 0;
	}
	
	//printImage(newBot-newTop+1,newR-newL+1,SIZEMAX,edit,fptr);
	
	fclose(fptr);
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

void printImage(int rCount, int cCount, int cols, int img[][cols], FILE* ptr){
	for(int rowI=0;rowI<rCount;rowI++){
		for(int colI=0;colI<cCount;colI++){
			if(ptr == stdout){
				switch(img[rowI][colI]){
					case 0:
						fprintf(ptr," ");
						break;
					case 1:
						fprintf(ptr,".");
						break;	
					case 2:
						fprintf(ptr,"o");
						break;
					case 3:
						fprintf(ptr,"O");
						break;
					case 4:
						fprintf(ptr,"0");
						break;
				}
				fprintf(ptr,"%c",img[rowI][colI]);
			}
			else{ 
				fprintf(ptr,"%d",img[rowI][colI]);
			}
		}
		fprintf(ptr,"\n");
	}
}
				
void cropImage(int newL, int newR, int newTop, int newBot, int rCount, int cCount, int cols, int img[][cols], int edit[][cols]){
	int editColI,editRowI = 0;
	for(int rowI=newTop-1;rowI<newBot;rowI++){
		editColI=0;
		for(int colI=newL-1;colI<newR;colI++){
			edit[editRowI][editColI]=img[rowI][colI];
			editColI++;
		}
		editRowI++;
	}
}
void imageBrightness(int rCount, int cCount, int cols, int img[][cols], int lvlFactor, int edit[][cols], FILE* ptr){
	for(int rowI = 0; rowI < rCount; rowI++){
		for(int colI = 0; colI < cCount; colI++){
			if(lvlFactor > 0 && img[rowI][colI] == 4){
				edit[rowI][colI] = 4;
			}
			else if(lvlFactor < 0 && img[rowI][colI] == 0){
				edit[rowI][colI] = '0';
			}
			else{
				edit[rowI][colI]=img[rowI][colI]+1;
			}
		}		
	}
}
