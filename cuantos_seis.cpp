#include <iostream>
#include <algorithm>
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


using namespace std;

/*int length(string s){
	int i=0;
	while(s[i]!='\0'){
		return i-1;
	}
}*/

char int_to_char(int i){
	return '0'+ i;
}

int digit_count(int nro){ //cuenta cuantas cifras tiene el nro
	if(nro==0){
		return 1;
	}
	int cant_cifras = 0;
	while(nro>=1){	//mientras haya nro que le saque la ultima cifra y lo agg al contador
		nro = nro/10;
		cant_cifras++;
	}
	return cant_cifras;
}

int get_digit(int nro,int i){ // esta funcion me retorna el iesimo digito del nro contando desde la derecha
	int digito = nro%(int)pow(10,i+1);
	return digito/(pow(10,i));
}

string int_to_string(int num){
	string cadena_de_numeros = ""; //empiezo con la cadena vacia
	int cant_cifras = digit_count(num); //veo cuantas cifras tiene
	for(int i=0;i<cant_cifras;i++){ //mientras tenga cifras que itere
		cadena_de_numeros = int_to_char(get_digit(num,i)) + cadena_de_numeros;  //un string es una suma de caracteres individuales
	}																		  // obtengo digito a digito y lo voy concatenando con lo que ya tenia en la cadena

	return cadena_de_numeros;
}


int char_count(string s, char c){ //cuento cuantas veces aparece c en el string s
	int cantidad_de_veces = std :: count(s.begin(), s.end(),c); 

	return cantidad_de_veces;
}

int main(){
	
	string cadena;
	char caracter = '6';
	int limite = 1200;

	for(int j=0;j<=limite;j++){
		cadena = int_to_string(j) + cadena;
	}
	
	int estas = char_count(cadena,caracter);

	cout << "El nro " << caracter << " aparece: " << estas << " veces. " << endl;

	return 0;
}