#ifndef VOXEL_H_INCLUDED
#define VOXEL_H_INCLUDED

using namespace std;

struct Voxel {
  float r,g,b; // Colors
  float a; // Transparency
  bool isOn; // Included or not
};

#endif // VOXEL_H_INCLUDED
