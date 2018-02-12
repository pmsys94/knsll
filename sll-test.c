#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testfuncs.h"

void showMenu();

int main(){
#ifdef DEBUG
	fprintf(stderr, "[DEBUG] PROGRAM RUNS IN DEBUG MODE !!\n");
#endif
	printf("Test application for libknsll\n");
		int menupoint = 99;
		do{
printf("This application can currently do nothing!\nIt will be there later...\n");
break;
			printf("\n\n");
			showMenu();
			printf("choice: ");
			if(scanf("%d", &menupoint) == 0) fprintf(stderr, "Menu choice was not a vaild input\n");
			switch(menupoint){
			case 0:
				break;
			case 1: {
				
				break;
				}
			case 2: {
							
				break;
				}
			case 3: {
				
				break;
				}
			default: {
				printf("Input is not a valid menu point!\n");
				}
			}
		}while(menupoint);
	return 0;
}

void showMenu(){
	printf(	"[0] - End Application\n"
	);
}
