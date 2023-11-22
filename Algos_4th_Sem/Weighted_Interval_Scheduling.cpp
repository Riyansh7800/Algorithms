#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class IntervalScheduling{
public:
    int size;
    T* array;
    T* pj;
    int M[100];

    IntervalScheduling(int n){
        size = n;
        array = new T[n+1];
        pj = new T[n+1];
    }
    
    void inputArray() {
        for (int i = 1; i < size+1; i++) {
            cout << "Enter Weights [" << i << "]: ";
            cin >> array[i];
            cout << "Enter p(j) [" << i << "]: ";
            cin >> pj[i];
        }
        computeOPT(array,pj,size);
    }

    void printArray() {
        for (int i = 1; i < size+1; i++) {
            cout << "weights of  " <<i<<" Is "<< array[i] << " and P(" <<i<<") is  " << pj[i] << " "<<endl;
        }
        cout << endl;
    }
    
    void computeOPT(T arr[],T pj[],int n){
        M[0] = 0;
        for (int i = 1; i < n+1; i++){
            M[i] = max((arr[i] + M[pj[i]]), M[i-1]);
        }
        cout << "M is: ";
        for (int i = 0; i < n+1; i++){
            cout << M[i] << " ";
        }
        cout << endl;
    }
    
    void find_Solution(int n){
        if(n>=1){
            if ((array[n] + M[pj[n]]) >= M[n-1]){
                find_Solution(pj[n]);
            }
            else{
                find_Solution(n - 1);
            }
            cout << n << " ";
        } 
    }    
};
int main(){
    cout << "\n------------------------  WEIGHTED INTERVAL SCHEDULING -----------------------\n\n";
    cout << "Enter the number of jobs: ";
    int n;
    cin >> n;
    IntervalScheduling<int> obj(n);
    obj.inputArray();
    int size = n;
   
    cout<<endl;
    obj.printArray();
    cout<<endl;
    cout<<"The Optimal Solution is"<<endl;
    obj.find_Solution(size);
    
    return 0;
}