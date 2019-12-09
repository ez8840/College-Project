#pragma once
#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

void gotoxy(int x, int y);

struct Starpos
{
	int s_iX[20];
	int s_iY[20];
};

class Star
{
	Starpos *pos = new Starpos;// ���� ��ġ�� ������ �迭 ������
	int m_iX; //������ ����
	int m_iY; //������ ����
	int m_iSpeed; //���� �������� �ӵ�
public:
	Star(int x, int y);
	void setSpeed(int speed);
	// x, y�� ��ġ�� ������������ �迭 ����
	void StarFall(int &x, int &y);
	void MakeStar(int &x, int &y);
	void StarErase(int &x, int &y);
	void StarManager();
	~Star();
};