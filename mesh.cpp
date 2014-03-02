#include "mesh.h"

#include <fstream>
#include <sstream>
#include <string>

#include "vector3.h"

Mesh::Mesh()
{

}

Mesh::Mesh(const char* file)
{
  readFile(file);
}

void Mesh::readFile(const char* filename)
{
  int numVerts, numFaces;
  
  std::ifstream file(filename);
  std::string unwanted;
  file >> unwanted >> std::ws;
  getline(file, unwanted);
  while(unwanted[0] == '#')
    {
      std::cout << unwanted << std::endl;
      getline(file, unwanted);
    }
  std::istringstream convert(unwanted, std::istringstream::in);
  convert >> numVerts >> numFaces >> unwanted;
  Vector3* verts = new Vector3[numVerts];

  for(int i = 0; i < numVerts; ++i)
    {
      file >> verts[i] >> std::ws;
    }
  for(int i = 0; i < numFaces; ++i)
    {
      int type;
      std::string line;
      getline(file, line);
      std::istringstream convert(line, std::istringstream::in);
      convert >> type;

      // check if the objects is a triangle of a quad
      if(type == 3)
	{
	  int v1, v2, v3;
	  convert >> v1 >> v2 >> v3;
	  Triangle tri(verts[v1],verts[v2],verts[v3]);
	  faces.push_back(tri);
	}
      if(type == 4)
	{
	  int v1, v2, v3, v4;
	  convert >> v1 >> v2 >> v3 >> v4;
	  Triangle tri1(verts[v1], verts[v3], verts[v2]);
	  Triangle tri2(verts[v1], verts[v4], verts[v3]);
	  faces.push_back(tri1);
	  faces.push_back(tri2);
	}
    }
  file.close();
}
