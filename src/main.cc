#include <vector>
#include <iostream>
#include "class/node.hh"
#include "class/astar.hh"
#include <cstdlib>

std::vector<std::vector<int>> genMat()
{
  std::vector<std::vector<int>> v;
  for (int i = 0; i < 100; ++i)
  {
    v.push_back(std::vector<int>());
    for (int j = 0; j < 100; ++j)
    {
      int r = rand() % 2;
      if (r == 0)
        v[i].push_back(1);
      else
        v[i].push_back(100);
    }
  }
  return v;
}

void display(std::vector<std::vector<int>> schema)
{
    std::vector<std::vector<Node>> map;
  for (int i = 0; i < schema.size(); ++i)//column
  {
    map.push_back(std::vector<Node>());
    for (int j = 0; j < schema.size(); ++j)//line
    {
     // if (schema[i][j] == 1)
      //{
        map[i].push_back(Node{i, j, schema[i][j]});
      //}
      
    }
  }
  Astar astar;
  std::vector<std::vector<int>> v = astar.Run(map[0][0], map[99][99], map);
  for (int i = 0; i < v.size(); ++i)
  {
      schema[v[i][0]]   [v[i][1]] = 0;
  }

  for (int i = 0; i < map.size(); ++i)
  {
    for (int j = 0; j < map[0].size(); ++j)
    {
      if (schema[i][j] == 100)
      {
        std::cout << '#' << "";
      }
      else if (schema[i][j] == 0)
      {
        std::cout << " \e[32;1m.\e[31;0m" << "";
      }
      else
        std::cout << " " << "";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << std::endl;
}

int main()
{
 

  display(genMat());
  display(genMat());
  display(genMat());
  display(genMat());
  //std::cout << r.x << " " << r.y << std::endl;
  return 0;
}