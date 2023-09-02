#include <iostream>
#include "./HeapClass.h"

void Heapify(vector<int> &arr, int size, int i)
{
    int index = i;
    int left = 2 * index;
    int right = 2 * index + 1;
    int largest = index;

    if (left <= size && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right <= size && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        index = largest;
        Heapify(arr, size, index);
    }
}

void BuildHeap(vector<int>&arr, int size){
    for(int i = size/2; i > 0; i--){
        Heapify(arr, size, i);
    }
}

void HeapSort(vector<int>&arr, int n){
     while(n != 1){
        swap(arr[1], arr[n]);
        n--;
        Heapify(arr, n, 1);
     }
}

int main()
{
    // Heap *h = new Heap();
    // h->arr.push_back(100);
    // h->arr.push_back(50);
    // h->arr.push_back(60);
    // h->arr.push_back(40);
    // h->arr.push_back(45);
    // h->size = h->arr.size()-1;
    // h->Insert(50);
    // h->Insert(30);
    // h->Insert(70);
    // h->Insert(40);
    // h->Insert(80);
    // h->Insert(100);
    // cout << "Before Deletion";
    // h->PrintHeap();
    // cout << "After Deletion";
    // h->Delete();
    // h->PrintHeap();

    vector<int> vect1;
    vect1.push_back(-1);
    vect1.push_back(12);
    vect1.push_back(56);
    vect1.push_back(43);
    vect1.push_back(6);
    vect1.push_back(78);
    vect1.push_back(87);
    vect1.push_back(5);
    vect1.push_back(44);
    vect1.push_back(3);
    vect1.push_back(23);
    vect1.push_back(32);
    BuildHeap(vect1, vect1.size()-1);
    for(auto i: vect1){
        cout<<i<<" ";
    }
    HeapSort(vect1, vect1.size()-1);
    cout<<endl;
    for(auto i: vect1){
        cout<<i<<" ";
    }
    return 0;
}