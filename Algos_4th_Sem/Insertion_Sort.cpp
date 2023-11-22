#include<iostream>
using namespace std;

template<class T>
T array[50];
int n;

template<class T>
void input() {
    cout << "\nEnter the size of the Array: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\tEnter element no. " << (i + 1) << " in the Array: ";
        cin >> array<T>[i];
    }
}

template<class T>
//printing the array
void output() {
    for (int i = 0; i < n; ++i) {
        if (i != 0)
            cout << ", ";
        cout << array<T>[i];
    }
    cout << endl;
}

template<class T>
void InsertionSort() {
    int j;
    T temp;
    for (int i = 1; i < n; ++i) {
        
        temp = array<T>[i];
        j = i - 1;
        
        while (j >= 0 && array<T>[j] > temp) {
            array<T>[j +
                     1] = array<T>[j];   
            j = j - 1;         
        }

        array<T>[j +
                 1] = temp;    
    }
}
int main(){
    input<T>();
    cout << "--------------------------------------\n";
    cout << "Array Before Sort: ";
    output<T>();
    cout<<endl;
    InsertionSort<T>();
            cout << "Array After Insertion Sort: ";
            output<T>();

    return 0;
}