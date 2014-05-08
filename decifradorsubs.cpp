#include <iostream>
#include <string>
#include <vector>

using namespace std;

string decifrarComUnder(string cifrado, string chave){
	string alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int pos;
	for(unsigned int i = 0; i < cifrado.length(); i++){
		pos = chave.find(cifrado[i]);

		if(pos != string::npos){
			cifrado[i] = alfabeto[pos];
		}else
		if(cifrado[i]!=' '){
            cifrado[i] = '_';
		}
	}
	return cifrado;
}

string decifrar(string cifrado, string chave){
	string alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int pos;
	for(unsigned int i = 0; i < cifrado.length(); i++){
		pos = chave.find(cifrado[i]);

		if(pos != string::npos){
			cifrado[i] = alfabeto[pos];
		}
	}
	return cifrado;
}

void percorrer(string cifrado){
	vector<string> possiveisComputador;
	vector<string> possiveisSeguranca;
	vector<string> possiveisAlfabetos;
	string substring;

    string alfabeto = "______________________________________________________________";
    string normal = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

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


	string plainText;
	for(unsigned int i = 0; i < possiveisSeguranca.size() ;i++){
            for(unsigned int j = 0; j < possiveisComputador.size() ;j++){
			if(possiveisComputador[j][4]==possiveisSeguranca[i][3]
             &&possiveisComputador[j][9]==possiveisSeguranca[i][4]
             &&possiveisComputador[j][0]==possiveisSeguranca[i][7]){
				alfabeto[0] = possiveisSeguranca[i][5];
				alfabeto[2] = possiveisSeguranca[i][7];
				alfabeto[3] = possiveisComputador[j][7];
				alfabeto[4] = possiveisSeguranca[i][1];
				alfabeto[6] = possiveisSeguranca[i][2];
				alfabeto[12] = possiveisComputador[j][2];
				alfabeto[13] = possiveisSeguranca[i][6];
				alfabeto[14] = possiveisComputador[j][1];
				alfabeto[15] = possiveisComputador[j][3];
				alfabeto[17] = possiveisComputador[j][9];
				alfabeto[18] = possiveisSeguranca[i][0];
				alfabeto[19] = possiveisComputador[j][5];
				alfabeto[20] = possiveisComputador[j][4];
				plainText = decifrar(cifrado, alfabeto);
				cout<<"possivel alfabeto"<<endl;
				cout<<normal<<endl;
				cout<<alfabeto<<endl;
				cout << "Texto semi-decifrado: \n" << plainText << endl;
                plainText = decifrarComUnder(cifrado, alfabeto);
                cout << plainText << endl;
                }
                alfabeto = "______________________________________________________________";
            }
	}

}

int main(){
	string textoCifrado;
	getline(cin, textoCifrado);
	percorrer(textoCifrado);
	return 0;
}
