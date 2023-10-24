# include<iostream>
using namespace std;

//���������

//�Ӻ����������
//�������������
class car
{
public:
	int m_a;
	int m_b;

	//��Ա�������ؼӺ�
	//car operator+(car& p)  //car��ʾ����ֵ������
	//{
	//	car temp;
	//	temp.m_a = m_a + p.m_a;
	//	temp.m_b = m_b + p.m_b;
	//	return temp;
	//}

};

//ȫ�ֺ������ؼӺ�
car operator+(car& c1, car& c2)
{
	car temp;
	temp.m_a = c1.m_a + c2.m_a;
	temp.m_b = c1.m_b + c2.m_b;
	return temp;
}

car operator+(car& c1, int num)
{
	car temp;
	temp.m_a = c1.m_a + num;
	temp.m_b = c1.m_b + num;
	return temp;
}

//ȫ�ֺ����������������
ostream& operator<<(ostream& cout, car& p)
{
	cout << "m_a=" << p.m_a << endl;
	cout << "m_b=" << p.m_b <<endl;	
	return cout;
}

void test20()
{
	car p1;
	p1.m_a = 10;
	p1.m_b = 20;
	car p2;
	p2.m_a = 30;
	p2.m_b = 40;

	car p3 = p1 + p2; 
	car p4 = p1 + 100;
	//car p3 = p1.operator+(p2);  //��Ա��������+�ı���
	//car p3 = operator+(p1, p2); //ȫ�ֺ�������+�ı���

	cout << "p3.m_a=" << p3.m_a << endl;
	cout << "p3.m_b=" << p3.m_b << endl;

	cout << "p4.m_a=" << p4.m_a << endl;
	cout << "p4.m_b=" << p4.m_b << endl;

	cout << p1 << p2;   //�������������Ӧ��
}

//ԭʼ�����Ĳ���
void test21()
{
	int a = 10;
	int b = 20;
	cout << ++a << endl;  //11
	cout << a << endl;    //11

	cout << b++ << endl;  //20
	cout << b << endl;    //21

}

//�������������
class car1
{
	friend ostream& operator<<(ostream& cout, car1& p);
public:
	car1()   //���캯��
	{
		num = 2;
	}
	
	//����ǰ��++�����  ����������Ϊ��һֱָ��ͬһ�����ݽ��е�������
	car1& operator++()
	{
		//��++������
		num++;
		return *this;

	}

	//���غ���++����� 
	car1& operator++(int)   //intΪռλ������Ϊ������ǰ��++�ͺ���++  ���÷���ֵ
	{
		car1 temp = * this;   //*thisΪ����
		num++;
		return temp;

	}

	//����ǰ��--�����
	car1& operator--()
	{
		num--;
		return *this;
	}

	//���غ���--�����
	car1& operator--(int)
	{
		car1 temp = *this;
		num--;
		return temp;
	}

private:
	int num;
};

ostream& operator<<(ostream& cout, car1& p)   //�������������
{
	cout << p.num << endl;
	return cout;
}


void test22()
{
	car1 cara;
	cout << ++(++cara);
	cout << cara;
}

void test23()
{
	car1 cara1;
	cout<<cara1++;
	cout << cara1;
}

void test24()
{
	car1 cara2;
	cout << --(--cara2);
	cout << cara2;
}

void test25()
{
	car1 cara2;
	cout << cara2--;
	cout << cara2;
}

//��ֵ���������
class car2
{
public:
	int* age2;
	car2(int age)  //���캯��
	{
		age2 = new int(age);   //age2��ŵ���һ����ַ ����new���ٵ��ڴ淵�ص���һ��ָ�� ()�ڵ������Ǿ����ֵ
	}
	~car2()   //�������� �ͷſռ� Ĭ���޲�
	{
		if (age2 != NULL)
		{
			delete age2;   //�ͷ�֮�� Ȼ���ÿ�
			age2 = NULL;
		}
	}
	car2& operator=(car2& p)  //��ֵ����
	{
		if (age2 != NULL)   //���ͷſռ䣬�ٽ��п����µĿռ�
		{
			delete age2;
			age2 = NULL;
		}
		age2 = new int(*p.age2);  //���
		return *this;  //����*this���ر���
	}
};

void test26()
{
	car2 c2(18);   //Ĭ�ϵ��ù��캯����������Ҫ���и���ֵ�Ĳ�������ֵΪ18
	car2 c3(20);
	car2 c4(30);
	c4 = c3 = c2;   // ǳ���� ��ֵ�����󣬽����������ͷţ����ͷ�c3 ���ͷ�c2,�ᱨ���ڴ��ظ��ͷ�

	cout << "c2����Ϊ��"<< *c2.age2 << endl;   //Ҫ���ֵ��Ҫ��*�����н�����
	cout << "c3����Ϊ��"<< *c3.age2 << endl;
	cout << "c4����Ϊ��" << *c4.age2 << endl;

}

//��ϵ���������  ==  !=
class car3
{
public:
	string name;
	int age;
	car3(string a, int b)   //�вι��츳��ֵ
	{
		name = a;
		age = b;
	}
	bool operator==(car3& p)    //����==
	{
		if (this->name == p.name && this->age == p.age)
		{
			return true;
		}
		return false;
	}
	bool operator!=(car3& p)    //����!=
	{
		if (this->name == p.name && this->age == p.age)
		{
			return false;
		}
		return true;
	}

};

void test27()
{
	car3 cc("С��", 20);
	car3 cc1("С��", 20);
	//cout << "������"<< cc.name << endl;
	//cout << "���䣺"<< cc.age << endl;
	if (cc == cc1)
	{
		cout << "������Ϣ��ͬ" << endl;
	}
	else
	{
		cout << "������Ϣ��ͬ" << endl;
	}
	if (cc != cc1)
	{
		cout << "������Ϣ��ͬ" << endl;
	}
	else
	{
		cout << "������Ϣ��ͬ" << endl;
	}
}

//������������
class car4
{
public:
	void operator()(string a)   //������������
	{
		cout << a << endl;
	}

	void operator()(int a, int b)
	{
		cout<< a + b <<endl;
	}
};

void c1(string a)
{
	cout << a << endl;
}

void test28()
{
	car4 c;
	c("hello world!");    //�����������غ��������ã����Գ�Ϊ�º���
	c1("hello world!");   //���溯������
	c(10, 20);
	//��������  û����ʾ��ȥ������󣬶��ǲ�������()����ʽ���������
	car4()(20, 30);
}

//int main()
//{
//	//test20();
//	//test21();
//	//test22();
//	//test23();
//	//test24();
//	//test25();
//	//test26();
//	//test27();
//	test28();
//
//	system("pause");
//	return 0;
//}