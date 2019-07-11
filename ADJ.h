#include <cassert>
#include <cstdio>


class Vertex {
public:
	int vertex_id;
	Vertex() {
		this->vertex_id = -1;
	}
	Vertex(int id) {
		this->vertex_id = id;
	}
	void set_id(int id) {
		this->vertex_id = id;
	}
	int get_id() {
		return this->vertex_id;
	}
};


class Edge {
public:
	Edge() {
		this->edge_from = this->edge_to = NULL;
		this->edge_w = -1;
	}
	Edge(Vertex *edge_from, Vertex *edge_to) {
		this->edge_from = edge_from;
		this->edge_to = edge_to;
	}
	Edge(Edge& e) {
		this->edge_from = e.get_edge_from();
		this->edge_to = e.get_edge_to();
		this->edge_w = e.get_edge_weight();
	}
	Vertex* get_edge_from() {
		return edge_from;
	}
	Vertex* get_edge_to() {
		return edge_to;
	}
	int get_edge_weight() {
		return edge_w;
	}
private:
	Vertex *edge_from, *edge_to;
	int edge_w;
};


class ListNode {
public:
	ListNode() {
		this->prev = this->next = NULL;
		this->cur = NULL;
		this->is_a_head = false;
		this->belong_to_vertex = NULL;
	}
	bool is_head() {
		return this->is_a_head;
	}
	Edge* get_edge() {
		return this->cur;
	}
	ListNode* get_prev() {
		return this->prev;
	}
	ListNode* get_next() {
		return this->next;
	}
	void set_vertex(Vertex *belong_to_vertex) {
		this->belong_to_vertex = belong_to_vertex;
		this->is_a_head = true;
	}
	void set_edge(Edge *p_edge) {
		this->cur = p_edge;
	}
	void set_prev(ListNode *prev) {
		this->prev = prev;
	}
	void set_next(ListNode *next) {
		this->next = next;
	}
	void insert_edge(Edge *new_edge) {
		ListNode *p_cur_node = this;
		while (!p_cur_node->is_head()) {
			assert(p_cur_node->get_prev());
			p_cur_node = p_cur_node->get_prev();
		}
		ListNode *pListNode = new ListNode;
		pListNode->set_edge(new_edge);
		pListNode->set_prev(p_cur_node);
		pListNode->set_next(p_cur_node->next);
		if (p_cur_node->get_next() == NULL) {
			p_cur_node->set_next(pListNode);
		} else {
			p_cur_node->get_next()->set_prev(pListNode);
			p_cur_node->set_next(pListNode);
		}
	}
private:
	ListNode *prev, *next;
	Edge *cur;
	bool is_a_head;
	Vertex *belong_to_vertex;
};


class Graph {
public:
	Vertex *vertex_pool;
	ListNode *vertex_to_edge;
	int vertex_num;

	Graph() {
		this->vertex_num = 0;
	}

	Graph(int vertex_num) {
		this->create_vertices(vertex_num);
	}

	void create_vertices(int vertex_num) {
		assert(vertex_num >= 0);
		this->vertex_num = vertex_num;
		this->vertex_pool = new Vertex[vertex_num];
		this->vertex_to_edge = new ListNode[vertex_num];
		for (int i = 0;i < vertex_num; i++) {
			this->vertex_pool[i].set_id(i);
			this->vertex_to_edge[i].set_vertex(&(this->vertex_pool[i]));
		}
	}

	void insert_edge(Vertex *from_vertex, Vertex *to_vertex) {
		Edge *pEdge = new Edge(from_vertex, to_vertex);
		vertex_to_edge[ from_vertex->vertex_id ].insert_edge(pEdge);
	}

	void insert_edge(int from_vertex_id, int to_vertex_id) {
		this->insert_edge(&(this->vertex_pool[from_vertex_id]), &(this->vertex_pool[to_vertex_id]));
	}

	void display_vertices() {
		for (int i = 0;i < vertex_num; i++) {
			printf("vertex_id: %d, ",vertex_pool[i].get_id());
			ListNode *p_cur_node = &(vertex_to_edge[i]);
			while(p_cur_node->get_next()) {
				p_cur_node = p_cur_node->get_next();
				if (p_cur_node->get_edge()) {
					printf("%d->%d ", p_cur_node->get_edge()->get_edge_from()->get_id(), p_cur_node->get_edge()->get_edge_to()->get_id());
				}
			}
			printf("\n");
		}
	}
};

class GridGraph: public Graph {
public:
	int grid_height, grid_width;
	GridGraph(int grid_height, int grid_width) {
		this->grid_height = grid_height;
		this->grid_width = grid_width;
		this->create_vertices(grid_height * grid_width);
		for (int i = 0;i < grid_height * grid_width; i++) {
			if (i - grid_width >= 0) {
				this->insert_edge(i, i - grid_width);
			}
			if (i % grid_width < grid_width - 1) {
				this->insert_edge(i, i + 1);
			}
			if (i + grid_width < grid_height * grid_width) {
				this->insert_edge(i, i + grid_width);
			}
			if (i % grid_width > 0) {
				this->insert_edge(i, i - 1);
			}
		}
	}
};