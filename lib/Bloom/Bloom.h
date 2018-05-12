#include <vector>

using namespace std;

typedef vector<bool> BV;
typedef vector<int> IV;

void BloomFilter(BV bits, IV dic, IV txt, int n, int m, int k);

unsigned int MurmurHash2 (int key, int len, unsigned int seed );

int fnv_mix(int a);

void insert(int value);

bool contains(int value);