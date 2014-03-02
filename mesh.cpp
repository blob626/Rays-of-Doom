#include "mesh.h"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
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

  getline(file, unwanted);

  std::string line;

  std::vector<Vector3> verts;

  while(!file.eof())
    {
      getline(file, line);
      std::istringstream temp(line, std::istringstream::in);
      char type;
      temp >> type;
      if(type == 'v')
	{
	  Vector3 vec;
	  temp >> vec;
	  verts.push_back(vec);
	}
      else if(type == 'f')
	{
	  int v1, v2, v3, v4 = -1;
	
	  temp >> v1 >> v2 >> v3 >> v4;
	  if(v4 != -1)
	    {
	      faces.emplace_back(verts[v1], verts[v2], verts[v3]);
	    }
	  else
	    {
	      faces.emplace_back(verts[v1], verts[v4], verts[v3]);
	      faces.emplace_back(verts[v1], verts[v3], verts[v2]);
	    }
	}
    }
  file.close();
}
