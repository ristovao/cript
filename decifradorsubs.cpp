#include <iostream>
#include <string>
#include <vector>

using namespace std;

void percorrer(string cifrado){
	vector<string> possiveisComputador;
	vector<string> possiveisSeguranca;
	string substring;
	for(unsigned int i = 0; i < cifrado.length()-10; i++){
		substring = cifrado.substr(i, 10);
		//checa se a substring pode ser "computador"
		if(substring[1] == substring[8]){
			possiveisComputador.push_back(substring);
		}
	}
	
	for(unsigned int i = 0; i < cifrado.length()-9; i++){
		substring = cifrado.substr(i, 9);
		//checa se a substring pode ser "seguranca"
		if(substring[5] == substring[8]){
			possiveisSeguranca.push_back(substring);
		}
	}
}

int main(){
	string textoCifrado;
	getline(cin, textoCifrado);
	percorrer(textoCifrado);
	return 0;
}