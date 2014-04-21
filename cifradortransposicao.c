#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCKSIZE 8;
#define MAXSIZE 100;

void encriptar(char text[]){
	char plain[100];
	strcpy(plain, text);
	int pos;
	
	for(pos = 0; pos < 100; pos += 8){
		text[pos] = plain[pos];	
		text[pos+1] = plain[pos+2];
		text[pos+2] = plain[pos+4];
		text[pos+3] = plain[pos+6];
		text[pos+4] = plain[pos+1];
		text[pos+5] = plain[pos+3];
		text[pos+6] = plain[pos+5];
		text[pos+7] = plain[pos+7];
	}
}

int main (int argc, char *argv[]){


    if(argc<3){
           printf("quantidades de arquivos insulficiente\n");
           system("pause");
           return -1;
    }
               
    FILE * cripto;
    FILE * textoclaro;
    FILE * chave;

    cripto = fopen("cripto.txt","w");
    textoclaro = fopen( argv[1] , "r");
    chave = fopen(  argv[2] , "r");

	char plainText[100];
	
	gets(plainText);
	
	printf("Plain text: %s\n", plainText);
	
	char *cipherText = plainText;
	
	encriptar(cipherText);
	
	printf("Cipher text: %s", cipherText);
	
	//no linux é outro comando
	return 0;

}
