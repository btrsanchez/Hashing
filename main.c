#include <fstream>
#include <iostream>
#include <cmath>
#include "lib/Bloom/Bloom.h"
#include "lib/HashOpen/linear2.h"
#include "lib/HashSeparate/hashL2.h"
#include "lib/BusquedaBinaria/busqueda_binaria.h"

IV dic;     
IV txt;

void ReadDic() {
  ifstream diccionari;
  diccionari.open("Dic.txt");
  int x;
    if (diccionari.is_open()) 
      while (diccionari>>x) dic.push_back(x);
  diccionari.close();
}

void ReadTxt() {
  ifstream text;
  text.open("Txt.txt");
  int x;
    if (text.is_open()) 
      while (text>>x) txt.push_back(x);
  text.close();
}

void Algorisme(string opcio) {
  //time_t timer;
  double talg;
  //timer = clock();
	if (opcio=="Bloom") {
		unsigned int n, m, k;
		BV bits;
		n = txt.size();
		const double ln2=log(2.0)*log(2.0);
		m=ceil(abs(n*log(1.0/n)/ln2));
		k = (m/n)*log(2.0);
		bits=BV(m, 0);
		BloomFilter(bits,dic,txt,n,m,k);
	}
	if (opcio=="HashOpen"){
    cout<<"Elige tamaño de la tabla Hash, el mínimo es "<<dic.size()<<" (tamaño dic.txt)"<<endl;
    int Hs;
    cin>>Hs;
		if (Hs>= dic.size()) busca(dic,txt,Hs);
	}
	if (opcio=="HashSeparate"){
    cout<<"Elige tamaño de la tabla Hash, el mínimo es "<<dic.size()<<" (tamaño dic.txt)"<<endl;
    int Hs;
    cin>>Hs;
		if (Hs>= dic.size()) buscaH(dic,txt,Hs);
	}
	if (opcio=="Binary"){
		Binaria(dic,txt);
	}
  //talg = double(clock() - timer) / CLOCKS_PER_SEC;
  //cout << "Algorithm execution time: " << talg << " seconds\n";
}

int main(){
	ReadDic();
	ReadTxt();
	string opcio;
	cout << "Elige algoritmo: Bloom/HashOpen/HashSeparate/Binary/All\n";
	cin >> opcio;
  if (opcio=="All") {
    cout << "Bloom\n";
    Algorisme("Bloom");
    cout << "\nHashOpen\n";
    Algorisme("HashOpen");
    cout << "\nHashSeparate\n";
    Algorisme("HashSeparate");
    cout << "\nBinary";
    Algorisme("Binary");
  }
	else Algorisme(opcio);
}
