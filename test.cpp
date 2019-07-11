#include <iostream>

#include "ADJ.h"

using namespace std;

int main() {
	int h,w;
	cin >> h >> w;
	int vertex_num = h*w;
	GridGraph graph(h, w);
	graph.display_vertices();
	return 0;
}