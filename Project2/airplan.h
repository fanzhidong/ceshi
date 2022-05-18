#pragma once
#include"myhelp.h"
class airplan
{
	node Plan;   //自己的飞机
	int px;     //飞机大小
	list<node> enemyPlan;  //敌机
public:
	airplan();
	airplan(int x, int y);
	list<node>& getEnemyPlan()
	{
		return enemyPlan;
	}
	node& getPlan()
	{
		return Plan;
	}
	bool planeColide(node& v1, node& v2, int px);  //飞机碰撞
	void destoryEnemy(int height);
};
