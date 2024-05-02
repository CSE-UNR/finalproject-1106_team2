//Project Design Testing

#include <stdio.h>

#define STRMAX 50
#define SIZEMAX 40
//#define fileName "image.txt"

void getFilename(char name[]);
int readFile(int rows, int cols, char img[][cols],int* rcount,FILE* ptr);
void displayImage(int cols, char img[][cols], FILE* ptr);
void brightLevel(int level, int cols, char img[][cols], FILE* ptr);
void cropImage(int TopBot, int LeftRi, int rowsize, int charsize, int cols,char img[][cols],int* newRowSize,int* newCharSize);

int main(){
	char fileName[STRMAX];
	char image[SIZEMAX][SIZEMAX]={0};
	int rowCount=0, charCount=0;
	FILE* fptr;
	
	//do while loop(while input is not 5)
		//display main menu function
		//get user input

		//switch selection for input 1:
			//if input is 1:
				//get file name function
				//open filename stream in read mode
				//if pointer is null
					//display failure message
				//else 
					//read file function
					//close file stream

			//if input is 2:
				//display image function

			//if input is 3:
				//display edit menu function
				//get user input
				
				//switch selection for input:
					//if input is 1:
						//crop image function
					//if input is 2:
						//dim/brighten image funct w/ parameter var 1
					//if input is 3:
						//dim/brighten image funct w/ parameter var -1
						
			//if input is 4:
				//get file name function
				//open filename stream in write mode
				//if pointer is null
					//display failure message
				//else
					//display image function (edited image, filename pointer)
					
			//if input is 5: 
				//do nothing
				
	//(end loop)

		
	
	//}while(input != 5);
	
	getFilename(fileName);
	
	fptr = fopen(fileName,"r");
	
	if(fptr == NULL){
		printf("File could not be opened.\n");
		return 0;
	}
	
	
	charCount = readFile(SIZEMAX,SIZEMAX,image,&rowCount,fptr);
	
	fclose(fptr);
	
	//Cut 1 from top: TopBot=1, LeftRi=0
	//Cut 1 from left: TopBot=0,LeftRi=1
	//Cut 1 from bottom: TopBot=-1, LeftRi=0
	//Cut 1 from right: TopBot=0, LeftRi=-1
	
	cropImage(5,0,rowCount,charCount,SIZEMAX, image,&rowCount,&charCount);
	cropImage(0,10,rowCount,charCount,SIZEMAX, image,&rowCount,&charCount);
	
	brightLevel(1,SIZEMAX,image,stdout);
	
	displayImage(SIZEMAX,image,stdout);
	
	printf("%d\n", charCount);
	printf("%d\n", rowCount);
	printf("%c\n", image[0][0]+1);
	
	
	
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

int readFile(int rows, int cols, char img[][cols],int* rcount, FILE* ptr){
	int ccount=0;
	for(int rowI=0;rowI<SIZEMAX;rowI++){
		fgets(img[rowI],SIZEMAX,ptr);
	}
	
	for(int rowI=0;rowI<SIZEMAX;rowI++){
		for(int strI=0;img[rowI][strI] != '\0';strI++){
			*rcount = rowI;
			ccount = strI;
			//printf("%d %c\n",rowI,img[rowI][strI]);
		}
	}
	*rcount = *rcount+1;
	
	return ccount;
}



void displayImage(int cols, char img[][cols], FILE* ptr){
	for(int rowI=0;rowI<SIZEMAX;rowI++){
		for(int strI=0;img[rowI][strI] != '\0';strI++){
			switch(img[rowI][strI]){
				case '0':
					fprintf(ptr," ");
					break;
				case '1':
					fprintf(ptr,".");
					break;	
				case '2':
					fprintf(ptr,"o");
					break;
				case '3':
					fprintf(ptr,"O");
					break;
				case '4':
					fprintf(ptr,"0");
					break;
				case '\n':
					fprintf(ptr,"\n");
					break;	
			}
		}
	}
}

void brightLevel(int level, int cols, char img[][cols], FILE* ptr){
	for(int rowI=0;rowI<SIZEMAX;rowI++){
		for(int strI=0;img[rowI][strI] != '\0';strI++){
			if(level>0 && img[rowI][strI]=='4'){
				img[rowI][strI] = '4';
			}
			else if(level<0 && img[rowI][strI]=='0'){
				img[rowI][strI] = '0';
			}
			else{
				if(img[rowI][strI] == '\n' ){
					img[rowI][strI] = '\n';
				}
				else{
					img[rowI][strI]=img[rowI][strI]+level;
				}
			}
		}
	}
}


void cropImage(int TopBot, int LeftRi, int rowsize, int charsize, int cols,char img[][cols],int* newRowSize,int* newCharSize){
	for(int rowI=0;rowI<SIZEMAX;rowI++){
		for(int strI=0;img[rowI][strI] != '\0';strI++){
			if(TopBot < 0){
				img[rowI][strI]=img[rowI][strI];
				if(rowI >= rowsize+TopBot){
					img[rowI][strI]='\0';
				}
				*newRowSize=rowsize+TopBot;
			}
			else if(LeftRi < 0){
				img[rowI][strI]=img[rowI][strI];
				if(strI >= charsize+LeftRi){
					img[rowI][strI]='\0';
					img[rowI][charsize+LeftRi]='\n';
				}
				*newCharSize=charsize+LeftRi;
			}
			else{
				img[rowI][strI]=img[rowI+TopBot][strI+LeftRi];
				*newRowSize=rowsize-TopBot;
				*newCharSize=charsize-LeftRi;
			}
		}
	}
}






