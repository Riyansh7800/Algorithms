#include <iostream>
#include <cstdlib>

using namespace std;

class BucketSort {
private:
    int N;
    float **buckets;

public:
    BucketSort(int n) {
        N = n;
        buckets = new float*[N];
        for (int i = 0; i < N; i++) {
            buckets[i] = nullptr;
        }
    }

    void sort(float arr[], int size) {
        for (int i = 0; i < size; i++) {
            int bucket_index = arr[i] * N;
            if (buckets[bucket_index] == nullptr) {
                buckets[bucket_index] = new float[size];
                for (int j = 0; j < size; j++) {
                    buckets[bucket_index][j] = 0;
                }
            }
            int j = 0;
            while (buckets[bucket_index][j] != 0) {
                j++;
            }
            buckets[bucket_index][j] = arr[i];
        }
        int k = 0;
        for (int i = 0; i < N; i++) {
            if (buckets[i] != nullptr) {
                int bucket_size = 0;
                while (buckets[i][bucket_size] != 0) {
                    bucket_size++;
                }
                insertionSort(buckets[i], bucket_size);
                for (int j = 0; j < bucket_size; j++) {
                    arr[k] = buckets[i][j];
                    k++;
                }
            }
        }
    }

    void insertionSort(float arr[], int size) {
        int i, j;
        float key;
        for (i = 1; i < size; i++) {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
};

int main() {
    int size, num_buckets;
    cout << "Enter the size of the array: ";
    cin >> size;

    float *arr = new float[size];
    for (int i = 0; i < size; i++) {
        cin>>arr[i];
    }

    cout << "Enter the number of buckets: ";
    cin >> num_buckets;

    BucketSort sorter(num_buckets);
    sorter.sort(arr, size);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
       cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
