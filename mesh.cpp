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
  
  if(unwanted[0] == '#')
    {
      std::cout << "object file comments:" << std::endl;
      do
	{
	  std::cout << unwanted << std::endl;
	  getline(file, unwanted);
	}
      while(unwanted[0] == '#');
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
      int v1, v2, v3, v4;
      if(type == 3)
	{
	  convert >> v1 >> v2 >> v3;
	  
	  faces.emplace_back(verts[v1], verts[v2], verts[v3]);
	}
      if(type == 4)
	{
	  convert >> v1 >> v2 >> v3 >> v4;
	  
	  faces.emplace_back(verts[v1], verts[v3], verts[v2]);
	  faces.emplace_back(verts[v1], verts[v4], verts[v3]);
	}
    }
  file.close();
}
