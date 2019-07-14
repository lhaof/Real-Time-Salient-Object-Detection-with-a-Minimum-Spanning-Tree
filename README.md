# Real-Time Salient Object Detection with a Minimum Spanning Tree
This is a re-implementation of a paper published in CVPR 2016. Given an input image (see the left figure), the algorithm can produce a gray-scale map (see the right figure) that indicates the most salient objects in the input.

<p align="center">
  <img src="0027.png" width="350" title="input_image">
  <img src="salmap.png" width="350" alt="output_image">
</p>

Notice that I have only implented the core of the algorithm, but have not developed the post-processing in the MBD-MST paper. If you want to use this code, please refer to 'main()' function in 'test.cpp'. Good luck and have fun.
