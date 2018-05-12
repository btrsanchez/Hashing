#include "busqueda_binaria.h"

int NumComp=0;
int NumAssig=0;
int NumAuxAssig=0;
int CompFallades=0;
int CompBones=0;

inline static bool comp(int a, int b) { return a < b; }

    //creadora que assigna un diccionari a una busqueda_binaria
    void setDiccionari( vector<int>& Diccionario) {
        Diccionari=Diccionario;
    }
    //retorn el private Diccionari d'una instancia busqueda_binaria
    vector<int>  getDic() {
        return Diccionari;
    }
    void merge(vector<int>& Diccionari, int l, int m, int r)
    {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) {
        L[i] = Diccionari[l + i];
        NumAuxAssig++;
    }
        
    for (j = 0; j < n2; j++){
        
        R[j] = Diccionari[m + 1+ j];
        NumAuxAssig++;
    }
      
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            Diccionari[k] = L[i];
            NumAssig++;
            i++;
        }
        else if(L[i] == R[j])
        {
            NumComp++;
            Diccionari[k] = L[i];
            NumAssig++;
            i++;
        }
        else
        {
            NumComp++;
            Diccionari[k] = R[j];
            NumAssig++;
            j++;
        }
        NumComp++;
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        Diccionari[k] = L[i];
        NumAssig++;
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        Diccionari[k] = R[j];
        NumAssig++;
        j++;
        k++;
    }
    }
    
    /* l is for left index and r is right index of the
   sub-array of arr to be sorted */
    void mergeSort(vector<int>& arr, int l, int r)
    {
        if (l < r)
        {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(Diccionari, l, m);
        mergeSort(Diccionari, m+1, r);
 
        merge(Diccionari, l, m, r);
        }
    }
    /**void ordena(vector<int>& Diccionari) {
        vector<int> v = Diccionari;
        sort(v.begin(), v.end(), comp);
        setDiccionari(v);
    }**/
    
    inline bool ContieneNumero(int x) {
        int i = 0;
        int d = Diccionari.size() - 1;
    
        while (i <= d) {
            int m = (i + d)/2;
            
            if  (x < Diccionari[m]){
                CompFallades++;
                d = m - 1;
            } 
            else if (x > Diccionari[m]){
                CompFallades++;
                i = m + 1;
            } 
            else    {
                CompFallades++;
                CompBones++;
                return true;
            }          
        }
        CompFallades++;
        return false;
    }


int main(int argc, char* argv[]) 
{
        
       /* chrono::steady_clock::time_point start= chrono::steady_clock::now();
        int j=0;
        for(int i=0; i<1000000; i++){
            j++;
        }
        chrono::steady_clock::time_point end= chrono::steady_clock::now();
        chrono::steady_clock::duration d= end-start;
        cout << chrono::duration_cast<chrono::milliseconds>(d).count();*/
        ifstream dic;
        ifstream text;
        int n;
        vector<int> v1;
        vector<int> v2;
        dic.open("diccionari.txt");
        while (dic >> n){
        v1.push_back(n);
        }
        busqueda_binaria myBusquedaBinaria;
        myBusquedaBinaria.setDiccionari(v1);
        myBusquedaBinaria.mergeSort(v1,0,v1.size()-1);
        text.open("entrada.txt");
        while (text >> n){
        v2.push_back(n);
        }
        
        vector<bool> result(v2.size());
        for (int i = 0; i < v2.size(); ++i) {
            result[i] = myBusquedaBinaria.ContieneNumero(v2[i]);
        }
        for (int i = 0; i < v2.size(); ++i) {
            cout << result[i];
        }
        cout << "\n" << " Nombre de Comparacions que fa el algoritme: " << NumComp;
        cout << "\n Nombre d'assignacions auxliars que es fan per ordenar el Diccionari: " << NumAuxAssig;
        cout << "\n Nombre d'assignacions que es fan al Diccionari després d'ordenar:' "<<  NumAssig;
        cout << "\n Nombre de comparacions fallades amb la entrada i el Diccionari: " << CompFallades;
        cout << "\n Nombre de comparacions encertades amb la entrada i el Diccionari: " << CompBones; 
    }



