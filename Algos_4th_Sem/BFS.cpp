#include <iostream>
#include <queue>
#include <list>
using namespace std;
template <class t>
class Breadth_First_Search {
public:
    list<t> *edges;
    int V;
    Breadth_First_Search(int n) {
        V = n;
        edges = new list<int>[V+1];
    }
    void input(){
        int numberofedges;
        cout<<"Enter the number of edges : ";
        cin>>numberofedges;
         int v1,v2;
        for(int i=0;i<numberofedges;i++){
            cout<<"Enter the edge pair : ";
            cin>>v1;
            cin>>v2;
            edges[v1].push_back(v2);
        }
         
    }
    void printG(){
        for(int d=1;d<=V;++d){
            cout<<"Vertex "<<d<<" ";
        for (int i : edges[d])
         {cout<<" -> "<<i;
    }
  cout<<endl;
        }
    }
    
    void print(int s){
        int visited[V];
        for(int i=1;i<=V;++i){
            visited[i]=false;
        }
      

        queue<int> Q;
        Q.push(s);
        visited[s]=true;
        while(!Q.empty()){
            int front = Q.front();
            cout<<"Parent Node :"<<front<<endl;
            Q.pop();
            for(int i:edges[front]){
            if(!visited[i]){
                cout<<"  CHILD NODE :  ";
                cout<<i;
                
                Q.push(i);
                visited[i]=true;
                
                }

            }
            cout<<endl;

            }
    }  
    
};
int main(){
    cout<<'H';
    cout<<"Enter the total number of vertices : ";
    int n;
    cin>>n;

    Breadth_First_Search<int> b1(n);
    b1.input();
   
    int source;
        cout<<" Enter the source vertex : ";
        cin>>source;
    cout<<"\n BFS TREE \n";
    b1.print(source);
    cout<<"Adjacency List : "<<endl;
    b1.printG();
   
return 0;
}