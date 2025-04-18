
#ifndef SORTS_HPP
#define SORTS_HPP

#include <utility>
#include <algorithm>

using namespace std;
 
class Sorts
{
  public:
  void bubble(int*, int);
  void insertion(int*, int);
  void quick(int*, int);

  int part(int*, int, int); //quick sort partition
  void quickTwo(int*, int, int); //quick sort main for low and high
  
  // Any Other Function you want to declare

  private:

	  // Any Variables you will need
};


// IMPLEMENTATION --- YOUR CODE

void Sorts::bubble(int* arr, int n){ //bubble sort
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < n - i - 1; j++){
      if(arr[j] > arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  return;
}

void Sorts::insertion(int* arr, int n){ //insert sort
  for(int i = 1; i < n; i++){
    int curr = arr[i];
    int j = i - 1;
    while(j >= 0 && arr[j] > curr){
      arr[j+1] = arr[j];
      j = j - 1;
    }
    arr[j+1] = curr;
  }
  return;
}

void Sorts::quick(int* arr, int n){ //quick sort that sucked to make
  quickTwo(arr, 0, n-1);
  return;
}

int Sorts::part(int* arr, int lo, int hi){
  int pivot = arr[hi];
  int i = lo - 1;
  for(int j = lo; j < hi; j++){
    if(arr[j] <= arr[hi]){
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[hi]);
  return i + 1;
}

void Sorts::quickTwo(int* arr, int lo, int hi){
  while(lo < hi){ //keep while in range
    int pivot = part(arr, lo, hi); //find point to split
    quickTwo(arr, lo, pivot - 1);
    quickTwo(arr, pivot + 1, hi);
    return;
  }
}
#endif