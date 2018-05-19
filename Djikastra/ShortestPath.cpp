//
//  ShortestPath.cpp
//  Djikastra
//
//  Created by Vijay Vishwakarma on 5/18/18.
//  Copyright © 2018 Vijay Vishwakarma. All rights reserved.
//

#include <iostream>

class ShortestPath {
  public:
    void vertices(int* v); //list of vertices in G(V,E).
    int* path(int u, int w);//find shortest path between u-w and returns the sequence of vertices representing
                // shorest path u-v1-v2-…-vn-w.
    int path_size(int u, int w); //return the path cost associated with the shortest path.
};
