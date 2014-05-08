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

int main(){
	string textoCifrado;
	getline(cin, textoCifrado);
	percorrer(textoCifrado);
	return 0;
}
