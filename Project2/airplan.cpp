#include "airplan.h"
airplan::airplan(int x, int y) :Plan(x, y)
{
	px = 40;
}
airplan::airplan() {}
bool airplan::planeColide(node& v1, node& v2, int px)
{
	int x = abs(v1.x - v2.x);
	int y = abs(v1.y - v2.y);
	return y < px&& x < px;
}
void airplan::destoryEnemy(int height)
{
	for (auto it = enemyPlan.begin(); it != enemyPlan.end(); it++)
	{
		if (it->y > height)
		{
			enemyPlan.erase(it);//删除it当前位置的数据
			break;
		}
	}
}
