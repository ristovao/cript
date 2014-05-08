#include <iostream>
#include <string>
#include <vector>

using namespace std;

void percorrer(string cifrado){
	vector<string> possiveisComputador;
	vector<string> possiveisSeguranca;
	string substring;
	if(cifrado.size()>=10){
        for(unsigned int i = 0; i < cifrado.length()-9; i++){
            substring = cifrado.substr(i, 10);
            //checa se a substring pode ser "computador"
            if(substring[1] == substring[8]){
                possiveisComputador.push_back(substring);
            }
        }
	}
	if(cifrado.size()>=9){
        for(unsigned int i = 0; i < cifrado.length()-8; i++){
            substring = cifrado.substr(i, 9);
            //checa se a substring pode ser "seguranca"
            if(substring[5] == substring[8]){
                possiveisSeguranca.push_back(substring);
            }
        }
	}


	for(unsigned int i = 0; i < possiveisSeguranca.size() ;i++){
            for(unsigned int j = 0; j < possiveisComputador.size() ;j++){
			if(possiveisComputador[j][4]==possiveisSeguranca[i][3]
             &&possiveisComputador[j][9]==possiveisSeguranca[i][4]
             &&possiveisComputador[j][0]==possiveisSeguranca[i][7]){
                    //aqui gerar um alfabeto possivel
                    cout<<"sim"<<endl;
                }
            }
	}

}

int main(){
	string textoCifrado;
	getline(cin, textoCifrado);
	percorrer(textoCifrado);
	return 0;
}
