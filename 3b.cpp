// DFS traversal  
#include<iostream> 
#include<list> 
using namespace std; 

class Graph 
{ 
	int V; // No. of vertices 
    list<int> *adj; // Pointer to an array containing adjacency lists

	// A recursive function used by DFS 
	void DFSUtil(int v, bool visited[])
	{  
      
      visited[v] = true; // Mark the current node as visited and print it
	  cout << v << " "; 

	  // Recur for all the vertices adjacent 
	  // to this vertex 
	  list<int>::iterator i; 
	  for (i = adj[v].begin(); i != adj[v].end(); ++i) 
		if (!visited[*i]) 
			DFSUtil(*i, visited); 
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


	// DFS traversal of the vertices 
	// reachable from v 
	void DFS(int v)
    { 
	  // Mark all the vertices as not visited 
	  bool *visited = new bool[V]; 
 	  for (int i = 0; i < V; i++) 
		 visited[i] = false; 

	  // Call the recursive helper function 
	  // to print DFS traversal
	  cout<<"\n\t"; 
	  DFSUtil(v, visited); 
    } 
}; 


int main() 
{ 
	cout<<"\n\n\tDFS Traversal for the graph given below"<<endl<<endl;

    cout<<"            0 -----------------> 1 \n";
    cout<<"            ^|                  /\n";
    cout<<"            ||                 /\n";
    cout<<"            ||                /\n";
    cout<<"            ||               /\n";
    cout<<"            ||              /\n";
    cout<<"            ||             /\n";
    cout<<"            ||            /\n";
    cout<<"            ||           /\n";
    cout<<"            ||          /\n";
    cout<<"            ||         /\n";
    cout<<"            ||        /\n";
    cout<<"            ||       /\n";
    cout<<"            ||      /\n";
    cout<<"            ||     /\n";
    cout<<"            ||    /               __\n";
    cout<<"            ||   /               |  |\n";
    cout<<"            ||  /                |  |\n";       
    cout<<"            |v L                 V  |\n";
    cout<<" start ----> 2 ----------------> 3---\n";
 
	Graph g(4); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(2, 0); 
	g.addEdge(2, 3); 
	g.addEdge(3, 3); 

	cout << "\n\n\tFollowing is Depth First Traversal (starting from vertex 2) \n"; 
	g.DFS(2); 
    cout<<endl<<endl<<"\t";
	return 0; 
} 
