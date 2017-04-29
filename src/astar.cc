#include <vector>
#include <tuple>
#include <iostream>
#include <cmath>
#include <algorithm> 

class Node
{
  public:
    Node(int x, int y, int p);
    int g = 0;
    int f;
    int x;
    int y;
    Node *parent = nullptr;
  private:
};

Node::Node(int x, int y, int p)
:x(x), y(y), g(p)
{}


bool operator==(Node a, Node b)
{
  return a.x == b.x && a.y == b.y;
}

bool operator==(Node a, std::vector<int> v)
{
  return a.x == v[0] && a.y == v[1];
}

bool exist(std::vector<Node*> v, Node e)
{
  for (int i = 0; i < v.size(); i++)
  {
    if (e == *v[i])
      return true;
  }
  return false;
}

bool exist(std::vector<std::vector<int>> v, Node e)
{
  for (int i = 0; i < v.size(); i++)
  {
    if (e == v[i])
      return true;
  }
  return false;
}


/*
function construct_path(node)
  path = set containing node
  while node.parent exists
    node = node.parent
    add node to path
  return path
*/


void display_map(std::vector<std::vector<std::tuple<int,int>>> map)
{
  for (int i = 0; i < 10; ++i)//column
  {
  
    for (int j = 0; j < 10; ++j)//line
    {
        std::cout << std::get<0>(map[i][j]) << " " ;
    }
    std::cout << std::endl;
  } 
  std::cout << std::endl;
  std::cin.get();
}

std::vector<Node> construct_path(Node* g)
{
  std::cout << g->parent;
  Node *tmp = g;
  std::vector<Node> v;
  while (tmp)
  {
    v.push_back(*tmp);
    tmp = tmp->parent;
  }

  std::reverse(v.begin(),v.end());
  for (int i = 0; i < v.size(); ++i)
  {
    std::cout << "(" << v[i].x << v[i].y << ")";
  }
  std::cout << std::endl;
  return v;
}

std::vector<std::vector<int>> neighbors(Node n, std::vector<std::vector<Node>> map)
{
  //int coord[2];
  //std::vector<Node*> *v = new std::vector<Node*>();
/*  if (n.x-1 >= 0 && n.y-1 >= 0)
    v->push_back(std::vector<int> {n.x-1, n.y-1});

  if (n.x-1 >= 0)
    v->push_back(map[n.x-1][n.y]);

  if (n.x-1 >= 0 && n.y+1 < map[0]->size())
    v->push_back(map[n.x-1][n.y+1]);

  if (n.y-1 >= 0)
    v->push_back(&map[n.x][n.y-1]);

  if (n.y+1 < map[0]->size())
    v->push_back(map[n.x][n.y+1]);

  if (n.x+1 < map.size() && n.y-1 >= 0)
    v->push_back(map[n.x+1][n.y-1]);

  if (n.x+1 < map.size())
    v->push_back(map[n.x+1][n.y]);

  if (n.x+1 < map.size() && n.y+1 < map[0].size())
    v->push_back(map[n.x+1][n.y+1]);*/
  std::vector<std::vector<int>> v; 
  if (n.x-1 >= 0 && n.y-1 >= 0)
    v.push_back(std::vector<int> {n.x-1, n.y-1});

  if (n.x-1 >= 0)
    v.push_back(std::vector<int> {n.x-1, n.y});

  if (n.x-1 >= 0 && n.y+1 < map[0].size())
    v.push_back(std::vector<int> {n.x-1, n.y+1});

  if (n.y-1 >= 0)
    v.push_back(std::vector<int> {n.x, n.y-1});

  if (n.y+1 < map[0].size())
    v.push_back(std::vector<int> {n.x,n.y+1});

  if (n.x+1 < map.size() && n.y-1 >= 0)
    v.push_back(std::vector<int> {n.x+1, n.y-1});

  if (n.x+1 < map.size())
    v.push_back(std::vector<int> {n.x+1, n.y});

  if (n.x+1 < map.size() && n.y+1 < map[0].size())
    v.push_back(std::vector<int> {n.x+1, n.y+1});
  return v;
}


int heuristic(Node s, Node g)
{
  return abs(s.x-g.x) + abs(s.y-g.y);
}


void display_open(std::vector<Node> v)
{
  for (int i = 0; i < v.size(); ++i)
  {
    std::cout << "(" << v[i].x << "," << v[i].y << ")" ;
  }
  std::cout << std::endl;
}


std::vector<Node> Astar(Node start, Node goal, std::vector<std::vector<Node>> map)
{

  std::vector<std::vector<std::tuple<int,int>>> map_debug;
  for (int i = 0; i < 10; ++i)//column
  {
    map_debug.push_back(std::vector<std::tuple<int,int>>());
    for (int j = 0; j < 10; ++j)//line
    {
        map_debug[i].push_back(std::make_tuple(0,0));
    }
  } 

  map_debug[start.x][start.y] = std::make_tuple(1,0);
  std::vector<Node*> open_list;
  open_list.push_back(&start);
  std::vector<Node*> closed_list;
  //map[start.x][start.y].g = 0;
  //map[start.x][start.y].f = heuristic(start, goal);
  while (open_list.size() != 0)
  {
//    display_open(open_list);
    display_map(map_debug);
    Node *current = open_list[0];
    // find the lowest f
    for (int i = 0; i < open_list.size(); i++)
    {
      if (open_list[i]->f < current->f){
        current = open_list[i];
        

      }
    }
    map_debug[current->x][current->y] = std::make_tuple(1,current->f);
    if (*current == goal)
      return construct_path(current);
    //remove current element
    for (int i = 0; i < open_list.size(); i++)
    {
      if (*open_list[i] == *current)
      {
        open_list.erase (open_list.begin()+i);;
      }
    }
    /*******************/
    closed_list.push_back(current);
    map_debug[current->x][current->y] = std::make_tuple(3,current->f);
    for (auto neighborint : neighbors(*current, map))//neighbor vector vector int
    {
      Node *neighbor = &map[neighborint[0]][neighborint[1]]; //ref on node of map
      //find it in closed_list
      if (exist(closed_list, *neighbor))//or not traversable
      {
        continue;
      }
      if (neighbor->f < current->f || !exist(open_list, *neighbor))
      { 
        neighbor->f = neighbor->g + heuristic(*neighbor, goal);
        neighbor->parent = current;

        if (!exist(open_list, *neighbor)){
          open_list.push_back(neighbor); 
          map_debug[neighbor->x][neighbor->y] = std::make_tuple(1,neighbor->f);
        }
      }

    }
  }
}

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
  std::vector<Node> v = Astar(map[0][0], map[9][9], map);
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