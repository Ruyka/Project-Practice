#include<stdio.h>
char* getBytes(double& x, int& nb){
	nb = sizeof(double);
	return (char*)(&x);
}
short* getWords(double& x, int& nw){
	nw = sizeof(double) / sizeof(short);
	return (short*)(&x);
}
void listBytes(char bytes[], int nb){
	for (int i = 0; i < nb; i++)
		printf("0x%X", (unsigned char)bytes[i]);
	printf("\n");
}
void listWords(short words[], int nw){
	for (int i = 0; i < nw; i++)
		printf("0x%X", (unsigned short)words[i]);
	printf("\n");
}
void main(){
	double a = 0.01; char*storedBytes; int nb; short *storedWords; int nw;
	printf("----------------------------------\n");
	storedBytes = getBytes(a, nb); listBytes(storedBytes, nb);
	printf("----------------------------------\n");
	storedWords = getWords(a, nw); listWords(storedWords, nw);
}