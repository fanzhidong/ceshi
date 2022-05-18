#include "bullet.h"

void Bullet::spwnBullet(node& plan)  //发射子弹
{
	bullet.push_back(node(plan.x, plan.y + 10));
}
void Bullet::dextoryBullet()  //销毁子弹
{
	for (auto it = bullet.begin(); it != bullet.end(); it++)
	{
		if (it->y < 0)
		{
			bullet.erase(it);
			break;
		}
	}
}
