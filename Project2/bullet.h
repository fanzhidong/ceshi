#pragma once
#include"myhelp.h"
#include"airplan.h"
class Bullet
{
	list<node> bullet;  //�ӵ��ڵ�
public:
	list<node>& getBullet()
	{
		return bullet;
	}
	void spwnBullet(node& plan);  //�����ӵ�
	void dextoryBullet(); //�����ӵ�
};
