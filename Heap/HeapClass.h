#include <iostream>
using namespace std;

class Heap
{
public:
    vector<int> arr;
    int size;

    Heap()
    {
        arr.push_back(-1);
        size = 0;
    }

    void Insert(int value)
    {
        size += 1;
        int index = size;
        arr.push_back(value);

        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    void Delete()
    {
        swap(arr[1], arr[arr.size() - 1]);
        arr.pop_back();       
        size--;

        int index = 1;
        while (index < size)
        {
            int left = 2 * index;
            int right = 2 * index + 1;

            int largest = index;
            if (left < size && arr[left] > arr[largest])
            {
                largest = left;
            }
            if (right < size && arr[right] > arr[largest])
            {
                largest = right;
            }
            if (index == largest)
            {
                return;
            }
            else
            {
                swap(arr[largest], arr[index]);
                index = largest;
            }
        }
    }

    void PrintHeap()
    {
        for (auto i : arr)
        {
            cout << i << " " << endl;
        }
    }
};