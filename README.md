# Real-Time Salient Object Detection with a Minimum Spanning Tree
<p align="center">
  <img src="0027.png" width="350" title="input_image">
  <img src="salmap.png" width="350" alt="output_image">
</p>

This is a re-implementation of a paper published in CVPR 2016. Given an input image (see the left figure), the algorithm can produce a gray-scale map (see the right figure) that indicates the most salient objects in the input.

Notice that I have only implemented the core of the algorithm, but have not developed the post-processing in the MBD-MST paper. If you want to use this code, please refer to 'main()' function in 'test.cpp'. Good luck and have fun.

By the way, if you use the code, please cite the following paper:
```
@inproceedings{Tu2016Real,
  title={Real-Time Salient Object Detection with a Minimum Spanning Tree},
  author={Tu, Wei Chih and He, Shengfeng and Yang, Qingxiong and Chien, Shao Yi},
  booktitle={IEEE Conference on Computer Vision & Pattern Recognition},
  year={2016},
}
```
