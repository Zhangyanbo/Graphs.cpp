#pragma once

#include <map>
#include <vector>
#include <array>
#include "vertex.h"

#define HaveVertex(v)	(search_map.find(v)!=search_map.end())
#define GetIndex(v)		(search_map.at(v))

#define VERTEX_ Vertexs::vertex<T_count, d_out>

namespace Graphs
{
	//============================================================================================


	template <typename T_count, int d_out>
	// T_count	每个节点储存的信息
	// T_index	插入节点、边时，用以区分的数据，如点的坐标(1,2), (3,4)
	// d_out	维度
	class Graph
	{

	public:
		Graph() = default;
		Graph(VERTEX_ init_node) :
			nodes({}),
			$d(d_out)
		{
			//nodes.push_back(init_node);
			put_vertex(init_node);
		}

		//==========Functions===================
		virtual int put_link(VERTEX_, VERTEX_, int8_t);	// !!! v1.out -> v2, v2.back -> v1 !!!
		virtual int put_vertex(VERTEX_);
		virtual bool have(VERTEX_);
		virtual std::vector<VERTEX_> get_nodes(void) const;

		size_t size(void);

		virtual void print_data(std::ostream &) const;	// print datas inside the class.

		virtual ~Graph() = default;

	protected:
		std::vector<VERTEX_> nodes = {};
		std::map<VERTEX_, size_t> search_map;
		int $d;
		int $p = 0;
	};

	//===================Functions=========================

	template <typename T_count, int d_out>
	int Graph<T_count, d_out>::put_link(VERTEX_ v1, VERTEX_ v2, int8_t edge_index)
	{
		// edge_index should smaller than ($d - 1)
		if (edge_index > $d - 1)
			return -1;

		// Make sure they are in graph
		if (!HaveVertex(v1))
			put_vertex(v1);
		if (!HaveVertex(v2))
			put_vertex(v2);

		// Get vertexes' index
		size_t v1_index = GetIndex(v1);
		size_t v2_index = GetIndex(v2);

		// Link vertexes
		nodes[v1_index].p_out[edge_index] = &nodes[v2_index];
		nodes[v2_index].p_back[edge_index] = &nodes[v1_index];

		return 0;
	}

	template <typename T_count, int d_out>
	int Graph<T_count, d_out>::put_vertex(VERTEX_ v)
	{
		if (!HaveVertex(v))
		{
			$p++;
			nodes.push_back(v);
			search_map.insert({ v, $p });
		}
		else
		{
			return -1;
		}

		return 0;
	}

	template <typename T_count, int d_out>
	bool Graph<T_count, d_out>::have(VERTEX_ v)
	{
		return HaveVertex(v);
	}

	template <typename T_count, int d_out>
	std::vector<VERTEX_> Graph<T_count, d_out>::get_nodes(void) const
	{
		return nodes;
	}

	template <typename T_count, int d_out>
	size_t Graph<T_count, d_out>::size()
	{
		return nodes.size();
	}

	template<typename T_count, int d_out>
	inline void Graph<T_count, d_out>::print_data(std::ostream &os) const
	{
		os << "Graph\t{" << std::endl;
		for (auto i = 0; i < this->nodes.size(); ++i)
		{
			os << "Graph.nodes[" << i << "]" << " :" << std::endl;
			os << nodes[i] << std::endl;
		}
		os << "}" << std::endl;
	}

	template <typename T_count, int d_out>
	std::ostream &operator<<(std::ostream &os, Graph<T_count, d_out> &item) {
		item.print_data(os);

		return os;
	}
}
