#include "Star.h"

using namespace std;

int main()
{
	Star a(20, 15);
	a.setSpeed(100);
	/*
	for (int i = 0; i < 20; i++)
	{
		cout << "-";
		gotoxy(i, 15);
		cout << "-";
		gotoxy(i, 0);
	} //���� �� ĭ. ���žƴ�
	*/
	a.StarManager();

	//fork() �Լ��� ���ؼ� �˾ƺ���
	//���� ������ ������ ���
}