# include<iostream>
using namespace std;

//�������

//������Ĭ�ϲ���
int funcation0(int a, int b, int c)  //����Ĭ��ֵ
{
	return a + b + c;
}

int funcation1(int a, int b=20, int c=30)   //��Ĭ��ֵ  ���ĳ��λ���Ѿ���Ĭ�ϲ������Ǹ������λ�����󣬶���ҪĬ�ϲ���,��Ȼ�ᱨ��
{
	return a + b + c;
}

//���������ͺ���ʵ��ֻ����һ����ΪĬ��ֵ�������������Ĭ��ֵ���ͻᷢ�����壬���оͻᱨ��

//����ռλ����
void funcation2(int a,int)    //��int��ʾռλ����  ռλ����������Ĭ�ϵ�ֵ
{
	cout << "this is a funcation2" << endl;
}

void funcation3(int a, int=10)    //ռλ����������Ĭ�ϵ�ֵ
{
	cout << "this is a funcation3" << endl;
}

//��������
//��Ҫ������������� ��1��������ͬһ���������� 2������������ͬ 3�������������Ͳ�ͬ �������ͬ ��˳��ͬ

void funcation()
{
	cout << "1" << endl;
}

void funcation(int a)
{
	cout << "2" << endl;
}

void funcation(double a)
{
	cout << "3" << endl;
}

void funcation(double a,int b)
{
	cout << "4" << endl;
}

void funcation(int a,double b)
{
	cout << "5" << endl;
}

// �������ص�ע������
// ������Ϊ��������
void funcation(float & a)
{
	cout << "6" << endl;
}

void funcation(const float& a)
{
	cout << "7" << endl;
}

//��������������Ĭ�ϲ�������Ҫ���������õ�ʱ�����׳��ֶ����ԣ��ᱨ��

//int main()
//{
//	cout<<"������������Ӻ�Ϊ��"<<funcation0(10, 20, 30)<<endl;   
//	cout<< "������������Ӻ�Ϊ��"<< funcation1(10,30) << endl;     //����ֵ���ô���ֵ��û�д�����Ĭ��ֵ
//	funcation2(10, 10);   //����ռλ�������������䣬��Ȼ�ᱨ��
//	funcation3(10);
//	cout << "**************************" << endl;
//	funcation();
//	funcation(10);
//	funcation(3.14);
//	funcation(3.14, 6);
//	funcation(6,3.14);
//	float a = 3.14;
//	funcation(a);
//	system("pause");
//	return 0;
//
//}