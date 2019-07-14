/*
Author: lhaof / Haofeng Li
Contact: lhaof@foxmail.com
Date: 2019.7.14
*/

#include <iostream>
#include <vector>
#include <string>

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
	const char* filename = "0027.png";
	vector<unsigned char> image;
	unsigned width, height;
	unsigned _error = lodepng::decode(image, width, height, filename);
	if(_error) cout << "decoder error " << endl; 
	// cout << "width: " << width << " height: " << height << endl;

	GridGraph graph(height, width, image, &get_weight_func);
	// graph.display_vertices(0, 2, 0, 2);

	MSTree mstree(&(graph.vertex_pool[0]), &graph);
	MBDMSTree mbdtree(&mstree, image);
	for (int w = 0; w < width; w++) {
		int v_id = w;
		mbdtree.set_vertex_seed(v_id);
		v_id = (height-1) * width + w;
		mbdtree.set_vertex_seed(v_id);
	}
	for (int h = 0; h < height; h++) {
		int v_id = h *width;
		mbdtree.set_vertex_seed(v_id);
		v_id = h * width + width - 1;
		mbdtree.set_vertex_seed(v_id);
	}
	mbdtree.compute_MBD();

	vector<unsigned char> salmap;
	for (int h = 0;h < height; h++) {
		for (int w = 0;w < width; w++) {
			int ix = h * width + w;
			for (int c = 0;c < 3; c++) {
				salmap.push_back((unsigned char)mbdtree.get_min_barrier_dist(ix));
			}
			salmap.push_back((unsigned char)255);
		}
	}
	string savename = "salmap.png";
	lodepng::encode(savename, salmap, width, height);

	//Graph g(10);
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

	/*
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
	*/
	return 0;
}
