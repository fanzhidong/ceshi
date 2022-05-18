#pragma once
#include"myhelp.h"
#include"airplan.h"
class Bullet
{
	list<node> bullet;  //子弹节点
public:
	list<node>& getBullet()
	{
		return bullet;
	}
	void spwnBullet(node& plan);  //发射子弹
	void dextoryBullet(); //销毁子弹
};
