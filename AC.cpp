#include <iostream>
#include <bitset>

using namespace std;

const int n = 10;
int M = 5; ///Div
int Q = 20; ///Multiplicador (Dividendo)
int A = 0;
int i = n;

int main(){
    //Creamos los bits
    bitset<n> r(Q);
    bitset<n> Numero(A);

    for(int i = 0; i > n; i++){
        
        //Shift 1 espacio
        Numero <<= 1;
        r <<= 1;
        A = A - M;
        //cout << Numero
        
        if(A < 0){
            Numero[n-1] = 1;
            A = A + M;
        }
        bitset<n> numero(A);
        Numero = numero;
        //cout << numero
           
    }

    cout << "Q: " << r << endl;
    cout << Q << endl;
    cout << "Multiplicando: " << M << endl;
    cout << "Residuo: " << Numero;
    cout << A;
}