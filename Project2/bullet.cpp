#include "bullet.h"

void Bullet::spwnBullet(node& plan)  //�����ӵ�
{
	bullet.push_back(node(plan.x, plan.y + 10));
}
void Bullet::dextoryBullet()  //�����ӵ�
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
