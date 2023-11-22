#include <iostream>
using namespace std;

template<class T> 
class MergeSort{
    int size;
    int comparisons;
    T* array;

    public:
        MergeSort(int n) {
            size = n;
            comparisons = 0;
            array = new T[size];
            for (int i = 0; i < size; i++) {
                cout << "Enter Element [" << i+1 << "]: ";
                cin >> array[i];
            }
            sort(0,size);
            cout << "\n Total Comparisons: " << comparisons << endl;
            cout << "\n Sorted Array :- " ;
            for (int i = 0; i < size; i++) {
                cout << array[i] << " ";
            }
        }
        void sort(int beg,int end){
            if(beg < end){
                int mid = (beg + end) / 2;
                sort(beg, mid);
                sort(mid+1, end);
                merge(beg, mid, end);
            }
        }

        void merge(int beg, int mid, int end){
            int left = mid - beg + 1;
            int right = end - mid;

            T left_array[left];
            T right_array[right];

            for(int i = 0; i < left ; ++i ){
                left_array[i] = array[beg + i];
            }
            cout << endl;
            for(int j = 0; j < right ; ++j ){
                right_array[j] = array[mid + j + 1];
            }
            int i= 0,j= 0,k= beg;

            while( i < left && j < right ){
                if(left_array[i]<=right_array[j]){
                    array[k] = left_array[i];
                    ++i;
                }else{
                    array[k] = right_array[j];
                    ++j;
                }
                ++comparisons;
                ++k;
            }

            while(i < left){
                array[k] = left_array[i];
                ++i;
                ++k;
            }

            while(j < right){
                array[k] = right_array[j];
                ++j;
                ++k;
            }  
        }
};

int main(){
    int n;
    cout<<"Enter the number of elements in the array : ";
    cin >> n;
    MergeSort<int> obj(n);
}
