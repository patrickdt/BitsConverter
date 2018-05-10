#include <stdio.h>

// It prints the bits in bitmap as 0s and 1s.
void printBits(unsigned int bitmap)
{
	// Add your code here
/*
	//unsigned int size = sizeof(unsigned int);
	unsigned int mask = 0x80000000;//1 << 31;
	//unsigned int mask = 1 << 31;
	//printf("mask = %u\n", mask);
	for(int i = 0; i < 32; i++){
		if (bitmap&mask){
			printf("%u", 1);
		}
		else{
			printf("%u", 0);
		}
		//printf("%u", bitmap&mask ? 1 : 0);
		//indices[i]=(bitmap&mask ? 1 : 0);
		bitmap = bitmap << 1;
	}
	
	printf("\n");
	
//	printf("10987654321098765432109876543210\n");

	int i = 31;
        while(i >= 0){
  	      printf("%d", i % 10);
              i--;
        }
        printf("\n");*/
	unsigned int mask = 1<<31; // 1 << 31;
	for (int i = 0; i < 32; i ++){
		if (bitmap & mask){
			printf("%u", 1);
		}
		else{
			printf("%u", 0);
		}
		bitmap = bitmap << 1;
	}
	printf("\n");
	int i = 31;
	while (i>=0){
		printf("%d", i%10);
		i--;
	}
	printf("\n");
}


// Sets the ith bit in *bitmap with the value in bitValue (0 or 1)
void setBitAt( unsigned int *bitmap, int i, int bitValue ) {
	// Add your code here
	unsigned int mask = 1 << i;
	if (bitValue == 1){
		*bitmap = *bitmap|mask;
	}
	else { //bitValue == 0
		*bitmap = ~*bitmap;
		*bitmap = *bitmap|mask;
		*bitmap = ~*bitmap;
	}
}

// It returns the bit value (0 or 1) at bit i
int getBitAt( unsigned int bitmap, unsigned int i) {
	// Add your code here
	bitmap = bitmap >> i;
	unsigned mask = 1;
	if (bitmap&mask == 1){
		return 1;
	}
	else return 0;
}

// It returns the number of bits with a value "bitValue".
// if bitValue is 0, it returns the number of 0s. If bitValue is 1, it returns the number of 1s.
int countBits( unsigned int bitmap, unsigned int bitValue) {
	// Add your code here
	int num_1 = 0;
	int num_0 = 0;
	if (bitValue == 1){
		for (int i = 0; i < 32; i++){
			if(bitmap&bitValue){
				num_1++;
			}
			bitmap = bitmap >> 1;
		}
		return num_1;
	}
	else{ //bitValue == 0;
		bitmap = ~bitmap;
		for (int i = 0; i < 32; i++){
			unsigned mask = 1;
			if(bitmap&mask){
				num_0++;
			}
			bitmap = bitmap >> 1;
		}
		return num_0;
	}			
}

// It returns the number of largest consecutive 1s in "bitmap".
// Set "*position" to the beginning bit index of the sequence.
int maxContinuousOnes(unsigned int bitmap, int * position) {
	// Add your code here
	int k;
	int count;
	int max;
	int start;
	int i = 31;
	while (i>=0){
		k = bitmap >> i;
		if ((k&1)&&count==0)
		{
			count++;
		}
		else if (!(k&1)){
			if(count > max){
				max = count;
				start = i;
				count = 0;
			}
			else count = 0;
		}
		else if ((k&1)&&count!=0){
			count++;
		}
		i--;
	}
	*position = start +1;
	return max;
}









//	int num_1 = 0;
	/*int c = 0;
	int max_arr[32][32];
        unsigned int mask = 1;
	int i, j, k;
      	for (i = 0, j = 0, k = 0; i < 32; i++){
               	if(bitmap&mask){
                       	num_1++;	
		}
		else{
			if (num_1 > 0){
				max_arr[j][0]= num_1; //placing one of the max values to an array index
				max_arr[j][1]= i - num_1; //placing the position where it's stored
				j = j + 1;
			}
			num_1 = 0; // reset the value of num;
		}		
       	        bitmap = bitmap >> 1;
       	}
*/
/*	
	int max = 0;
	int num_1 =0;
	int i;
	int j;
	unsigned int mask = 1;
	for(i=0, j=0, num_1=0;(i<32)&&(mask=(1<<i));i++){
		if(mask&bitmap){
			num_1++;
		}
		else{
			if(num_1 > 0){
				max_arr[j][0]=num_1;
				max_arr[j++][1]=i-num_1;
			}
			num_1=0;
		}
	}	

//	int pos = 0;	
	for(int i=0;i<j;i++){
		if(max_arr[i][0]>max_arr[max][0])
			max=i;
		//if(max_arr[i][0]>max){
			//max=max_arr[i][0];
			//pos=i;
	}
	*position=max_arr[max][1];
	
	return max_arr[max][0];
*/
/*
	int pos;
	int l = 0;
	int max = max_arr[l][0];
	for (int m = 0; m < j; m++){
		if (max_arr[m][0] > max){
			max = max_arr[m][0];
			pos = m;
		}
	}
	return max_arr[pos][0];
	*position = max_arr[pos][1];
*/


