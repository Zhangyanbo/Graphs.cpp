#pragma once

#include "Graph.h"

class G2 : public Graphs::Graph<long, 3>
{

#define G2Vertex Vertexs::vertex<long, 3>

public:
	G2() = default;
	G2(G2Vertex inital);

	void print_data(std::ostream &) const override;

	void excited(void) const;
};

inline void G2::print_data(std::ostream& os) const
{
	os << "G2\t{" << std::endl;
	for (auto i = 0; i < this->nodes.size(); ++i)
	{
		os << "G2.nodes[" << i << "]" << " :" << std::endl;
		os << nodes[i] << std::endl;
	}
	os << "}" << std::endl;
}

inline void G2::excited() const
{
	std::cout << "This thing you made...Excited!!" << std::endl;
	std::cout << "This things' size is " << nodes.size() << std::endl;
}

inline G2::G2(G2Vertex inital)
{
	put_vertex(inital);
}
