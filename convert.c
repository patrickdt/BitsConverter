#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char ** argv){

	if (argc < 4) {
		printf("Usage:  convert <basefrom> <baseto> <number>\n");
		exit(1);	
	}

	int basefrom = atoi(argv[1]);
	int baseto = atoi(argv[2]);
	long int number = atol(argv[3]);

	printf("Number read in base %d: %s\n", basefrom, argv[3]);

	//Trying to convert number for whatever base to decimal value
	int digits = strlen(argv[3]);
	int dec_val = 0; //decimal value
	for(int i = 0; i < digits; i++){
		char val = argv[3][i];
		//printf("val = %d\n", val);
		if(val <= '9'){
			int val_int = val - '0';
			dec_val += (val_int * pow(basefrom, digits - 1 -i));
			if (val_int > basefrom){
				printf("Wrong digit in number.\n");
				exit(1);
			}
		}
		else if(val > '9'){
			//printf("A=%d\n", 'A');
			int val_int = val - 'A' + 10;
			//printf("newval=%d\n",val);
			dec_val += (val_int * pow(basefrom, digits - 1 - i));
			if (val_int > basefrom){
				printf("Wrong digit in number.\n");
				exit(1);
			}
		}
	}
	//printf("Number read in base %d: %s\n", basefrom, argv[3]);
	//printf("dec_val: %d, digits: %d\n", dec_val, digits);
/*
	//print wrong digit
	for (int i = 0; i < digits; i++){
		int val = argv[3][i] - 'A' + 10;
		if (val > basefrom){
			printf("Wrong digit in number.\n");
			exit(1);
		}
	}
*/
	//converting decimla value to base10 number
	int dec_temp10 = dec_val;
	int * base10 = (int*)malloc(sizeof(int)*100);
	int quotient10 = dec_temp10;
	int c10 = 0;
	while ((quotient10)>0){
		base10[c10]= quotient10 % 10;
		quotient10 /= 10;
		c10++;
	}
	
	printf("Converted to base 10: ");
	for(int e = c10; e > 0; e--){ 
		printf("%d", base10[e-1]);
	}

	printf("\n");


	//converting decimal value to baseto number
	int dec_temp = dec_val;
	char * baseto_num = (char*)malloc(sizeof(char)*100);
	int quotient = dec_temp;
	int s = 0;
	while((quotient)>0){
		int remainder = quotient % baseto;
		if (remainder > 9){
			remainder += 'A' - 10;
			baseto_num[s] = remainder;
		}
		else{
			baseto_num[s]= remainder;
		}
		s++;
		quotient /= baseto;
	}
	baseto_num[s]='\0';

	printf("Converted to base %d: ", baseto);
	for(int e = s; e > 0; e--){
		if (baseto_num[e-1] > 9){
			printf("%c",(baseto_num[e-1]));
		}
		else{
			printf("%d",(baseto_num[e-1]));
		}
	}
	printf("\n");
}
