#pragma once
#include"myhelp.h"
class airplan
{
	node Plan;   //�Լ��ķɻ�
	int px;     //�ɻ���С
	list<node> enemyPlan;  //�л�
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
	bool planeColide(node& v1, node& v2, int px);  //�ɻ���ײ
	void destoryEnemy(int height);
};
