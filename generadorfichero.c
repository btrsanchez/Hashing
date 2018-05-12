#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;




int main() {
	ofstream salida;
	ofstream numeros;
	int n;
	int m;
	vector<int> v;
	cout << "Define el tamaño del diccionario " ; cin >> n;
	cout << "Escribe el contenido del diccionario " ;
	salida.open("diccionari.txt");
	for(int i=0; i < n; i++){
		cin >> m;
		salida << m << endl;
		v.push_back(m);
	}
	salida.close();
	numeros.open("entrada.txt");
	cout << "Definir tamaño del fichero de números como mínimo " << 2*n << " "; cin >> n;
    int aux;
	cout << "Si desea escribir el contenido de la entrada escriba 0 sino cualquier otro numero: " << endl ; 
    cin >> aux;
    if(aux==0) {
        cout << "Escriba el contenido del fichero de números " << endl;
        for(int i=0; i < n; i++){
		cin >> m;
		numeros << m << endl;
        }
    }
    else {
        cout << "Se generara su fichero con contenido aleatorio " << endl ;
    }
	if(aux!=0)
    {
        int random;
        for(int i=0; i < n; i++){
        random=rand();
		numeros << random << endl;
        }
	}
	numeros.close();
    cout << "Diccionario y entrada creados con éxito!! " << endl;
}
