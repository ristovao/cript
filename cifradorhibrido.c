#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int local(char *alfabeto,char letra){
    int i = 0;
    
    for(i=0;i<62;i++){
            if(alfabeto[i]==letra)
            return i;                        
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
    
    if(argc<4){
               printf("quantidades de arquivos insulficiente\n");
               system("pause");
               return -1;

               }
               
    FILE * cripto;
    FILE * textoclaro;
    FILE * chave;
    
    
    char alfabeto[62] ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char textochave[62];
    char letraclaro;
    char letrachave;
    
    int i =0;
    
    cripto = fopen("temp.txt","w");
    textoclaro = fopen( argv[1] , "r");
    chave = fopen(  argv[2] , "r");

    letrachave = getc(chave);

    while(letrachave != EOF){
        printf("%c",letrachave);
        textochave[i]=letrachave;
        letrachave = getc(chave);
        i++;
    }
    
    letraclaro = getc(textoclaro);
    
    while(letraclaro != EOF){
        printf("%c",letraclaro); 
        if(letraclaro!=32)
                fprintf(cripto,"%c",textochave[local(alfabeto,letraclaro)]);
        else
                fprintf(cripto," ");
        
        letraclaro = getc(textoclaro);
    }
	
	//PARTE DE TRANSPOSICAO


    free(&letraclaro);
    free(&letrachave);

    fclose(cripto);
    fclose(textoclaro);
    fclose(chave);
    
    FILE * textoclarotransp;    
    FILE * chavetransp;
	FILE * saida;


    saida = fopen("cripto.txt","w");
    
    textoclarotransp = fopen( "temp.txt" , "r");
    chavetransp = fopen(  argv[3] , "r");

    i = 0;

    int textochaveTransp[8];
    char letrasClaroTransp[8];
    char letraTransp='1';
    letraTransp = getc(chavetransp);
    printf("\n\n\n");
    printf("%p %c ",&letraTransp,letraTransp);
    printf("\n\n\n");
    while(letraTransp != EOF){
        printf("%c",letraTransp);
        textochaveTransp[i]=atoi(&letraTransp);
        printf(" %d \n",textochaveTransp[i]);
        letraTransp = getc(chavetransp);
        i++;
    }
    system("pause");
    printf("\n\n\n");

    letraTransp = getc(textoclarotransp);
    
    
     printf("%c",letraTransp);
     printf("\n\n\n");
    while(letraTransp != EOF){
        
       for(i=0;i<8;i++){
            letrasClaroTransp[i]=letraTransp;
            letraTransp = getc(textoclarotransp);
       }
       printf("\n%s",letrasClaroTransp);
       for(i=0;i<8;i++)
       printf("\n%d",textochaveTransp[i]);
        
       printf("\n%s\n",encriptarchave(letrasClaroTransp,textochaveTransp));
       
       for(i=0;i<8;i++){
         fprintf(saida,"%c",letrasClaroTransp[i]);
       }
      
    }
    
    
	fclose(saida);
    fclose(textoclaro);
    fclose(chave);
    //no linux é outro comando
    system("pause");
    return 0;

}
