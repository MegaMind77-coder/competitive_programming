#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long long int bintodec(char *bin,int i,int j){ //converts a string storing a binary to decimal between the index's specified(will be reused in binary to octal)(eg bin(10011,1,3) returns 1)
	long long int sum = 0;//stores the final decimal value
	int p=j;//stores the power,used to calculate the decimal value. 
	for(int x=i;x<=j;x++){
		sum += (long long int)pow(2,p-i)*(bin[x]-'0');
		p--;
	}
	return sum;//returns the final decimal value
}

long long int octal(char *bin,int n){//returns octal representaion of binary number
	int zeros = 3 - n%3;//number of extra zeroes added at the beginning.
	int i = n%3-1;//stores the final index from the binary string combined with the zeroes
	int k =0;
	long long int sum = 0;//stores the final octal value
	int j =n/3;//number of parts of 3 the binary string can be divided into -1
	char extra[3];//extra string in which the extra zeroes are added
	int y=0;
	for(y;y<zeros;y++){
		extra[y]='0';
	}//adding zeros to extra string 
	int z=y;
	for(z,k;z<3,k<=i;z++)
	{
		extra[z]=bin[k++];
	}//final extra string is completed
//	printf("%s",extra);	
	for(int c=1;c<(int)n/2;c++){//divides the binary into three digits substrings and converts them into decimal and adds them after multiplying the powers of 10 
       		 if(j>0){
				sum += (int)pow(10,j-1)*bintodec(bin,i+1,i+3);
			}
			j--;
			i+=3;
	}
	sum += (long long int)pow(10,(int)n/3)*(bintodec(extra,0,2));//converts the extra part into decimal and adds them after multiplying the power
	return sum;//returns the final octal value
}

char *hexadecimal(char *bin,int n){//coverts the binary string inti a hexadecimal value and returns it
	long long int sum = 0;
	sum = bintodec(bin,0,n-1);//converts binary to decimal
	long long int i=0;
	while(sum>=pow(16,i)){//loop finds max power of 16 that decimal can be divided by 
		i++;
	}
	i-=1;//i represents the max value of power
	char *hexa =(char *)malloc(50*sizeof(char));//stores the hexa value
	int j=0;
	while(sum>=0 && j<=i){
		int x=(int)sum/pow(16,i-j);
		if(x<10)
		{
			hexa[j]=x+'0';
		}
		else{
			hexa[j]=(char)(x+55);//converts values greater than 10 to ascii
		}
		sum = sum - x*pow(16,i-j);
		j++;
	}
        return hexa;//returns final hexa string
}

int main()
{
	int n;
	char *bin;
	scanf("%d %s",&n,bin);
	printf("%lld," ,bintodec(bin,0,n-1));
	printf("%lld,",octal(bin,n));
	printf("%s",hexadecimal(bin,n));
	return 0;
}
