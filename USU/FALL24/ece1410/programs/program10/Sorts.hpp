
#ifndef SORTS_HPP
#define SORTS_HPP
 
class Sorts
{
  public:
  void bubble(int*, int);
  void insertion(int*, int);
  void quick(int*, int);
  
  // Any Other Function you want to declare

  private:

	  // Any Variables you will need
};


// IMPLEMENTATION --- YOUR CODE

void Sorts::bubble(int* arr, int n){
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

void Sorts::insertion(int* arr, int n){
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

void Sorts::quick(int*, int){
  return;
}
#endif