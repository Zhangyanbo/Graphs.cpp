#pragma once
#include <ostream>

namespace Vertexs {
	template <typename T_count, int d_out>
	struct vertex
	{
		vertex() = default;
		vertex(size_t name, T_count data) :
			$d(d_out),
			$name(name),
			$data(data)
		{
			for (auto i = 0; i < $d; ++i)
			{
				p_out[i] = nullptr;
				p_back[i] = nullptr;
			}
		}

		int $d;
		size_t $name;
		T_count $data;
		std::array<vertex*, d_out> p_out;
		std::array<vertex*, d_out> p_back;
	};

	template <typename T_count, int d_out>
	bool operator<(const vertex<T_count, d_out> &a, const vertex<T_count, d_out> &b) {
		return a.$name < b.$name;
	}

	template <typename T_count, int d_out>
	bool operator>(const vertex<T_count, d_out> &a, const vertex<T_count, d_out> &b) {
		return a.$name > b.$name;
	}

	template <typename T_count, int d_out>
	bool operator==(const vertex<T_count, d_out> &a, const vertex<T_count, d_out> &b) {
		return a.$name == b.$name;
	}

	template<typename Ty_>
	std::ostream &operator<<(std::ostream &os, const std::vector<Ty_> &item) {
		os << "{";
		for (auto i = 0; i < item.size() - 1; ++i)
		{
			os << ((item[i] == nullptr) ? "NULL" : "DATA") << ", ";
		}
		os << ((item[item.size() - 1] == nullptr) ? "NULL" : "DATA") << "}";

		return os;
	}

	template<typename Ty_, size_t s_>
	std::ostream &operator<<(std::ostream &os, const std::array<Ty_, s_> &item) {
		os << "{";
		for (auto i = 0; i < item.size() - 1; ++i)
		{
			os << ((item[i] == nullptr) ? "NULL" : "DATA") << ", ";
		}
		os << ((item[item.size() - 1] == nullptr) ? "NULL" : "DATA") << "}";

		return os;
	}

	template <typename T_count, int d_out>
	std::ostream &operator<<(std::ostream &os, const vertex<T_count, d_out> &item) {
		os << "Vertex_" << item.$name << "<" << item.$d << "> \t {" << std::endl;

		os << "\tlink out : " << item.p_out << std::endl;
		os << "\tlink in  : " << item.p_back << std::endl;
		os << "\tdatas : " << std::endl;
		os << "\t" << item.$data << std::endl;
		os << "}";

		return os;
	}
}