#pragma once
#include"airplan.h"
#include"bullet.h"
class game
{
	int wid;
	int height;
	int grade;
	int px;   //ͼƬ��С
	TCHAR tc[30];  //����������ʾ
	vector<IMAGE> ving;  //ͼƬ
	airplan plan;
	Bullet bullet;
public:
	game(int wid, int height);
	~game();
	//��ʼ��
	void init();
	//���ɵл�
	void spawnEnemy();
	//�ƶ�
	void control();
	//�ɻ�ײ�ӵ�
	bool bulletCollide(airplan& plan, int px);
	//��Ϸ�Ƿ����
	bool isGameOver();
	void draw();
	//ˢ��
	void updata(airplan& plan, Bullet& bullet);
	//��ʼ��Ϸ
	void start();
};
