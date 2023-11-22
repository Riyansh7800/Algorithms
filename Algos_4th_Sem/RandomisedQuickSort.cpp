#include <iostream>
#include <ctime>
using namespace std;
template<class T>
class RandomisedQuickSort {
public:
   
    int size;
    int counter;
    T *array;

   
    RandomisedQuickSort(int n) {
        size = n;
        counter = 0;
        array = new T[n];
    }

   
    void input() {
        for (int i = 0; i < size; i++) {
            cout << "Enter Element [" << i << "]: ";
            cin >> array[i];
        }
    }

    
    void output() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << "  ";
        }
        cout << endl;

        cout<<"Number of Comparisons "<<counter<<endl;
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
        //pivRand = start + n%(end - start +1);
        srand(time(NULL));
        pivRand=start+(rand()%(end-start +1 ));
        cout<<"Pivot element is "<<array[pivRand]<<endl;
        swap(array[end], array[pivRand]);

        return partition(start, end);
    }

   
    void quickSort(int start, int end) {
        if (start < end) {
            //counter++;
           
            int pivotInd = randPartition(start, end);
            quickSort(start, pivotInd-1);
            quickSort(pivotInd+1, end);
        }
    }
};
int main(){
     int n;
    cout<<"Enter the number of elements in the array : ";
    cin >> n;
   RandomisedQuickSort<int> obj(n);
    obj.input();
    cout<<endl;
    obj.quickSort(0,n-1);

    cout<<"Array after Sorting "<<endl;
    obj.output();
}