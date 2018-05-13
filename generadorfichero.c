#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;


void usage(int f,int tamDic) {
    if(f <= 0 or f < tamDic){
    cerr << "Cota no válida " << endl;
    exit(1);
    }
}
void usage1(int d,int tamDic){
        if(d/2 < tamDic ){
            cerr << "Tamaño no válido para el fichero " << endl;
            exit(1);
            }
        }
void usage2(double p){
        if(p < 0.0 or p > 1.0 ){
        cerr << "Proporción no válida para el fichero " << endl;
        exit(1);
        }
}

int main() {
	ofstream salida;
	ofstream numeros;
	int tamDic;
	int m;
        int aux1;
        int random;
        int n;
	vector<int> v;
        double proporcion;
        int cota;
	cout << "Define el tamaño del diccionario " ; cin >> tamDic;
	cout << "Escribe 0 si quieres definir el contenido del diccionario u otro número si quieres que se genere aleatoriamente " ; cin >> aux1;
	salida.open("Dic.txt");
        if(aux1==0){
            cout << "Escriba los números que habrá en el diccionario " << endl;
	for(int i=0; i < tamDic; i++){
		cin >> m;
		salida << m << endl;
		v.push_back(m);
	}
        }
        else {
            cout << "Diccionario aleatorio: Escribe la cota positiva máxima para los números del diccionario" << endl; cin >> cota; 
            usage(cota,tamDic);
            for(int i=0; i < tamDic; i++){
            random=rand()%cota+1;
            salida << random << endl;
            v.push_back(random);
        }
        }
        
	salida.close();
	numeros.open("Txt.txt");
	cout << "Define el tamaño del fichero de texto (mínimo " << 2*tamDic << ")\n"; cin >> n;
        usage1(n,tamDic);
        int aux;
	cout << "Si desea escribir el contenido de la entrada escriba 0 sino cualquier otro numero: " << endl ; cin >> aux;
        if(aux==0) {
        cout << "Escriba el contenido del fichero de números " << endl;
        for(int i=0; i < n; i++){
		cin >> m;
		numeros << m << endl;
            }
        }
        else {
            cout << "Escriba proporción, un real del 0 al 1" << endl; cin >> proporcion;
            usage2(proporcion);
            //int tamano_diccionario = factor_texto_diccionario*tamDic;
            int repetidos = tamDic*proporcion;
            for (int i = 0; i < repetidos; ++i) {
            int indice_archivo = rand()%tamDic;
            numeros << v[indice_archivo] << endl;
        }
        cout << "Se generara su fichero con contenido aleatorio " << endl ;
        for(int i=repetidos; i < n; i++){
                random=rand()%n+1;
		numeros << random << endl;
        
            }
        }
	numeros.close();
    cout << "Diccionario y entrada creados con éxito!! " << endl;
}