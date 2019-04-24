// Topological sorting of a DAG 
#include<iostream> 
#include <list> 
#include <stack> 
using namespace std; 
 
class Graph 
{ 
	int V; // No. of vertices'  
	list<int> *adj; // Pointer to an array containing adjacency listsList

	// A function used by topologicalSort 
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
	{ 
	   // Mark the current node as visited. 
	   visited[v] = true; 

	   // Recur for all the vertices adjacent to this vertex 
	   list<int>::iterator i; 
	   for (i = adj[v].begin(); i != adj[v].end(); ++i) 
		  if (!visited[*i]) 
			 topologicalSortUtil(*i, visited, Stack); 
 
    	// Push current vertex to stack which stores result 
	    Stack.push(v); 
    }

public: 
	Graph(int V) // Constructor 
    { 
	  this->V = V; 
	  adj = new list<int>[V];  
    }  
	
	// function to add an edge to graph 
	void addEdge(int v, int w)
	{ 
	   adj[v].push_back(w); // Add w to v’s list. 
    } 

	
	// prints a Topological Sort of the complete graph 
	void topologicalSort() 
	{ 
	  stack<int> Stack; 

	  // Mark all the vertices as not visited 
	  bool *visited = new bool[V]; 
	  for (int i = 0; i < V; i++) 
		 visited[i] = false; 

	  // Call the recursive helper function to store Topological 
	  // Sort starting from all vertices one by one 
	  for (int i = 0; i < V; i++) 
	    if (visited[i] == false) 
		  topologicalSortUtil(i, visited, Stack); 
      
      cout<<endl<<"\t\t";
	  // Print contents of stack 
	  while (Stack.empty() == false) 
	  {  
		cout << Stack.top() << " "; 
		Stack.pop(); 
	  } 
    } 
}; 

int main() 
{ 
	cout<<"\n\n\tTopological Sorting for the graph given below"<<endl<<endl;
    cout<<"           5 ---------> 0 <--------- 4\n";
    cout<<"           |                         |\n";
    cout<<"           |                         |\n";
    cout<<"           |                         |\n";
    cout<<"           |                         |\n";
    cout<<"           |                         |\n";
    cout<<"           V                         V\n";
    cout<<"           2 ---------> 3 ---------> 1\n\n";

	Graph g(6); 
	g.addEdge(5, 2); 
	g.addEdge(5, 0); 
	g.addEdge(4, 0); 
	g.addEdge(4, 1); 
	g.addEdge(2, 3); 
	g.addEdge(3, 1); 

	cout << "\tFollowing is a Topological Sort of the given graph \n"; 
	g.topologicalSort(); 
	cout<<endl<<endl<<"\t";

	return 0; 
} 
