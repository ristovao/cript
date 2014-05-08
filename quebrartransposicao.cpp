#include <iostream>
#include <string>
#include <vector>

#define BLOCKSIZE 8;
#define MAXSIZE 100;



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

void percorrer(string cifrado){

	vector<string> possiveisChaves;
	string substring;
	string decifrado;
	for (int i=0;i<8;i++)
    for (int j=0;j<8;j++)
    for (int k=0;k<8;k++)
    for (int l=0;l<8;l++)
    for (int m=0;m<8;m++)
    for (int n=0;n<8;n++)
    for (int o=0;o<8;o++)
    for (int p=0;p<8;p++)
    if(i!=j
    && i!=k
    && i!=l
    && i!=m
    && i!=n
    && i!=o
    && i!=p
    && j!=k
    && j!=l
    && j!=m
    && j!=n
    && j!=o
    && j!=p
    && k!=l
    && k!=m
    && k!=n
    && k!=o
    && k!=p
    && l!=m
    && l!=n
    && l!=o
    && l!=p
    && m!=n
    && m!=o
    && m!=p
    && n!=o
    && n!=p
    && o!=p ){

    for(int tamanho =0; tamanho < cifrado.size();tamanho+=180)
    substring = cifrado.substr(i, 8);


    //printf("%d,%d,%d,%d,%d,%d,%d,%d\n", i , j , k,l,m,n,o,p);

    }


}


int main(){
	string textoCifrado;
	getline(cin, textoCifrado);
	percorrer(textoCifrado);
	return 0;
}
