#include"Digraph.h"
#include"List.cpp"
#include<iostream>
using namespace std;
template<int max_size>
void Digraph<max_size>::depth_first(void(*visit)(Vertex&))const
{
	bool visited[max_size];
	Vertex v;
	for(int v=0;v<count;v++)
		visited[v]=false;
	for(int v=0;v<count;v++)
		if(!visited[v])
			traverse(v,visited,visit);
}
template<int max_size>
void Digraph<max_size>::traverse(Vertex &v,bool visited[],void (*visit)(Vertex&))const
{
	Vertex w;
	visited[v]=true;
	(*visit)(v);
	for(int i=0;i<neighbors[v].size();i++)
	{
		neighbors[v].retrieve(i,w);
		if(!visited[w])
			traverse(w,visited,visit);
	}
}
template<int max_size>
void Digraph<max_size>::breadth_first(void(*visit)(Vertex &))const
{
	Queue q;
	bool visited[max_size];
	Vertex v,w,x;
	for(v=0;v<count;v++)
		visited[v]=false;
	for(v=0;v<count;v++){
		if(!visited[v])
			q.append(v);
		visited[v]=true;
		while(!q.empty()){
			q.retrieve(w);
				(*visit)w;
			for(int i=0;i<neighbor[w].size();i++)
			{
				neighbor[w].retrieve(i,x);
				if(!visited[x])
				{
					q.append(x);
					visited[x]=true;
				}
			}
			q.serve();
		}
	}
}
template<int graph_size>
void Digraph<graph_size>::depth_sort(List<Vertex>&topological_order)
{
	bool visited[graph_size];
	Vertex v;
	for(v=0;v<count;v++)
		visited[v]=false;
	topological.clear();
	for(v=0;v<count;v++)
		if(!visited[v])
		recursive_depth_sort(v,visited,topological_order);
}
template<int graph_size>//先把它的后径写出来，当后径出完后再写它本身。
void Digraph<graph_size>::recursive_depth_sort(Vertex ,bool *visited, List<Vertex>&topological_order)
{
	visited[v]=true;
	int degree=neighbors[v].size();
	for(int i=0;i<degree;i++){
		Vertex w;
		neighbors[v].retreive(i,w);
		if(!visited[w])
			recursive_depth_sort(w,visited,topologocal_order);
	}
	topological_order.insert(0,v);
}
template<int graph_size>//先把前驱为0的放在最后一位，再把它自己相应的后径减一，使得0的再出来。
void Digraph<graph_size>::breadth_sort(List<Vertex>&topological_order)
{
	topological.clear();
	Vertex v,w;
	int predecessor_count[graph_size];
	for(int i=0;i<graph_size)
		predecessor_count[i]=0;
	for(v=0;v<count;v++)
	{
		for(int i=0;i<neighbor[v].size();i++)
		{
			neighbor[v].retreieve(i,w);
			predecessor_count[w]++;
		}
	}
	Queue ready_to_predecessor[graph_size];
	for(v=0;v<count;v++)
		if(predecessor_count[v]==0)
			ready_to_predecessor[v].append;
		while(!ready_to_predecessor.empty()){
			ready_to_precessor[v].retrieve(v);
			topological_order.insert(topological_order.size(),v);
			for(int j=0;j<neighbors[v].size();j++)
			{
				neighbors[v].retrieve(j,w);
				predecessor_count[w]--;
				if(predecessor_count[w]==0)
					ready_to_predecessor.append(w);
			}
			ready_to_predecessor.serve();
		}
}
template<int graph_size>//?
void Digraph<graph_size>::printf_in(Vertex v)
{
	Vertex w;
	Vertex m;
	new_one[graph_size];
	for(int i=0;i<graph_size;i++)
		new_one[i]=0;
	for(w=0;w<count;w++){
		for(int j=0;j<neighbors[w].size();j++)
		{
			neighbors[w].retrieve(j,m);
			new_one[m]++;
		}
	}
	cout<<new_one[v];
}
template<int graph_size>
void Digraph<gragh_size>::printf_out(Vertex v)
{
	cout<<neighbors[v].size();
}





