#include<iostream>
#include<vector>
using namespace std;

//This is a non Comparison sorting algorithm
//Good For small numbers

//so the steps for this count sort is

/*
    step1: find the largest element
    step2: create an frequency array with size largest lement + 1 and keep the elements frequency
    step3: update the original array with count and have an srted array
*/

void CountSort(vector<int>& arr, int n){
    int largest = arr[0];
    for(auto i: arr){
        largest = max(largest, i);
    }

    vector<int> frequencyArr(largest+1, 0);
    for(auto i: arr){
        frequencyArr[i]++;
    }

    int index = 0;
    for(int i = 0;i<=largest;i++){
        while(frequencyArr[i] > 0){
            arr[index] = i;
            index++;
            frequencyArr[i]--;
        }
    }
}

int main(){
    vector<int> arr = {3,4,4,1,6,3,5,3};
    CountSort(arr, 8);
    for(auto i: arr){
        cout<<i<<endl;
    }
    return 0;
}