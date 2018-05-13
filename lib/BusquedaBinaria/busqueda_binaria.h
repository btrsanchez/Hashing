#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
//#include <chrono>

using namespace std;
  
static bool comp(int a, int b);
void merge(vector<int>& Diccionari, int l, int m, int r);
void mergeSort(vector<int>& arr, int l, int r);
inline bool ContieneNumero(int x);
void Binaria(vector<int> Diccionari,vector<int> text);