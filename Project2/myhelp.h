#pragma once
#include<easyx.h>
#include<conio.h>
#include<list>
#include<vector>
#include<iostream>
using namespace std;
struct node
{
	int x, y;
	node(int x, int y) :x(x), y(y) {}
	node() { x = 0; y = 0; }
};
