# include<iostream>
using namespace std;

//��̳У�ʵ�ʿ����в�����ʹ�ã�
class base2
{
public:
	int a;
	base2()   //���캯������ֵ
	{
		a = 100;
	}
};

class base3
{
public:
	int a;
	int b;
	base3()   
	{
		a = 150;
		b = 200;
	}
};

//��̳�
class son8 :public base2, public base3
{
public:
	int c;
	int d;
	son8()
	{
		c = 300;
		d = 400;
	}
};

void test41()
{
	son8 s;
	cout << "sizeof s = " << sizeof(s) << endl;   //����base2,base3�е�����
	cout << "s.base2::a = " << s.base2::a << endl;   //������������Ҫ��������
	cout << "s.base3::a = " << s.base3::a << endl;
}

//���μ̳�
class animal
{
public:
	int age;

};

class sheep :virtual public animal    //virtual ��̳�
{

};

class tuo :virtual public animal
{

};

class sheeptuo :public sheep, public tuo
{

};

void test42()
{
	sheeptuo st;
	//������������ͬ�����ݣ���Ҫ������������
	st.sheep::age = 18;
	st.tuo::age = 28;
	cout << "st.sheep::age = " << st.sheep::age << endl;
	cout << "st.tuo::age = " << st.tuo::age << endl;
	//������̳еķ�ʽ���Խ����Դ�˷ѵ�����
	cout << "st.age = " << st.age << endl;

}

//int main()
//{
//	//test41();
//	test42();
//
//	system("pause");
//	return 0;
//}