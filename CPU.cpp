//Adrian Biller A01018940 matrix multiplication using cpu with lineal problem






#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void printArray(int ** array, int size){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      cout<<" "<<array[i][j];
    }
    cout<<endl;
  }
  cout<<endl;
}



int** generateData(int size){
  int** array = new int*[size];
  for(int i = 0; i < size; i++){
    array[i] = new int [size];
    for(int j = 0; j < size; j++){
      array[i][j] = rand() % 10;
    }
  }
  // printArray(array, size);
  return array;
}

int ** multiplyMatrices(int** matrixA, int ** matrixB, int size){
  int ** multiplication  = new int*[size];
  for(int i = 0; i < size; i++){
    multiplication[i] = new int[size];
    for(int j = 0; j < size; j++){
      for(int k = 0; k < size; k++){
        multiplication[i][j] += matrixA[i][k] * matrixB[k][j];
      }
    }
  }
  return multiplication;
}



int main(){
  //row column
  srand(time(NULL));
  clock_t begin = clock();


  cout<< "1 for multiplication of 1000 x 1000 matrix"<<endl;
  cout<< "2 for multiplication of 2000 x 2000 matrix"<<endl;
  cout<< "3 for multiplication of 4000 x 4000 matrix"<<endl;
  int size = 0;
  cin>>size;
  if(size == 1)
    size = 1000;
  else if(size == 2)
    size = 2000;
  else
    size = 4000;
  int ** array1  = generateData(size);
  int ** array2  = generateData(size);
  int ** mult = multiplyMatrices(array1, array2, size);
  cout<<"Multiplication result"<<endl;
  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  printArray(mult, size);
  cout<<"Elapsed time: "<<elapsed_secs<<" seconds"<<endl;
  return 0;
}
