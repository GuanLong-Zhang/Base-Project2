//��������������� ��װ �̳� ��̬
//�������
# include<iostream>
using namespace std;

//Բ����
const double PI= 3.14;

//����һ��Բ��
class circle
{
	//Ȩ��
public:
	//����    (������
	int c_r;
	//��Ϊ   ��������
	double calculate()
	{
		return 2 * PI * c_r;
	}
};

//����һ��ѧ����
class student
{
	//Ȩ��
public:
	//����  ��Ա����
	string name;
	string number;

	//��Ϊ   ��Ա����
	void fuzhi()
	{
		cout << "������ѧ����Ϣ" << endl;
		cout << "������" << " ";
		cin >> name;
		cout << "ѧ�ţ�" << " ";
		cin >> number;
	}

	void shuchu()
	{
		cout << "���ѧ����Ϣ" << endl;
		cout << "������" << name << endl;
		cout << "ѧ�ţ�" << number << endl;
	}
};

//����Ȩ��
//public     ����  ���ڿ��Է��� ����Ҳ���Խ��з���
//protected  ����  ���ڿ��Է��� ���ⲻ���Խ��з���
//private    ˽��  ���ڿ��Է��� ���ⲻ���Խ��з���


//����һ����ʦ��
class teacher
{
public:
	string name;
protected:
	string car;
private:
	string password;
public:
	void func()   //���ڷ���
	{
		name = "����";
		car = "����";
		password = "123456";
	}
};

//c++��struct �� class ������
//Ĭ�Ϸ���Ȩ�޲�ͬ struct Ĭ�Ϲ��� classĬ��˽��

class A1
{
	int num1;    //Ĭ�Ϸ���Ȩ��Ϊ˽��
};

struct A2
{
	int num2;    //Ĭ�Ϸ���Ȩ��Ϊ����
};

//��Ա��������Ϊ˽�еĺô�
//1.�����Լ����ö�дȨ��
//2.����д���Լ�����ݵ���Ч��

class Person
{
public:   //������Ա����
	void setname(string s)  //��д
	{
		name = s;
	}
	string getname()    //�ɶ�
	{
		return name;
	}
	void setage(int a)   //��д
	{
		if (a < 0 || a>150)
		{
			cout << "�����������" << endl;
			age = 0;
			return;   //��Ҫ����return���ؽ������Ȼ������Ǵ����
		}
		age = a;
	}
	int getage()     //�ɶ�
	{
		return age;
	}

	void setlover(string s)  //��д
	{
		lover = s;
	}

private:   //˽�г�Ա
	string name;    //�ɶ���д
	int age;        //ֻ��
	string lover;   //ֻд

};

//int main()
//{
//	//����һ������
//	circle c1;
//	c1.c_r = 10;
//	cout << "Բ���ܳ�Ϊ��" << c1.calculate() << endl;
//
//	//����һ������
//	student a1;
//	//��ֵ
//	a1.fuzhi();
//	//���
//	a1.shuchu();
//
//	teacher t1;
//	t1.name = "����";
//	//t1.car = "����";    //����Ȩ�� ���ⲻ���Խ��з���  �ᱨ��
//	//t1.password = "123";  //˽��Ȩ�� ���ⲻ���Խ��з���  �ᱨ��
//
//	//����һ������
//	A1 A1;
//	//A1.num1 = 10;   //���� �����Խ��з���
//	A2 A2;
//	A2.num2 = 20;   //��������
//
//	//����һ������
//	Person P;
//	P.setname("����");  //��д
//	cout<<"����Ϊ��"<<P.getname()<<endl;        //�ɶ�
//	P.setage(1800);   //��д
//	cout<<"����Ϊ��"<<P.getage()<<endl;   //�ɶ�
//	P.setlover("����");   //��д
//	system("pause");
//	return 0;
//}