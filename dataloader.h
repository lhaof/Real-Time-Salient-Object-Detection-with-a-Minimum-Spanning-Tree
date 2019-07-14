#include <cassert>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

class DataLoader {
public:
	DataLoader(const string& dataset, const string& split, bool is_dense) {
		assert(dataset == "DAVIS" || dataset == "FBMS");
		if (dataset == "DAVIS") {
			assert(split == "train" || split == "val");
		}
		if (dataset == "FBMS") {
			assert(split == "train" || split == "test");
		}
		string list_path;
		if (dataset == "DAVIS") {
			list_path = "/mnt/nvme/video_saliency/DAVIS/ImageSets/480p/" + split + ".txt";
		} else if (dataset == "FBMS") {
			
		}
	}
};