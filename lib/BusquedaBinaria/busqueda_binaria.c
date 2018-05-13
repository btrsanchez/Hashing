#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>

using namespace std;

int NumComp=0;
int NumAssig=0;
int NumAuxAssig=0;
int CompFallades=0;
int CompBones=0;

vector<int> Diccionari;

static bool comp(int a, int b) { return a < b; }

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
        
    for (j = 0; j < n2; j++) {
        
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
    
void mergeSort(vector<int>& Diccionari, int l, int r)
{
                /* l is for left index and r is right index of the
   sub-array of arr to be sorted */
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
    
void Binaria(vector<int> dicc,vector<int> text) 
{
    int n;

    //chrono::steady_clock::time_point start= chrono::steady_clock::now();
    Diccionari = dicc;

    mergeSort(Diccionari,0,Diccionari.size()-1);

    vector<bool> result(text.size());
    
    for (int i = 0; i < text.size(); ++i) {
        result[i] = ContieneNumero(text[i]);
    }
                    
    /*chrono::steady_clock::time_point end= chrono::steady_clock::now();
    chrono::steady_clock::duration d= end-start;
    cout << chrono::duration_cast<chrono::microseconds>(d).count()<< endl;*/
    /**for (int i = 0; i < v2.size(); ++i) {
        cout << result[i];
    }**/
    cout << "\n" << " Número de comparaciones que hace el algoritmp de ordenar: " << NumComp;
    cout << "\n Número de asignaciones auxliares que se hacen para ordenar el Diccionari: " << NumAuxAssig;
    cout << "\n Número de asignaciones que se hacen al Diccionari después de ordenar:' "<<  NumAssig;
    cout << "\n Número de comparaciones falladas con la entrada y el Diccionari: " << CompFallades;
    cout << "\n Número de comparaciones acertadas con la entrada y el Diccionari: " << CompBones << endl;
}

