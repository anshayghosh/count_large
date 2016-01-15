#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_permission(char file[], char req[]);

int main (int argc, char *argv[])
{
	//the condition if no arguments are provided
    if (argc == 1){
    	printf("Error: no arguments inputted.\n");
    	return -1;
    }
	//initializing all variables for the loops
	char* strpart;
	int lim = atoi(argv[1]);
	int finalval=0;
    char str[100];
    int counter = 0;
    //started a while loop in order to input every line of the redirected/piped file. 
    while(!(feof(stdin))){
    	//get the first line of the loop
    	fgets(str,100,stdin);
    	//if statement in orded to skip the first two lines of the ls -l output
    	if (counter >=1){
    		//initialize another counter to know which part of the code we're on
    		int partcounter = 0;
    		strpart = strtok(str," ");
    		int possible = 1;
    		//loop to go through each part of the line seperated by " " 
    		while (strpart!=NULL){
    			//check whether the current file is directory
    			if (partcounter == 0){
    				if(check_permission(strpart,"d---------")==1){
    					possible =0;
   					}
   				}
   				//if not check if there is an extra argument for the the specified file permissions.
    			if ((argc==3)&&(possible==1)){
    				if (partcounter == 0){
    					strpart++;
    					if(check_permission(strpart,argv[2])==0){
    						possible =0;
    					}
    				}
    			}
    			//finally check the size of the file and compare it to the limit
    			if((possible == 1)&&(partcounter==4)){
    				int value = atoi(strpart);
    				if (value>=lim ){
    					finalval++;
    				}
    			}
    			partcounter++;
    			strpart = strtok(NULL, " ");
   			}
   		}
    		
   		counter++;
   	}
   	printf("%d\n",finalval);	
    return 0;
    
}

int check_permission(char file[], char req[]){
	//initialize the required variables
	int size = strlen(req);
	int i =0;
	int val=1;
	//run a loop in order to compare the non "-" parts of the req string and check if they match the file string
	for(i = 0;i<size;i++){
		if(req[i]!='-'){
			if (req[i]!=file[i]){
				val = 0;
			}
		}
	}
	return val;
}
