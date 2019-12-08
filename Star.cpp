#include "Star.h"

using namespace std;

void gotoxy(int x, int y)
{
	COORD Pos = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

Star::Star(int x, int y)
{
	m_iX = x;
	m_iY = y;
}
void Star::setSpeed(int speed)
{
	m_iSpeed = speed;
}
void Star::StarFall(int &x, int &y) // x, y �� ���� ��ġ
{	
	y++;
	gotoxy(x, y);
	cout << '@' << endl;
	
} //����� ������ ���� ��ǥ�� �̵�
void Star::MakeStar(int &x, int &y) 
{
	srand(time(NULL));
	int x1 = rand() % (m_iX - 2);
	x = x1 + 1;  //ó�� �����Ǵ� x�� ��ġ
	y = 1;  //ó�� �����Ǵ� y�� ��ġ
	
} //�� ���� ��, ���� ��ġ�� ���(���� ���κ�)

void Star::StarErase(int &x, int &y) //x, y�� ���� ��ġ
{
	if (y > 1)
	{
		gotoxy(x, y - 1);
		cout << " " << endl;
		
		gotoxy(x, y - 1);
		cout << "\0" << endl; //������ �ڸ��� �ι��� ����		
	}	
	if (y == m_iY - 1)
	{
		gotoxy(x, y - 1);
		cout << " " << endl;
		
		gotoxy(x, y - 1);
		cout << "\0" << endl;

		Sleep(m_iSpeed);

		gotoxy(x, y);
		cout << " " << endl;

		gotoxy(x, y);
		cout << "\0" << endl;
		
	}
}//���� ��ġ�� �� �κ��� ����� �Լ�
void Star::StarManager()
{
	for(int i = 0; i < m_iX; i++)
	{	
		
		if (pos->s_iY[i] != 1 || pos->s_iY[i] == m_iY - 1)
		{
			 MakeStar(pos->s_iX[i], pos->s_iY[i]);
			 Sleep(m_iSpeed);
		}
		for(int j = 0 ;j < m_iY - 1; j++)
		{
		    
		     StarFall(pos->s_iX[j], pos->s_iY[j]);
			 StarErase(pos->s_iX[j], pos->s_iY[j]);
			 
			 Sleep(m_iSpeed);
			
		}
		    
	}
	
}
/*
���� �����Ǵ� ������ ������
�ð����� ���� ����
�ð����� ���� ��ġ���� ������
���� ������ ������ x��ǥ�� ���ϸ� �ȵ�
���� �����ϸ� y��ǥ �ʱ�ȭ, x��ǥ ����
*/
Star::~Star()
{
	delete[] pos;
}
/*
������2 :
������3 :
�� �������� ����߸��� �����?
���� �� �ϳ��� ������ �������߸� ���� ���� ������
���� ���ļ� ������
*/