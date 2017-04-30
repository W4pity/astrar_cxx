#include <vector>
#include <iostream>
#include "class/node.hh"
#include "class/astar.hh"


int main()
{
  int schema[10][10]= {{1,1,1,1,1,1,1,1,1,1},
                       {1,1,1,1,1,1,1,1,1,1},
                       {1,1,5,1,1,1,1,1,1,1},
                       {1,1,1,1,1,1,1,1,1,1},
                       {1,1,1,1,100,100,100,100,100,0},
                       {1,1,1,1,1,1,1,1,1,1},
                       {1,1,1,1,1,1,1,1,1,1},
                       {1,1,1,1,1,1,1,1,1,1},
                       {1,1,1,1,1,1,1,1,1,1},
                       {1,1,1,1,1,1,1,1,1,1}};

  std::vector<std::vector<Node>> map;
  for (int i = 0; i < 10; ++i)//column
  {
    map.push_back(std::vector<Node>());
    for (int j = 0; j < 10; ++j)//line
    {
     // if (schema[i][j] == 1)
      //{
        map[i].push_back(Node{i, j, schema[i][j]});
      //}
      
    }
  }
  Astar astar;
  std::vector<Node> v = astar.Run(map[0][0], map[9][9], map);
  for (int i = 0; i < v.size(); ++i)
  {
      schema[v[i].x][v[i].y] = 0;
  }

  for (int i = 0; i < 10; ++i)
  {
    for (int j = 0; j < 10; ++j)
    {
      std::cout << schema[i][j] << " ";
    }
    std::cout << std::endl;
  }
  //std::cout << r.x << " " << r.y << std::endl;
  return 0;
}