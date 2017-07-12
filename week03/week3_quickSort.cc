#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<random>
#include<algorithm>
using namespace std;

inline bool isLess(int,int);
void exchange(vector<int> &, int, int);
void init(int);
void readInput();
void printResult(const vector<int> &);

void myQuickSort(vector<int> &);
void quickSort(vector<int> &, int, int);
int myPartition(vector<int> &, int, int);
int myQuickFind(vector<int> &, int);
int quickFind(vector<int> &, int, int, int);

vector<int> test_array;
int quick_sort_compare = 0;

int main(){
  //readInput();
  init(20);
  printResult(test_array);
  myQuickSort(test_array);
  printResult(test_array);
  cout << "The comparation made by QuickSort is : "
       <<quick_sort_compare <<endl;
  cout << "The 5th smallest number is : "
       << myQuickFind(test_array, 5) <<endl;
}

inline bool isLess(int a, int b){
  return a<b ? 1 : 0;
}

void exchange(vector<int> &test_array, int i, int j){
  int temp = test_array[i];
  test_array[i] = test_array[j];
  test_array[j] = temp;
}

void init(int length){
  test_array.clear();
  srand(time(NULL));
  for (int i=0; i<length; i++){
    test_array.push_back(random()%100);
  }
}

void readInput(){
  int temp, N=0;
  cout<<"First key in the length of test array"<<endl;
  cin>>N;
  test_array.clear();
  while(N>=0) {
    test_array.push_back(temp);
    N--;
  }
}

void printResult(const vector<int> &test_array){
  cout << " The current array is :" << endl;
  for(int i = 0; i < test_array.size(); i++) {
    cout<< test_array[i] << ' ';
  }
  cout << endl;
}

int myPartition(vector<int> &test_array, int begin, int end){
  int i = begin + 1;
  for (int j = begin+1; j<=end; j++){
    quick_sort_compare ++; //comparation made by quick sort
    if (isLess(test_array[j], test_array[begin])){
      exchange(test_array, i, j);
      i++;
    }
  }
  exchange(test_array, begin, i-1);
  return i-1;
}


void quickSort(vector<int> & test_array,  int begin, int end){
  if (begin >= end) return;
  //printResult(test_array);
  int mid = myPartition(test_array, begin, end);
  quickSort(test_array, begin, mid-1);
  quickSort(test_array, mid+1, end);
}

void myQuickSort(vector<int> & test_array){
  quickSort(test_array, 0, test_array.size()-1);
}

int quickFind(vector<int> & test_array, int begin, int end, int k){
  if (begin == end && begin!= k) return -1;
  int mid = myPartition(test_array, begin, end);
  if (mid == k) return test_array[k];
  if (mid > k) return quickFind(test_array, begin, mid-1, k);
  if (mid < k) return quickFind(test_array, mid+1, end, k);
}

int myQuickFind(vector<int> & test_array, int k){
  //input k is kth, k-1 is kth element's index.
  return quickFind(test_array, 0, test_array.size()-1, k-1);
}
