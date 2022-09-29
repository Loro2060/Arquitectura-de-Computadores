#include <iostream>
#include <bitset>

using namespace std;

string bit;
int sig;
string cadena;

int exponente(string cad, int n){
	for(int i = 0; i < cad.length(); i++){
		if(cad[i] == '1'){
            return n;
        } 

		n = n - 1;
	}
    
	return 0;
}

template <typename x>

string abinario(x n, int donde = 0){
    int exp;

	if (sizeof(n) == 8 || sizeof(n) == 4){
		//Negativo
		if (n < 0){
			bit = " 1 ";
			n = n * 1;
		}
        //Positivo
		else{
            bit = " 0 ";
        } 

		if (n < 256 && donde == 0){
			
			bitset<8> cadena32(n);
            sig = 23;
			cadena = cadena32.to_string();

			exp = exponente(cadena, 7);
			cadena = cadena.substr(8-exp);
			
			if (exp != 0){
                exp = exp + 127;
            } 

			cadena32 = exp;

			bit = bit + cadena32.to_string();
            //cout << "bit32: " << bit << endl;
		}

		else if ((n > 255 && n < 2048) || donde == 1){
            // 32 52
			bitset<11> cadena64(n);
            sig = 52;
			cadena = cadena64.to_string();
			

			exp = exponente(cadena, 10);
			cadena = cadena.substr(11 - exp);
			
			if (exp != 0){
                exp = exp + 1023;
            } 

			cadena64 = exp;

			bit = bit + cadena64.to_string();
		}
		else if( (n > 2047 && n < 32768) || donde == 2){
			
			bitset<15> cadena128(n);
            sig = 112;
			cadena = cadena128.to_string();
			

			exp = exponente(cadena, 14);
			cadena = cadena.substr(15 - exp);
			
			if (exp != 0){
                exp = exp + 16383;
            } 

			cadena128 = exp;
			bit = bit + cadena128.to_string();
		}
        
		int bits = n;

		bit = bit + ".";
        //Decimales
		bit = bit + cadena;
        
		sig = sig - cadena.length();
		
        //cout << bit << endl;
		return bit;
	}
	
	return "No es una cadena convertible ";
}

int main(){
	float a = 3.15;
	string b1 = abinario(a);
	cout << a << " En binario: " << b1 <<endl;
	
    double b = 3.15; 
	string b2 = abinario(b);
	cout << b << " En binario: " << b2 <<endl;
	
    int c = 22; 
	string b3 = abinario(c);
	cout << c << " En binario: "<< b3 << endl;

    double d = 1231; 
	string b4 = abinario(d);
	cout << d << " En binario: " << b4 <<endl;

  return 0;
	
}