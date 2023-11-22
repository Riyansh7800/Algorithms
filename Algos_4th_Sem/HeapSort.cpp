#include <iostream>

using namespace std;

template<class T>
class Heap {
public:

    int size;
    int heapSize;
    int counter;
    T *array;

    Heap(int n) {
        size = n;
        heapSize = n;
        counter = 0;
        array = new T[n];
    }

    void inputArray() {
        for (int i = 0; i < size; i++) {
            cout << "Enter Element [" << i << "]: ";
            cin >> array[i];
        }
    }

    void printArray() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << ", ";
        }
        cout << "\b\b\n";
    }

    void maxHeapify(T array[], int i) {
   
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

    
        if (left <= heapSize - 1 && array[left] >= array[i]) {
            largest = left;
            counter++;
        }
       
        if (right <= heapSize - 1 && array[right] >= array[largest]) {
            largest = right;
            counter++;
        }
       
        if (i != largest) {
            swap(i, largest);
            maxHeapify(array, largest);
        }
    }

    void buildMaxHeap() {
        for (int i = size / 2; i >= 0; i--) {
            maxHeapify(array, i);
        }
    }

    void swap(int i, int j) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    void heapSort() {
    
        for (int i = size - 1; i >= 1; i--) {
            swap(i, 0);
            heapSize = heapSize - 1;
            maxHeapify(array, 0);
        }
    }

};

int main() {
  

    cout << "---------------------------------------------------------\n";
    cout << "Enter the Size of the Array: ";
    int n;
    cin >> n;

 
        Heap<int> obj(n);
        cout << "The Array you have entered is ";
        obj.printArray();
        obj.buildMaxHeap();
        cout << "The Heapified Array is ";
        obj.printArray();
        obj.heapSort();
        cout << "The Array After Heap Sort is ";
        obj.printArray();
        cout << "The Total no of comparisons is " << counter << endl;
        
   

    return 0;
}