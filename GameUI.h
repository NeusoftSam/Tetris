#ifndef GAMEUI_H
#define GAMEUI_H
#include "Common.h"

class GameUI
{
private:
	
public:
	void showMain();                   //显示UI Main函数
	void showTetris(bool ** UIArray,int s);  //显示Tetris游戏界面
	void updateUI();                   //刷新屏幕
};

#endif