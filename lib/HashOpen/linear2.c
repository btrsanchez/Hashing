#include "linear2.h"

void busca(vector<int> dicc,vector<int> text){
    int x,i,a,c=0,z=0,y=0,z2=0,y2=0;;
    vector<int> v(2*dicc.size(),-1);
    bool t;
    for(i=0;i<dicc.size();i++){
        t=true;
        x=dicc[i];
        a= x % (v.size());
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
        a= x % (v.size());
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
    cout<<c<<" de les "<<text.size()<<" paraules apareixen al diccionari."<<endl;
    cout<<z+z2<<" accessos durant la creació("<<z<<" fracasos,"<<z2<<" éxits)"<< endl;
    cout<<y+y2<<" accessos durant la búsqueda ("<<y<<" fracasos,"<<y2<<" éxits)"<< endl;
}