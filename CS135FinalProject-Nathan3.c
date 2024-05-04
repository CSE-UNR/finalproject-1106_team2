//Project Design Testing int version (bruh)

#include <stdio.h>
#include <stdbool.h>

#define STRMAX 50
#define SIZEMAX 40
//#define fileName "image.txt"

void getFilename(char name[]);
int readFile(int rows, int cols, int img[][cols],int* rcount, FILE* ptr);
void printImage(int rCount, int cCount, int cols, int img[][cols], FILE* ptr);
void cropImage(int newL, int newR, int newTop, int newBot, int cols, int img[][cols], int edit[][cols]);
int cropMenu(int rCount, int cCount, int cols, int img[][cols], FILE* ptr,int* newLeft, int* newRight, int* newTop);
char translateImage(int number);

int main(){
	char fileName[STRMAX];
	int image[SIZEMAX][SIZEMAX]={0}, edit[SIZEMAX][SIZEMAX]={0}, rowSize=0, colSize=0;
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
	
	int newL, newR, newTop, newBot;
	
	newBot = cropMenu(rowSize,colSize,SIZEMAX,image,stdout,&newL,&newR,&newTop);
	
	cropImage(newL,newR,newTop,newBot,SIZEMAX,image,edit);
	
	printImage(newBot-newTop+1,newR-newL+1,SIZEMAX,edit,stdout);
	
	////
	
	printf("%d\n", newBot-newTop+1);
	printf("%d\n", newR-newL+1);
	
	printf("%d\n", colSize);
	printf("%d\n", rowSize);
	
	getFilename(fileName);
	
	fptr = fopen(fileName,"w");
	
	if(fptr == NULL){
		printf("Upload File could not be opened.\n");
		return 0;
	}
	
	printImage(newBot-newTop+1,newR-newL+1,SIZEMAX,edit,fptr);
	
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
				fprintf(ptr,"%c",translateImage(img[rowI][colI]));
			}
			else{ 
				fprintf(ptr,"%d",img[rowI][colI]);
			}
		}
		fprintf(ptr,"\n");
	}
}

int cropMenu(int rCount, int cCount, int cols, int img[][cols], FILE* ptr,int* newLeft, int* newRight, int* newTop){
	int newBottom;
	for(int i=0;i<=cCount;i++){
		if(i==1 || i==cCount){
			fprintf(ptr,"%d",i);
		}
		else{
			fprintf(ptr," ");
		}
	}
	fprintf(ptr,"\n");
	for(int rowI=0;rowI<rCount;rowI++){
		if(rowI == 0){
			fprintf(ptr,"1");
		}
		else{
			fprintf(ptr," ");
		}
		for(int colI=1;colI<cCount;colI++){
			fprintf(ptr,"%c",translateImage(img[rowI][colI]));
		}
		fprintf(ptr,"\n");
	}
	fprintf(ptr,"%d\n",rCount);
	printf("The image you want to crop is %d x %d.\n",rCount,cCount);
	printf("Which column do you want to be the new left side? ");
	do{
		scanf("%d",newLeft);
		if(*newLeft<1 || *newLeft>cCount-1){
			printf("Invalid column value. Choose between 1 and %d:",cCount-1);
		}
	}while(*newLeft<1 || *newLeft>cCount-1);
	
	printf("\nWhich column do you want to be the new right side? ");
	do{
		scanf("%d",newRight);
		if(*newRight<*newLeft || *newRight>cCount){
			printf("Invalid column value. Choose between %d and %d:",*newLeft,cCount);
		}
	}while(*newRight<*newLeft || *newRight>cCount);
	
	printf("\nWhich row do you want to be the new top? ");
	do{
		scanf("%d",newTop);
		if(*newTop<1 || *newTop>rCount-1){
			printf("Invalid row value. Choose between 1 and %d:",rCount-1);
		}
	}while(*newTop<1 || *newTop>rCount-1);

	printf("\nWhich row do you want to be the new bottom? ");
	do{
		scanf("%d",&newBottom);
		if(newBottom<*newTop || newBottom>rCount){
			printf("Invalid row value. Choose between %d and %d:",*newTop,rCount);
		}
	}while(newBottom<*newTop || newBottom>rCount);

	return newBottom;
}

char translateImage(int number){
	char symbol;
	switch(number){
		case 0:
			symbol=' ';
			break;
		case 1:
			symbol='.';
			break;	
		case 2:
			symbol='o';
			break;
		case 3:
			symbol='O';
			break;
		case 4:
			symbol='0';
			break;
	}
	return symbol;
}

void cropImage(int newL, int newR, int newTop, int newBot, int cols, int img[][cols], int edit[][cols]){
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




