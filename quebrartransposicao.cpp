#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

#define BLOCKSIZE 8;
#define MAXSIZE 100;



string dencriptarchave(string text,int i,int j,int k,int l,int m,int n,int o,int p){


	string plain=text;

        int pos =0;
		text[i] = plain[pos];
		text[j] = plain[pos+1];
		text[k] = plain[pos+2];
		text[l] = plain[pos+3];
		text[m] = plain[pos+4];
		text[n] = plain[pos+5];
		text[o] = plain[pos+6];
		text[p] = plain[pos+7];

  return text;
}


void decifra(string textocifrado,int i,int j,int k,int l,int m,int n,int o,int p){

string substring;
string decifrado="";

    int temp;



    for(int tamanho =0; tamanho < textocifrado.length();tamanho=tamanho+8){
        substring=textocifrado.substr(tamanho,8);
        decifrado+=(dencriptarchave(substring,i,j,k,l,m,n,o,p));

    }
    //cout<<decifrado<<endl;

    if((decifrado.find("computador")!=string::npos)&&(decifrado.find("seguranca")!=string::npos)){
        cout<<"possivel texto decifrado"<<endl;
        cout<<decifrado<<endl;
        cout<<"chave"<<endl;
        cout<<i<<j<<k<<l<<m<<n<<o<<p<<endl;
		system("pause");
    }
}

void percorrer(string cifrado){

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


    decifra(cifrado,i,j,k,l,m,n,o,p);



    }


}


int main(){
	string textoCifrado;
	getline(cin, textoCifrado);
    percorrer(textoCifrado);
	return 0;
}
