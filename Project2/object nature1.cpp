# include <iostream>
using namespace std;

//��������
//�������Ϊ������ĳ�Ա  �򵥵�˵��������������

//�ֻ���
class phone
{
public:
	string phone_name;
	phone(string name)
	{
		cout << "phone���캯������" << endl;
		phone_name = name;
	}
	~phone()
	{
		cout << "phone������������" << endl;
	}
};

//�����а����ֻ��࣬
//�ȵ����ֻ���Ĺ��캯�����ٵ�������Ĺ��캯����
//���ͷ���������������ͷ��ֻ�������;

class person1   
{
public:
	int a1;
	int b1;
	int c1;
	string name;
	phone p_n;    //�ֻ������

	//��ͳ��ʼ��  �����вι��캯�����г�ʼ��
	//person(int a, int b, int c)
	//{
	//	a1 = a;
	//	b1 = b;
	//	c1 = c;
	//	cout << "�����вι��캯�����г�ʼ��" << endl;
	//}

	//��ʼ���б���г�ʼ��
	person1(int a,int b,int c, string d ,string e) :a1(a), b1(b), c1(c),name(d),p_n(e)
	{
		cout << "person1���캯������" << endl;
	}
	~person1()
	{
		cout << "person1������������" << endl;
	}

};

class person2
{
public:
	static int age;   //��̬��Ա����   1.���ж�����Ҫͬһ������ 2.����׶ξͷ������ڴ�  3.�������� ������г�ʼ��
	static void funcation()   //��̬��Ա����   ��̬��Ա����ֻ�ܶԾ�̬��Ա�������з���
	{
		age = 100;  
		//age1 = 200;    //������Ϊage1Ϊ�Ǿ�̬��Ա����
		cout << "��̬��Ա�����ĵ���" << endl;
	}
	int age1;
private:
	static int agea;

};

int person2::age = 10;  //�����ʼ����̬��Ա����
int person2::agea = 10;

void test01()
{
	person2 p;
	cout <<"����Ϊ��"<< p.age << endl;  //ͨ���������󣬷��ʾ�̬��Ա����
	person2 p1;
	p1.age = 20;
	cout << "����Ϊ��" << p.age << endl;   //����ͬһ�����ݣ���Ȼ����p1�����޸ĵģ�������p���з��ʵ�ʱ��ֵ��Ȼ��������
	cout << "����Ϊ��" << person2::age << endl;  //ͨ���������з��ʾ�̬��Ա����   �������ı�������������ĵط�
	//cout << "����Ϊ��" << person11::agea << endl;  //����agea��˽�еĲ����Խ��з���
	person2 p2;
	p2.funcation();   //ͨ���������󣬷��ʾ�̬��Ա����
	person2::funcation();  //ͨ���������з��ʾ�̬��Ա����

}

void test00()
{
	person1 p(10, 20, 30,"����","ƻ���ֻ�");
	cout << "a����" << p.a1 << endl;
	cout << "b����" << p.b1 << endl;
	cout << "c����" << p.c1 << endl;
	cout << "������" << p.name << endl;
	cout << "�ֻ���" << p.p_n.phone_name << endl;
}

class person3
{
public:
	int ma;   //�Ǿ�̬��Ա����  ������Ķ�����
	static int mb;  //��̬��Ա���� ��������Ķ�����
	void funcation1() {}  //�Ǿ�̬��Ա����  ��������Ķ�����
	static void funcation2() {}  //��̬��Ա����   ��������Ķ�����
	int age;
	person3()    //�޲ι���
	{

	}
	person3(int age)   //�вι���
	{
		this->age = age;    //this->�������Ƿ�ֹ���Ƴ�ͻ
	}
	person3& personaddperson( person3 &p)
	{
		this->age += p.age;
		return *this;    //����ָ��ı���,�����Ϳ����ظ�����һ������
	}
};


int person3::mb = 0;

void test02()
{
	person3 p;
	//C++��Ϊÿ���ն������һ���ֽڿռ䣬Ŀ����Ϊ������ÿ���ն�����ռ���ڴ�ռ�
	cout << "�ն�����ռ���ڴ�ռ䣺"<<sizeof(p) << endl;   //�ն�����ռ��һ���ֽ�
}

void test03()
{
	person3 p;
	cout << "�Ǿ�̬��Ա������ռ���ڴ�ռ䣺" << sizeof(p) << endl;   //ռ���ĸ��ֽ�  intռ��4���ֽ�
}

void test04()
{
	person3 p(18);
	cout << "����Ϊ��" << p.age << endl;
}

void test05()
{
	person3 p1(10);
	person3 p2(20);
	//p2.personaddperson(p1);
	//��ʽ���˼��
	p2.personaddperson(p1).personaddperson(p1).personaddperson(p1);
	cout << "����Ϊ��" << p2.age << endl;
}

class person4
{
public:
	int age;
	mutable int m_age;    //����mutableʹ���ڳ���������Ȼ���Ըı�ֵ�Ĵ�С
	void showclassname()
	{
		cout << "this is a person4 class" << endl;
	}
	void showpersonage()
	{
		if (this == NULL)   //����ָ��Ϊ��
		{
			return;
		}
		cout << "age=" << age << endl;
	}
	//�����ź������const�ͻᱨ��thisָ��ı��ʾ���ָ�볣�� ��ָ�򲻿��Խ����޸ģ�
	//�����ź������constʹ��ָ���ֵҲ�����Խ����޸��ˣ����Իᱨ��
	//������
	void showperson() const 
	{
		//age = 100;
		m_age = 100;
	}
};

//��ָ����ʳ�Ա����
void test06()
{
	person4 * p = NULL;
	p->showclassname();
	p->showpersonage();   //����һ���ղ�������Ϊ�����ָ��Ϊ��
	const person4 pa;     //������
	//pa.age = 200;       //����������ָ���ֵ�����Խ����޸�
	pa.m_age = 200;       //��ȷ��mutable���ε�ֵ���Խ����޸�
	pa.showperson();      //������ֻ�ܷ��ʳ�����
	

}

//int main()
//{
//	//test00();
//	//test01();
//	//test02();
//	//test03();
//	//test04();
//	//test05();
//	test06();
//	system("pause");
//	return 0;
//}