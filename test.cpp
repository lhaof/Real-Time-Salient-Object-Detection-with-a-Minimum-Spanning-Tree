#include <iostream>
#include <vector>

#include "ADJ.h"
#include "lodepng.h"
#include "utils.h"
#include "MST.h"

/*
red value of i-th pixel: i * 4 
green value of i-th pixel: i * 4 + 1
blue value of i-th pixel: i * 4 + 2
alpha value of i-th pixel: i * 4 + 3
*/

using namespace std;

int main() {
	const char* filename = "0004.png";
	vector<unsigned char> image;
	unsigned width, height;
	unsigned _error = lodepng::decode(image, width, height, filename);
	if(_error) cout << "decoder error " << endl; 
	cout << "width: " << width << " height: " << height << endl;

	GridGraph graph(height, width, image, &get_weight_func);
	graph.display_vertices(0, 2, 0, 2);

	Graph g(10);
	/*
	g.insert_undirected_edge(0,1,3); g.insert_undirected_edge(0,2,10); 
	g.insert_undirected_edge(0,3,13);
	g.insert_undirected_edge(1,3,30); g.insert_undirected_edge(1,5,21);
	g.insert_undirected_edge(1,7,9);
	g.insert_undirected_edge(2,3,5); g.insert_undirected_edge(2,4,29);
	g.insert_undirected_edge(2,8,33);
	g.insert_undirected_edge(3,4,19); g.insert_undirected_edge(3,5,17);
	g.insert_undirected_edge(3,6,25);
	g.insert_undirected_edge(4,6,9); g.insert_undirected_edge(4,8,26);
	g.insert_undirected_edge(4,9,6);
	g.insert_undirected_edge(5,6,8); g.insert_undirected_edge(5,7,12);
	g.insert_undirected_edge(6,9,3);
	g.insert_undirected_edge(8,9,1);
	*/

	/*
	g.insert_undirected_edge(0,1,2); g.insert_undirected_edge(0,2,3); 
	g.insert_undirected_edge(0,3,3);
	g.insert_undirected_edge(1,3,3); g.insert_undirected_edge(1,5,5);
	g.insert_undirected_edge(1,7,2);
	g.insert_undirected_edge(2,3,5); g.insert_undirected_edge(2,4,3);
	g.insert_undirected_edge(2,8,4);
	g.insert_undirected_edge(3,4,2); g.insert_undirected_edge(3,5,2);
	g.insert_undirected_edge(3,6,5);
	g.insert_undirected_edge(4,6,4); g.insert_undirected_edge(4,8,2);
	g.insert_undirected_edge(4,9,3);
	g.insert_undirected_edge(5,6,3); g.insert_undirected_edge(5,7,3);
	g.insert_undirected_edge(6,9,5);
	g.insert_undirected_edge(8,9,4);
	g.display_vertices();
	MSTree t(&(g.vertex_pool[7]), &g);
	*/

	g.insert_undirected_edge(0,1,3); g.insert_undirected_edge(0,3,3);
	g.insert_undirected_edge(1,2,1); g.insert_undirected_edge(1,4,2);
	g.insert_undirected_edge(2,5,1);
	g.insert_undirected_edge(3,4,2); g.insert_undirected_edge(3,6,3);
	g.insert_undirected_edge(4,5,1); g.insert_undirected_edge(4,7,2);
	g.insert_undirected_edge(5,8,1);
	g.insert_undirected_edge(6,7,3);
	g.insert_undirected_edge(7,8,1);
	g.display();
	MSTree t(&(g.vertex_pool[4]), &g);
	t.display();
	return 0;
}