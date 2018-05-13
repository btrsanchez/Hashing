#include "linear2.h"

void busca(vector<int> dicc,vector<int> text, int size){
    int x,i,a,c=0,z=0,y=0,z2=0,y2=0;;
    vector<int> v(size,-1);
    bool t;
    for(i=0;i<dicc.size();i++){
        t=true;
        x=dicc[i];
        a= x % (size);
        while(t){
            if(v[a]==-1 or v[a]==x){
                z2++;
                v[a]=x;
                t=false;
            }
            else{
                z++;
                a++;
                if(v.size()==a) v.push_back(x);
            }
        }
    }
    //for(i=0;i<v.size();i++)cout<<v[i]<<" ";
    for(i=0;i<text.size();i++){
        t=true;
        x=text[i];
        a= x % (size);
        while(t){
            if(a==v.size() or v[a]==-1){
                y2++;
                t=false;
            }
            else if (v[a]==x){
                y2++;
                t=false;
                c++;
            }
            else {
                a++;
                y++;
            }
        }
    }
    cout<<c<<" de las "<<text.size()<<" palabrass apararecen al diccionario."<<endl;
    cout<<z+z2<<" accesos durante la creación("<<z<<" fracasos,"<<z2<<" éxitos)"<< endl;
    cout<<y+y2<<" accesos durante la búsqueda("<<y<<" fracasos,"<<y2<<" éxitos)"<< endl;
}
