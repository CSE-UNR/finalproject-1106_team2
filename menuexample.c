

#include<stdio.h>

int menuFunction(int menuChoice)
int editMenuFunction(int editChoice)
int main(){
}
int menuFunction(int menuChoice){

	int menuChoice;
	
	printf("**ERINSTAGRAM**\n");
	printf("1: Load a new image\n");
	printf("2: Display image\n");
	printf("3: Edit image\n");
	printf("0: Exit\n");
	printf("\nChoose from one of the options above: ");
	scanf("%d", &menuChoice);
	
	return 0;
}

int editMenuFunction(int editChoice){

	int editChoice;
	
	printf("**EDITING**\n");
	printf("1: Crop image\n");
	printf("2: Dim image\n");
	printf("3: Brighten image\n");
	printf("0: Return to main menu\n");
	printf("\nChoose from one of the options above: ");
	scanf("%d", &editChoice);
	
	return 0
}
