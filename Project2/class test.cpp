# include<iostream>
using namespace std;

//���һ����������
class Cube
{
private:
	int ml;
	int mw;
	int mh;
public:
	void set(int a, int b, int c)
	{
		ml = a;
		mw = b;
		mh = c;
	}
	int getml()
	{
		return ml;
	}
	int getmw()
	{
		return mw;
	}
	int getmh()
	{
		return mh;
	}
	int area()
	{
		return 2 * ml * mw + 2 * ml * mh + 2 * mw * mh;
	}
	int volume()
	{
		return ml * mw * mh;
	}
	string compare(int a, int b)
	{
		if (a == b)
		{
			return "���" ;
		}
		else
		{
			return "�����" ;
		}
	}
	//��Ա����ֻ��Ҫ����һ������
	bool iscompare(Cube a)
	{
		if (mh == a.getmh() && ml == a.getml() &&  mw == a.getmw())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

string compare(int a, int b)
{
	if (a == b)
	{
		return "���";
	}
	else
	{
		return "�����";
	}
}

//ȫ�ֺ�����Ҫ������������
bool iscompare(Cube a, Cube b)   //�ж������������Ƿ���� �����жϳ� �� �� �Ƿ����
{
	if (a.getmh() == b.getmh() && a.getml() == b.getml() && a.getmw() == b.getmw())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//int main()
//{
//	Cube a,b;
//	a.set(3, 4, 5);
//	b.set(3, 4, 5);
//	int aa = a.area();
//	int av = a.volume();
//	int ba = b.area();
//	int bv = b.volume();
//	cout<<"a�����Ϊ��"<<aa<<endl;
//	cout<<"a�����Ϊ��"<<av<<endl;
//	cout << "b�����Ϊ��" <<ba<< endl;
//	cout << "b�����Ϊ��" <<bv<< endl;
//	
//	cout << "ȫ�ֺ����Ƚ�" << endl;
//	bool ret = iscompare(a, b);
//	if (ret)
//	{
//		cout << "a��b���" << endl;
//	}
//	else
//	{
//		cout << "a��b�����" << endl;
//	}
//	cout << "a��b������Ƿ����:" << compare(aa, ba) << endl;
//	cout << "a��b������Ƿ����:" << compare(av, bv) << endl;
//
//	cout << "��Ա�����Ƚ�" << endl;
//	bool ret1 = a.iscompare(b);
//	if (ret1)
//	{
//		cout << "a��b���" << endl;
//	}
//	else
//	{
//		cout << "a��b�����" << endl;
//	}
//	cout << "a��b������Ƿ����:"<< a.compare(aa, ba)<<endl;
//	cout << "a��b������Ƿ����:" << a.compare(av, bv) << endl;
//
//	system("pause");
//	return 0;
//}
