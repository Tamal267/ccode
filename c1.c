#include<stdio.h>
#include <stdbool.h>
#include <math.h>
int primeNum[50847535];
bool notPrime[1000000000];
int k = 0;
void seive(int n){
	notPrime[1] = true;
	primeNum[k++] = 2;
	for(int i=4;i<=n;i+=2) notPrime[i] = true;
	for(int i=3;i<=n;i+=2){
		if(!notPrime[i]){
			primeNum[k++] = i;
			if(i < sqrt(n) + 2) for(int j = i*i; j<=n; j+= 2*i) notPrime[j] = true;
		}
	}
}
int main(){
	int i = 1e9;
	seive(i);
	FILE *fp;
	fp = fopen("input.txt", "w");
	for(int i=0;i<(int)50847534;i++){
		fprintf(fp, "%d: %d\n", i, primeNum[i]);
	}
	printf("hello\n");
}
