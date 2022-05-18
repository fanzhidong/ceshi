#include "game.h"
game::game(int wid, int height) :wid(wid), height(height)
{
	initgraph(wid, height);
	px = 40;
	ving.resize(3);
	loadimage(&ving[0], _T("res/1.jpg"), px, px);
	loadimage(&ving[1], _T("res/2.jpg"), px, px);
	loadimage(&ving[2], _T("res/3.jpg"), px, px);
	grade = 0;
	plan = { wid / 2, height - px * 2 };   //�ɻ����м�
}
game::~game()
{
	closegraph();
}
void game::init()
{
	grade = 0;
	plan = { wid / 2, height - px * 2 };   //�ɻ����м�
	bullet.getBullet().clear();
	plan.getEnemyPlan().clear();
}
//���ɵл�
void game::spawnEnemy()
{
	static int x = 0;  // �л�������
	if (x >= 20)
	{
		if (plan.getEnemyPlan().size() < 5)
		{
			plan.getEnemyPlan().push_back(node(rand() % (wid - px) + px / 2, 0));
		}
		x = 0;
	}
	x++;
}
//�ƶ�
void game::control()
{
	int speed = 4;
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('w'))
	{
		if (plan.getPlan().y > px / 2)
			plan.getPlan().y -= speed;
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('d'))
	{
		if (plan.getPlan().x < wid - px)
			plan.getPlan().x += speed;
	}
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('a'))
	{
		if (plan.getPlan().x > 0)
			plan.getPlan().x -= speed;
	}
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('s'))
	{
		if (plan.getPlan().y < height - px)
			plan.getPlan().y += speed;
	}
	if (_kbhit())
	{
		if (_getch() == (VK_SPACE))
		{
			bullet.spwnBullet(plan.getPlan());
		}
	}
}
//�ɻ�ײ�ӵ�
bool game::bulletCollide(airplan& plan, int px)
{
	for (auto p = bullet.getBullet().begin(); p != bullet.getBullet().end(); p++)
	{
		for (auto en = plan.getEnemyPlan().begin(); en != plan.getEnemyPlan().end(); en++)
		{
			if (plan.planeColide(*p, *en, px))
			{
				bullet.getBullet().erase(p);
				plan.getEnemyPlan().erase(en);
				return true;
			}
		}
	}
	return false;
}
//��Ϸ�Ƿ����
bool game::isGameOver()
{
	for (auto p : plan.getEnemyPlan())
	{
		if (plan.planeColide(plan.getPlan(), p, px))
		{
			return true;
		}
	}
	return false;
}
void game::draw()
{
	BeginBatchDraw();
	cleardevice();
	for (auto p : plan.getEnemyPlan())
	{
		putimage(p.x, p.y, &ving[0]);
	}
	for (auto p : bullet.getBullet())
	{
		putimage(p.x, p.y, &ving[2]);
	}
	putimage(plan.getPlan().x, plan.getPlan().y, &ving[1]);
	wsprintf(tc, _T("score:%d"), grade);
	outtextxy(wid / 2, px, tc);
	EndBatchDraw();
}
//ˢ��
void game::updata(airplan& plan, Bullet& bullet)
{
	for (auto& p : plan.getEnemyPlan())
	{
		p.y += 2;
	}
	for (auto& p : bullet.getBullet())
	{
		p.y -= 8;
	}
	if (bulletCollide(plan, px))
		grade++;
	plan.destoryEnemy(height);
	bullet.dextoryBullet();
	spawnEnemy();
}
//��ʼ��Ϸ
void game::start()
{
	while (true)
	{
		updata(plan, bullet);
		control();
		draw();
		if (isGameOver())
		{
			if (MessageBox(GetForegroundWindow(), _T("�Ƿ�ʼ�µ���Ϸ"), _T("��Ϸ����"), MB_YESNO) == IDYES)
			{
				init();
			}
			else
				break;
		}
		Sleep(20);
	}
}
