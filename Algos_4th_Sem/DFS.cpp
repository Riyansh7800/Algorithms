#include <iostream>
#include <stack>
#include <list>
using namespace std;
template <class t>
class Depth_First_Search {
public:
    list<t> *edges;
    int V;

    Depth_First_Search(int n) {
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
            cout<<"inside list of "<<v1<<" We have "<<v2<<endl;
             edges[v2].push_back(v1);
             cout<<"inside list of "<<v2<<" We have "<<v1<<endl;
             cout<<endl;
            
        }
         
    }
    void printG(){
        for(int d=1;d<V;++d){
            cout<<"Vertex "<<d<<" ";
        for (int i : edges[d])
         {cout<<" -> "<<i;
    }
  cout<<endl;
        }
    }
    
    void print(int s){
        bool explored[V];
        for(int i=0;i<V;i++){
            explored[i]=false;
        }
      

        stack<int> S;
        S.push(s);
       
        while(!S.empty()){
            int p=S.top();
            S.pop();
            cout<<"Parent : "<<p<<endl;
            if(explored[p]== false){
                explored[p]=true;
                cout<<"Child is : "<<endl;
              
                    for(int i:edges[p]){
                        if(!explored[i]){
                            explored[p]=true;
                                  cout<<i<<" ";
                                S.push(i);
                               
                               
                
                
                }
                cout<<endl;
              

            }

            
            }
        }
         
                           

        }
        

    
        


    
};
int main(){
    cout<<"Enter the total number of vertices : ";
    int n;
    cin>>n;

    Depth_First_Search<int> b1(n);
    b1.input();
   
    int source;
    cout<<" Enter the source vertex : ";
    cin>>source;
   
    cout<<"\nDFS Tree : "<<endl;
    b1.print(source);

    cout<<"\nAdjacency List : "<<endl;
    b1.printG();
   
return 0;
}