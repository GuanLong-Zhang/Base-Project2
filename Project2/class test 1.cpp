//���Բ�Ĺ�ϵ
# include<iostream>
using namespace std;
# include "point.h"
# include"circle.h"

//�����������class���з��ļ���д  .h�ļ��з�����  .cpp�зŹ���ʵ��

//class circle
//{
//private:
//	int x;  //Բ��
//	int y;
//	int r;  //�뾶
//public:
//	void set(int a, int b, int c)
//	{
//		x = a;
//		y = b;
//		r = c;
//	}
//	int getx()
//	{
//		return x;
//	}
//	int gety()
//	{
//		return y;
//	}
//	int getr()
//	{
//		return r;
//	}
//};

//class point
//{
//private:
//	int x;   //�������
//	int y;
//public:
//	void set(int a, int b)
//	{
//		x = a;
//		y = b;
//	}
//	int getx()
//	{
//		return x;
//	}
//	int gety()
//	{
//		return y;
//	}
//};

string panduan(circle a, point b)
{
	double juli = sqrt(pow((a.getx() - b.getx()),2) + pow((a.gety() - b.gety()),2));   //pow(3,2)��ʾ3��2�η�
	if (a.getr() == juli)
	{
		return "����Բ��";
	}
	else if (a.getr() > juli)
	{
		return "����Բ��";
	}
	else
	{
		return "����Բ��";
	}
}

//int main()
//{
//	circle c;
//	point  p;
//	c.set(0, 0, 5);   //����Բ�� x y �뾶r
//	p.set(3, 4);      //���������� x y  (1,1) (3,4) (5,5)
//	cout << "Բ������Ϊ��" << "<"<<c.getx() << "," << c.gety()<<">" << endl;
//	cout << "Բ�İ뾶Ϊ��" << c.getr() << endl;
//	cout << "�������Ϊ��" << "<" << p.getx() << "," << p.gety() << ">" << endl;
//	cout<<"����Բ�Ĺ�ϵ��"<<panduan(c, p)<<endl;
//
//}