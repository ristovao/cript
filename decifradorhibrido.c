#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCKSIZE 8;
#define MAXSIZE 100;


int local(char *alfabeto,char letra){
    int i = 0;
    
    for(i=0;i<62;i++){
            if(alfabeto[i]==letra)
            return i;                        
    }
    
}

char * dencriptarchave(char text[8],int chave[8]){
	int i;
	
	char plain[8];

for(i=0;i<8;i++){
         plain[i]=text[i];
       }

   int pos =0;
		text[chave[0]] = plain[pos];	
		text[chave[1]] = plain[pos+1];
		text[chave[2]] = plain[pos+2];
		text[chave[3]] = plain[pos+3];
		text[chave[4]] = plain[pos+4];
		text[chave[5]] = plain[pos+5];
		text[chave[6]] = plain[pos+6];
		text[chave[7]] = plain[pos+7];
  return text;
}

int main (int argc, char *argv[]){


    if(argc<4){
           printf("quantidades de arquivos insulficiente\n");
           system("pause");
           return -1;
    }
               
    FILE * cripto;
    FILE * textoclaro;
    FILE * chave;

    cripto = fopen("temp.txt","w");
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
       
       printf("\n%s\n",dencriptarchave(letrasclaro,textochave));
       
       for(i=0;i<8;i++){
         fprintf(cripto,"%c",letrasclaro[i]);
       }
      
    }


    fclose(cripto);
    fclose(textoclaro);
    fclose(chave);
    printf("aqui\n");
    char comando[800]="";
    
    strcat(comando,"\"decifradorsubstituicao .exe\" temp.txt ");
    strcat(comando,argv[3]);
    
    printf("%s",comando);
    
    system(comando);




	system("pause");
	//no linux é outro comando
	return 0;

}
