
#include <iostream>
#include "Graph.h"
#include "testGraph.h"
#include <string>


int main(void)
{
	Vertexs::vertex<long, 3> v(2333, 45456);

	G2 g(v);

	int data1 = 8964;
	int data2 = 817;

	Vertexs::vertex<long, 3> v_add_1(8964, 2333);
	Vertexs::vertex<long, 3> v_add_2(817, 23333);


	std::cout << "Put v1 : "  << g.put_vertex(v_add_1) << std::endl;
	std::cout << "Put v2 : " << g.put_vertex(v_add_2) << std::endl;
	std::cout << "Put v2 again : " << g.put_vertex(v_add_2) << std::endl;

	std::cout << "Put v1->v2 : " << g.put_link(v_add_1, v_add_2, 0) << std::endl;

	if (g.have(v_add_1))
		std::cout << "v_add_1 found." << std::endl;
	else
		std::cout << "Cannot find v_add_1." << std::endl;

	std::cout << "G2::g = " << g << std::endl;

	g.excited();

	Graphs::Graph<long, 8> gp(Vertexs::vertex<long, 8>(1222, 2132));
	gp.put_vertex(Vertexs::vertex<long, 8>(12243, 56433));
	gp.put_vertex(Vertexs::vertex<long, 8>(1224453, 5556534));
	gp.put_vertex(Vertexs::vertex<long, 8>(23434, 65565));

	std::cout << gp << std::endl;

#define VertexString(a,b) Vertexs::vertex<std::string, 8>(a, b)

	std::cout << "Test String:========" << std::endl;

	Graphs::Graph<std::string, 8> gs(Vertexs::vertex<std::string, 8>(12434, "JiangZeming"));
	gs.put_vertex(VertexString(12243, "Zeming"));
	gs.put_vertex(VertexString(1224453, "Excited"));
	gs.put_vertex(VertexString(23434, "sdgfeew"));

	std::cout << gs << std::endl;

}
