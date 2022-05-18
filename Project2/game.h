#pragma once
#include"airplan.h"
#include"bullet.h"
class game
{
	int wid;
	int height;
	int grade;
	int px;   //图片大小
	TCHAR tc[30];  //输入文字提示
	vector<IMAGE> ving;  //图片
	airplan plan;
	Bullet bullet;
public:
	game(int wid, int height);
	~game();
	//初始化
	void init();
	//生成敌机
	void spawnEnemy();
	//移动
	void control();
	//飞机撞子弹
	bool bulletCollide(airplan& plan, int px);
	//游戏是否结束
	bool isGameOver();
	void draw();
	//刷新
	void updata(airplan& plan, Bullet& bullet);
	//开始游戏
	void start();
};
