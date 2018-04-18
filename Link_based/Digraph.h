#include"List.cpp"
typedef int Vertex;
template<int max_size>
class Digraph{
	int count;
	List<Vertex>neighbors[max_size];
	void depth_first(void (*visit)(Vertex&))const;
	void traverse(Vertex&v,bool visited[],void(*visit)(Vertex&))const;
	void depth_sort(List<Vertex>&topological_order);
	void recursive_depth_sort(Vertex,bool *visited,List<Vertex>&topological_order);
	void breadth_sort(List<Vertex>&topological_order);
	void printf_in(Vertex v);
	void printf_out(Vertex v);
};
