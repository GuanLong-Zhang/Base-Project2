# include<iostream>
using namespace std;

class building;

//������Ԫ
class goodgay
{
public:
	building * g;
	goodgay();      //�������� ���ⶨ��
	void visit();
	void visit1();   
};


class building
{
	friend void goodgay::visit1();   //friend���γ�Ա�����������Ϳ��Է���˽�������ˣ�������Ҫע��goodgay�ĳ�Ա���������ȶ���
	//friend class goodgay;   //friend������������������Ϳ��Է���˽��������
	friend void goodfirend(building* building);   //friend����ȫ�ֺ����������������Ϳ��Է���˽��������
public:
	string keting;
	building()   //���캯������ֵ
	{
		keting = "����";
		woshi = "����";
	}
private:
	string woshi;

};

goodgay::goodgay()   //���캯��
{
	g = new building;   //�ڶ��������ڴ�ռ�
}

void goodgay::visit() //����ŵ�building֮�󣬲�Ȼ����ʾʹ����δ�����building
{
	cout << "�û�����ȥ���ʽ��������еĹ������ԣ�" << g->keting << endl;

	//cout << "�û�����ȥ���ʽ��������е�˽�����ԣ�" << g->woshi << endl;     //Ҫ���ʱ��뽫�û������Ϊ��Ԫ��
}

//��Ա��������Ԫ����
void goodgay::visit1()
{
	cout << "��Ա����ȥ���ʽ��������еĹ������ԣ�" << g->keting << endl;

	cout << "��Ա����ȥ���ʽ��������е�˽�����ԣ�" << g->woshi << endl;
}

//ȫ�ֺ�������Ԫ����
void goodfirend(building* building)
{
	cout << "ȫ�ֺ����Թ������Խ��з��ʣ�" << building->keting << endl;

	cout << "ȫ�ֺ�����˽�����Խ��з��ʣ�" << building->woshi<< endl;
}

void test11()
{
	building a;
	goodfirend(&a);
}

void test12()
{
	goodgay b;
	b.visit();
}

void test13()
{
	goodgay c;
	c.visit1();
}

//int main()
//{
//	//test11();
//	//test12();
//	//test13();
//
//	system("pause");
//	return 0;
//}