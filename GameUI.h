#ifndef GAMEUI_H
#define GAMEUI_H
#include "Common.h"

class GameUI
{
private:
	
public:
	void showMain();                   //��ʾUI Main����
	void showTetris(bool ** UIArray,int s);  //��ʾTetris��Ϸ����
	void updateUI();                   //ˢ����Ļ
};

#endif