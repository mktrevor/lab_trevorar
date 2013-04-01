#include <iostream>
#include <cstdlib>
#include "minarrayheap.h"
using namespace std;

const int MAXVAL = 1024;

void genRandArray(int *data, int len)
{
  for(int i=0; i < len; i++){
    data[i] = rand() % MAXVAL;
  }
}

void printArray(int *data, int len)
{
  cout << "Array contents are: " << endl;
  for(int i=1; i < len; i++){
    cout << data[i] << endl;
  }
}
int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Please provide the size of the array and a random seed number" << endl;
    return 1;
  }
  int size = atoi(argv[1]);
  int seed = atoi(argv[2]);
  srand(seed);

  int *data = new int[size];
  genRandArray(data, size);
  
  printArray(data, size);

  MinArrayHeap<int> h(data, size);

  // Eventually add some pushes here




  cout << "Heap contents as they are popped: " << endl;
  while( !h.empty() ){
    cout << h.top() << endl;
    h.pop();
  }
  delete [] data;

  return 0;
}
