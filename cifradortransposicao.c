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

char * encriptarchave(char text[8],int chave[8]){
	int i;
	
	char plain[8];

for(i=0;i<8;i++){
         plain[i]=text[i];
       }

   int pos =0;
		text[pos] = plain[chave[0]];	
		text[pos+1] = plain[chave[1]];
		text[pos+2] = plain[chave[2]];
		text[pos+3] = plain[chave[3]];
		text[pos+4] = plain[chave[4]];
		text[pos+5] = plain[chave[5]];
		text[pos+6] = plain[chave[6]];
		text[pos+7] = plain[chave[7]];
  return text;
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

    int i =0;

    int textochave[8];
    char letrasclaro[8];
    char letra='1';

    
    letra = getc(chave);
    while(letra != EOF){
        textochave[i]=atoi(&letra);
        letra = getc(chave);
        i++;
    }

    letra = getc(textoclaro);
    
    while(letra != EOF){
        
       for(i=0;i<8;i++){
            letrasclaro[i]=letra;
            letra = getc(textoclaro);
       }
       printf("\n%s",letrasclaro);
       
       printf("\n%s\n",encriptarchave(letrasclaro,textochave));
       
       for(i=0;i<8;i++){
         fprintf(cripto,"%c",letrasclaro[i]);
       }
      
    }


    fclose(cripto);
    fclose(textoclaro);
    fclose(chave);


	system("pause");
	//no linux é outro comando
	return 0;

}
