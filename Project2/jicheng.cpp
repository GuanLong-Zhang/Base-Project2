#include<iostream>
using namespace std;

//��ͨʵ��

//java����
//class java
//{
//public:
//	void header()
//	{
//		cout << "��ҳ�������Σ���¼��ע��......(����ͷ��)" << endl;
//	}
//	void footer()
//	{
//		cout << "�������ģ�����������վ�ڵ�ͼ......(����β��)" << endl;
//	}
//	void lefter()
//	{
//		cout << "java,python,c++,c......(�������)" << endl;
//	}
//	void content()
//	{
//		cout << "java�γ�" << endl;
//	}
//};

//pythonҳ��
//class python
//{
//public:
//	void header()
//	{
//		cout << "��ҳ�������Σ���¼��ע��......(����ͷ��)" << endl;
//	}
//	void footer()
//	{
//		cout << "�������ģ�����������վ�ڵ�ͼ......(����β��)" << endl;
//	}
//	void lefter()
//	{
//		cout << "java,python,c++,c......(�������)" << endl;
//	}
//	void content()
//	{
//		cout << "python�γ�" << endl;
//	}
//};


//�̳еķ�ʽ  
//�﷨   class ���� ���̳з�ʽ ����
//�ŵ�   �����ظ�����


//�����Ĳ���
class basepage
{
public:
	void header()
	{
		cout << "��ҳ�������Σ���¼��ע��......(����ͷ��)" << endl;
	}
	void footer()
	{
		cout << "�������ģ�����������վ�ڵ�ͼ......(����β��)" << endl;
	}
	void lefter()
	{
		cout << "java,python,c++,c......(�������)" << endl;
	}
};

//javaҳ��
class java:public basepage    //�̳й�������
{
public:
	void content()
	{
		cout << "java�γ�" << endl;
	}
};


//pythonҳ��
class python:public basepage   //�̳й�������
{
public:
	void content()
	{
		cout << "python�γ�" << endl;
	}
};

void test31()
{
	cout << "javaҳ��" << endl;
	java ja;
	ja.header();
	ja.lefter();
	ja.content();
	ja.footer();

	cout << "*******************************************" << endl;
	cout << "python����" << endl;
	python py;
	py.header();
	py.lefter();
	py.content();
	py.footer();
}

//�̳й���
//���ۺ��ּ̳з�ʽ�������������඼�����Է��ʸ����е�˽������
//�����̳У������еĹ������Ժͱ�����������������Ȼ�ǹ����ͱ�����
//�����̳У������еĹ������Ժͱ��������������ж��Ǳ�������
//˽�м̳У������еĹ������Ժͱ��������������ж���˽������

class base1   //����
{
public:
	int a;
	static int s_a;
protected:
	int b;
private:
	int c;
public:
	base1()  //���캯��
	{
		cout << "�����еĹ��캯��" << endl;
		a = 100;
	}
	~base1()  //��������
	{
		cout << "�����е���������" << endl;
	}
	void func()
	{
		cout << "base1 func" << endl;
	}
	void func(int a)
	{
		cout << "base1 func(int a)" << endl;
	}
	static void func1()
	{
		cout << "base1 static func1" << endl;
	}
	static void func1(int a)
	{
		cout << "base1 static func1(int a)" << endl;
	}
};
int base1::s_a = 100;

class son :public base1   //�����̳�
{
public:
	void func()
	{
		a = 10;  //�����еĹ��� ����������Ȼ�ǹ���
		b = 20;  //�����еı��� ����������Ȼ�Ǳ���
		//c = 30;  //���� �����е�˽�� �������в��ɷ���
	}
};

class son1 :protected base1  //�����̳�
{
public:
	void func()
	{
		a = 10;  //�����еĹ��� ���������Ǳ���
		b = 20;  //�����еı��� ���������Ǳ���
		//c = 30;  //���� �����е�˽�� �������в��ɷ���
	}

};

class son2 :private base1  //˽�м̳�
{
public:
	void func()
	{
		a = 10;  //�����еĹ��� ����������˽��
		b = 20;  //�����еı��� ����������˽��
		//c = 30;  //���� �����е�˽�� �������в��ɷ���
	}

};

void test32()
{
	son s;
	s.a = 100;
	//s.b = 200; //����  �������� ���ⲻ���Խ��з���
}

void test33()
{
	son1 s;
	//s.a = 100;   //���� �������� ���ⲻ���Խ��з���
	//s.b = 200;   //���� �������� ���ⲻ���Խ��з���
}

void test34()
{
	son2 s;
	//s.a = 100;   //���� ˽������ ���ⲻ���Խ��з���
	//s.b = 200;   //���� ˽������ ���ⲻ���Խ��з���
}

//�̳��еĶ���ģ��
class son3 :public base1   //�����еķǾ�̬��Ա���Զ��ᱻ����̳У���ʹ�����Խ��з��ʣ�����ȷʵ�Ǽ̳й�����
{
public:
	int d;
};

class son4 :protected base1   
{
public:
	int d;
};

class son5 :private base1
{
public:
	int d;
};

void test35()
{
	cout << "sizeof(son3)=" << sizeof(son3) << endl;   //��СΪ16�ֽ�,���������е�����
	cout << "sizeof(son4)=" << sizeof(son4) << endl;
	cout << "sizeof(son5)=" << sizeof(son5) << endl;
}

//�̳��еĹ��������������˳��
//�ȸ��๹�죬�����๹�죻
//�������������ٸ���������
class son6 :public base1
{
public:
	son6()  //���캯��
	{
		cout << "�����еĹ��캯��" << endl;
	}
	~son6()  //��������
	{
		cout << "�����е���������" << endl;
	}
};

void test36()
{
	son6 s;
}

//�̳���ͬ����Ա�Ĵ���ʽ
class son7 :public base1
{
public:
	int a;  //�����е�a�븸���е�a������
	static int s_a;
	static void func1()
	{
		cout << "son7 static func1" << endl;
	}
	son7()   //���캯����ʼ��
	{
		a = 200;
	}
	void func()
	{
		cout << "son7 func" << endl;
	}
};
int son7::s_a = 200;   //��̬��Ա���� �������� �����ʼ��


void test37()
{
	son7 s;
	cout << "son   a=" << s.a << endl;
	cout << "base1 a=" << s.base1::a << endl;  //���ʸ����е�ͬ����Ա��Ҫ��������
	s.func();
	s.base1::func();                           //���ʸ����е�ͬ��������Ҫ��������
	s.base1::func(10);
	//ͨ��������ʾ�̬��Ա����
	cout << "son   s_a="<<s.s_a<<endl;
	cout << "base1 s_a=" << s.base1::s_a << endl;
	//ͨ���������ʾ�̬��Ա����
	cout << "son   s_a=" << son7::s_a << endl;
	cout << "base1 s_a=" << son7::base1::s_a << endl;
	//ͨ���������
	s.func1();
	s.base1::func1();
	//ͨ����������
	son7::func1();
	son7::base1::func1();
	son7::base1::func1(100);

}

//int main()
//{
//	//test31();
//	//test35();
//	//test36();
//	test37();
//
//	system("pause");
//	return 0;
//
//}