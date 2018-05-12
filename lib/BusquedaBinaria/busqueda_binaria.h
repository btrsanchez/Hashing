#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
using namespace std;
  
    vector<int> Diccionari;
  void setDiccionari( vector<int>& Diccionario);
  vector<int>  getDic();
  void merge(vector<int>& Diccionari, int l, int m, int r);
  void mergeSort(vector<int>& arr, int l, int r);
  inline bool ContieneNumero(int x) ;

