// BFS traversal  
#include<iostream> 
#include <list> 
using namespace std; 

class Graph 
{ 
	int V; // No. of vertices  
	list<int> *adj; // Pointer to an array containing adjacency list 

public: 
	
	Graph(int V) //Constructor
	{ 
	  this->V = V; 
	  adj = new list<int>[V]; 
    } 
 
	void addEdge(int v, int w)  // function to add an edge to graph
    { 
   	   adj[v].push_back(w); // Add w to v’s list. 
    }

	void BFS(int s) // prints BFS traversal from a given source s 
    { 
	 
	  bool *visited = new bool[V]; // marking all vertices as not visited
	  for(int i = 0; i < V; i++) 
		 visited[i] = false; 

	  list<int> queue; // Create a queue for BFS 

	  visited[s] = true; // Mark the current node as visited and enqueue it 
	  queue.push_back(s); 

	  // 'i' will be used to get all adjacent 
	  // vertices of a vertex 
	  list<int>::iterator i; 
      
      cout<<"\t";

	  while(!queue.empty()) 
	  { 
	 	 // Dequeue a vertex from queue and print it 
		 s = queue.front(); 
		 cout << s << " "; 
		 queue.pop_front(); 

		 // Get all adjacent vertices of the dequeued 
		 // vertex s. If a adjacent has not been visited, 
		 // then mark it visited and enqueue it 
		 for (i = adj[s].begin(); i != adj[s].end(); ++i) 
		 { 
			if (!visited[*i]) 
			{ 
 				visited[*i] = true; 
				queue.push_back(*i); 
			} 
		 } 
	  } 
    } 

}; 

int main() 
{ 
    cout<<"\n\n\tBFS Traversal for the graph given below"<<endl<<endl;

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

	Graph G(4); 
	G.addEdge(0, 1); 
	G.addEdge(0, 2); 
	G.addEdge(1, 2); 
	G.addEdge(2, 0); 
	G.addEdge(2, 3); 
	G.addEdge(3, 3); 

	cout << "\n\n\tFollowing is Breadth First Traversal "<< "(starting from vertex 2) \n\n"; 
	G.BFS(2); 
    cout<<endl<<endl<<"\t";
	return 0; 
} 
