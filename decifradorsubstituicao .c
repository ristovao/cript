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

int main (int argc, char *argv[]){
    
    if(argc<3){
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
    
    cripto = fopen("decripto.txt","w");
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
                fprintf(cripto,"%c",alfabeto[local(textochave,letraclaro)]);
        else
                fprintf(cripto," ");
        
        letraclaro = getc(textoclaro);
    }

    
    fclose(cripto);
    fclose(textoclaro);
    fclose(chave);
    //no linux é outro comando
    system("pause");
    return 0;

}
