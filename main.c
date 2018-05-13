#include <fstream>
#include <iostream>
#include <cmath>
#include "lib/Bloom/Bloom.h"
#include "lib/HashOpen/linear2.h"
#include "lib/HashSeparate/hashL2.h"
//#include "lib/BusquedaBinaria/busqueda_binaria.h"

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
	if (opcio=="Bloom") {
		unsigned int n, m, k;
		BV bits;
		n = txt.size();
  		const double ln2=log(2)*log(2);
  		m=ceil(abs(n*log(1.0/n)/ln2));
  		k = (m/n)*log(2);
  		bits=BV(m, 0);
  		BloomFilter(bits,dic,txt,n,m,k);
	}
	if (opcio=="HashOpen"){
        cout<<"Choose Hash Table size, minimum is "<<dic.size()<<" (dic.txt size)"<<endl;
        int Hs;
        cin>>Hs;
		if (Hs>= dic.size()) busca(dic,txt,Hs);
	}
	if (opcio=="HashSeparate"){
        cout<<"Choose Hash Table size, minimum is "<<dic.size()<<" (dic.txt size)"<<endl;
        int Hs;
        cin>>Hs;
		if (Hs>= dic.size()) buscaH(dic,txt,Hs);
	}
	if (opcio=="Binary"){
		//buscaH(dic,txt);
	}
}

int main(){
	ReadDic();
	ReadTxt();
	string opcio;
	cout << "Choose algorithm: Bloom/HashOpen/HashSeparate/Binary\n";
	cin >> opcio;
	Algorisme(opcio);
}
