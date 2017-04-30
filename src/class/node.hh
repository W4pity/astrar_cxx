#pragma once
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