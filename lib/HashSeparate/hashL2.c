#include"hashL2.h"

void buscaH(vector<int> dicc,vector<int> text,int size){
    int x,i,a,c=0,z=0,y=0,z2=0,y2=0;
    list<int>* table;
    table = new list<int>[size];
    bool t;
    for(i=0;i<dicc.size();i++){
        z++;
        t=true;
        x=dicc[i];
        a= x % (size);
        table[a].push_back(x);
    }
    for(i=0;i<text.size();i++){
        t=true;
        x=text[i];
        a= x % (size);
        list<int>::iterator it=table[a].begin();
        while(t and it!=table[a].end()){
            if (*it==x){
                y2++;
                t=false;
                c++;
            }
            else {
                it++;
                y++;
            }
        }
        if (it==table[a].end())y++;
    }
    cout<<c<<" de les "<<text.size()<<" paraules apareixen al diccionari."<<endl;
    cout<<z<<" accessos durant la creació"<<endl;
    cout<<y+y2<<" accessos durant la búsqueda ("<<y<<" fracasos,"<<y2<<" éxits)"<< endl;
}
