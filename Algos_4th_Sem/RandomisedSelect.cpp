#include <iostream>
#include <ctime>
using namespace std;

template<class T>
class RandomizedSelect {
public:
    
    int size;
    int counter;
    T *array;
    int smallestInd;

    RandomizedSelect(int n, int i) {
        size = n;
        counter = 0;
        array = new T[n];
        smallestInd = i;
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
   int partition(int start, int end) {
        
        T pivot = array[end];
        
        int i = start-1;

        for (int j = start; j < end; j++) {
            
            counter++;
            if (array[j] <= pivot) {
                i++;
                swap(array[j], array[i]);
            }
        }
        swap(array[i+1], array[end]);
        return (i+1);
    }

    int randPartition(int start, int end) {
        int pivRand;
        int n;
        srand(time(NULL));
        pivRand=start+(rand()%(end-start +1 ));
        cout<<"Pivot element is "<<array[pivRand]<<endl;
        swap(array[end], array[pivRand]);

        return partition(start, end);
    }

    int randomizedSelect(int start, int end, int smallestInd) {
        if (start == end) {
            return array[start];
        }
        int q = randPartition(start, end);
        int k = q - start + 1;
        if (smallestInd == k){ return array[q];
        }
        else if (smallestInd < k) {
            return randomizedSelect(start, q - 1, smallestInd);
        }
        else {
            return randomizedSelect(q + 1, end, smallestInd - k);
    }
    }
  
};

int main() {
    cout << "---------------------------------------------------------\n";
    cout << "Enter the Size of the Array: ";
    int n,i;
    cin >> n;
    cout << "Enter the ith smallest element you want to find: ";
    cin >> i;

    RandomizedSelect<int> obj(n, i);
    obj.inputArray();
        cout << "The Array you have entered is ";
        obj.printArray();
        int ithsmallestele = obj.randomizedSelect(0, n-1, i);
        cout << "ith Smallest Element that you searched in the Array is " << ithsmallestele << endl;
}