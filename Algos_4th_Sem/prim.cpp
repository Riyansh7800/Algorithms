#include<iostream>
#include<cstring>
#include<climits>
#include <list>
using namespace std;
class Node {
public:
    int dest;
    int weight;
    Node* next;

    Node(int dest, int weight) {
        this->dest = dest;
        this->weight = weight;
        this->next = nullptr;
    }
};

class HeapNode {
public:
    int v;
    int key;
};
class MinHeap {
public:
    HeapNode** arr; 
    int size;       
    int capacity;   

    MinHeap(int capacity) {
        this->capacity = capacity;
        arr = new HeapNode*[capacity];
        size = 0;
    }

    void insert(int v, int key) {
        if (size == capacity) {
            cout << "Heap overflow\n";
            return;
        }

        HeapNode* newNode = new HeapNode;
        newNode->v = v;
        newNode->key = key;

        arr[size] = newNode;
        size++;

        int i = size - 1;
        while (i != 0 && arr[parent(i)]->key > arr[i]->key) {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }
    HeapNode* extractMin() {
        if (size == 0) {
            return nullptr;
        }

        HeapNode* minNode = arr[0];

        arr[0] = arr[size - 1];
        size--;
        minHeapify(0);

        return minNode;
    }
    bool isEmpty() {
        return size == 0;
    }

private:
    int parent(int i) {
        return (i - 1) / 2;
    }
    int left(int i) {
        return 2 * i + 1;
    }
    int right(int i) {
        return 2 * i + 2;
    }

    void minHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < size && arr[l]->key < arr[smallest]->key) {
            smallest = l;
        }

        if (r < size && arr[r]->key < arr[smallest]->key) {
            smallest = r;
        }

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

};
class Graph {
public:
    int V;    
    list<Node>* adjList;   

    Graph(int V) {
        this->V = V;
        adjList = new list<Node>[V+1];
    }

    void addEdge(int src, int dest, int weight) {
        Node newNode(dest, weight);
        adjList[src].push_back(newNode);

        newNode.dest = src;
        adjList[dest].push_back(newNode);
    }

    int minKey(int* key, bool* mstSet) {
        int min = INT_MAX;
        int minIndex = -1;
        for (int v = 0; v < V; v++) {
            if (mstSet[v] == false && key[v] < min) {
                min = key[v];
                minIndex = v;
            }
        }
        return minIndex;
    }
    void PrimMST() {
        int* parent = new int[V]; // Array to store constructed MST
        int* key = new int[V]; // Key values used to pick minimum weight edge in cut
        bool* mstSet = new bool[V]; // To represent set of vertices not yet included in MST

        for (int i = 0; i < V; i++) {
            key[i] = INT_MAX;
            mstSet[i] = false;
        }
        key[0] = 0;
        parent[0] = -1; 
        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;
            for (Node v : adjList[u]) {
                if (mstSet[v.dest] == false && v.weight < key[v.dest]) {
                    parent[v.dest] = u;
                    key[v.dest] = v.weight;
                }
            }
        }
        printMST(parent, key);
    }


    void printMST(int* parent, int* key) {
        cout << "Edge \t     Weight\n";
         int totWeight = 0;
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " ->  " << i << "\t" << key[i] << endl;
            totWeight += key[i];
        }
        cout << "-----------------------------------\n";
        cout << "Total Cost: " << totWeight;
    }

};
int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the Graph details : "<<endl;
    for (int i = 1; i < E+1; i++) {
        int u, v, w;
       cout<<" the source : ";
        cin >> u ;
        cout<<endl;
        cout<<"the destinantion : ";
        cin>> v ;
        cout<<endl;
        cout<<"the weight  : ";
        cin>> w ;
        
        
        g.addEdge(u, v, w);
    }
    g.PrimMST();

    return 0;
}





