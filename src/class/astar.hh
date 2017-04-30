#pragma once
#include <vector>
#include "node.hh"

class Astar
{
public:
    void display_open(std::vector<Node> v);
    int heuristic(Node s, Node g);
    std::vector<std::vector<int>> neighbors(Node n, std::vector<std::vector<Node>> map);
    std::vector<Node> construct_path(Node* g);
    void display_map(std::vector<std::vector<std::tuple<int,int>>> map);
    bool exist(std::vector<std::vector<int>> v, Node e);
    bool exist(std::vector<Node*> v, Node e);
    std::vector<Node> Run(Node start, Node goal, std::vector<std::vector<Node>> map);
private:
};
bool operator==(Node a, std::vector<int> v);
bool operator==(Node a, Node b);
