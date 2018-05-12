#include <iostream>
#include "Bloom.h"

using namespace std;
int n, m, k;
BV bits;

void BloomFilter(BV bf, IV dic, IV txt, int siz, int bts, int funcs) {
  int c = 0;
  n = siz;
  m = bts;
  k = funcs;

  bits = bf;

  for (int i = 0; i < n; ++i){
    insert(txt[i]);
  }

  for (int i = 0; i < dic.size(); ++i) {
    if (contains(dic[i])) ++c;
    //cout << dic[i] << ": " << contains(dic[i]) << endl;
  }
  cout << c << " de les " << txt.size() << " paraules apareixen al diccionari.\n";
}

unsigned int MurmurHash2 (int key, int len, unsigned int seed ){

  const unsigned int s = 0x5bd1e995;
  const int r = 24;

  unsigned int h = seed ^ len;
  const unsigned char * data = (const unsigned char *)key;

  while(len >= 4)
  {
    unsigned int k = key;

    k *= s; 
    k ^= k >> r; 
    k *= s; 
    
    h *= s; 
    h ^= k;

    data += 4;
    len -= 4;
  }

  switch(len)
  {
  case 3: h ^= data[2] << 16;
  case 2: h ^= data[1] << 8;
  case 1: h ^= data[0];
          h *= s;
  };

  h ^= h >> 13;
  h *= s;
  h ^= h >> 15;

  return h;
}

int fnv_mix(unsigned int a) {
    a += a << 13;
    a ^= a >> 7;
    a += a << 3;
    a ^= a >> 17;
    a += a << 5;
    return a%m;
}

void insert(int value) {
  unsigned int a = MurmurHash2(value, 32, 0x9747b28c);
  unsigned int b = MurmurHash2(value, 32, a);
  unsigned int x;
  for (int i = 0; i < k; ++i){
    if (i%2) {
      x = fnv_mix(x%m);
    }
    else {
      x = (a + i*b) % m;
    }
    bits[x]=true; 
  }    
}
  
bool contains(int value) {
  int res = 0;
  unsigned int a = MurmurHash2(value, 32, 0x9747b28c);
  unsigned int b = MurmurHash2(value, 32, a);
  unsigned int x;
  for (int i = 0; i < k; ++i){
    if (i%2) x = fnv_mix(x%m);
    else {
      x = (a + i*b) % m;
    }
    if (bits[x]) ++res; 
  }
  return (res==k);
}