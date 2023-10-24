#include<iostream>
using namespace std;

//��̬

//������
class animal
{
public:
	virtual void speak()   //�麯��   �麯����ָ�� �麯����
	{
		cout << "animal is speaking" << endl;
	}
};

//è��
class cat :public animal
{ 
	virtual void speak()   //��д�ĺ������滻���̳��Ը��������
	{
		cout << "cat is speaking" << endl;
	}
};

//����
class dog :public animal
{
	virtual void speak()
	{
		cout << "dog is speaking" << endl;
	}
};

//��ַ�ڱ���׶ξ�ȷ���ˣ��������۴���ʲô����animal
//����virtual ��ʵ���˵�ַ��󶨣������н׶ε�ַ��ȷ��
//��̬��̬��ʹ�ã������ָ�������ȥָ������Ķ���
void dospeak(animal& a)    //���������ָ���������
{
	a.speak();
}

void test51()
{
	cat c;
	dospeak(c);
	dog d;
	dospeak(d);
}

void test52()
{
	cout << "sizeof(animal) =  " << sizeof(animal) << endl;    //����virtual��СΪ1��Ϊ���ࣻ����virtual��СΪ4
}

//��̬����1-������
//��ͨд��
class calculate
{
public:
	int m1;
	int m2;
	int getrusult(string p)
	{
		if (p == "+")
		{
			return m1 + m2;
		}
		else if (p == "-")
		{
			return m1 - m2;
		}
		else if (p == "*")
		{
			return m1 * m2;
		}
		else
		{
			return m1 / m2;
		}
	}

	void fuzhi(int a, int b)
	{
		m1 = a;
		m2 = b;
	}
};

void test53()
{
	int a;
	int b;
	calculate c;
	cout << "��������������" << endl;
	cin >> a >> b;
	c.fuzhi(a, b);
	cout << "�����������Ϊ��" << c.getrusult("+") << endl;
	cout << "�����������Ϊ��" << c.getrusult("-") << endl;
	cout << "�����������Ϊ��" << c.getrusult("*") << endl;
	cout << "�����������Ϊ��" << c.getrusult("/") << endl;
}

//��̬д��
//���������
class abstractcalculate
{
public:
	int m1;
	int m2;
	virtual int getresult()   //�麯��
	{
		return 0;
	}
};

//�ӷ�
class addcalculate:public abstractcalculate
{
public:
	virtual int getresult()
	{
		return m1 + m2;
	}
};

//����
class subcalculate :public abstractcalculate
{
public:
	virtual int getresult()
	{
		return m1 - m2;
	}
};

//�˷�
class chengcalculate :public abstractcalculate
{
public:
	virtual int getresult()
	{
		return m1 * m2;
	}
};

//����
class chucalculate :public abstractcalculate
{
public:
	virtual int getresult()
	{
		return m1 / m2;
	}
};

void test54()
{
	int a;
	int b;
	cout << "��������������" << endl;
	cin >> a >> b;

	abstractcalculate* ab = new addcalculate;   //new���ٵ��ڴ�ռ���һ��ָ��  �����ָ��ָ���������
	ab->m1 = a;
	ab->m2 = b;
	cout << "�����������Ϊ��" << ab->getresult() << endl;
	delete ab;

	ab  = new subcalculate;
	ab->m1 = a;
	ab->m2 = b;
	cout << "�����������Ϊ��" << ab->getresult() << endl;
	delete ab;

	ab = new chengcalculate;
	ab->m1 = a;
	ab->m2 = b;
	cout << "�����������Ϊ��" << ab->getresult() << endl;
	delete ab;

	ab = new chucalculate;
	ab->m1 = a;
	ab->m2 = b;
	cout << "�����������Ϊ��" << ab->getresult() << endl;
	delete ab;

}

//���麯���ͳ�����
//ֻҪ������һ�����麯������ô�������ǳ�����
//�ص㣺�������޷�ʵ��������
//      ���������д�������еĴ��麯��������Ҳ�ǳ�����
class base4
{
public:
	virtual void func() = 0;   //���麯��
};

class son9 :public base4
{
public:
	virtual void func()   //��д���麯��������Ҳ�ǳ�����
	{
		cout << "func ����" << endl;
	}
};

void test55()
{
	//base4 b;   //���� �������޷�ʵ��������
	//son9 s;
	base4* b = new son9;   //����ָ��ָ���������
	b->func();
}

//��̬����2-������Ʒ
//��������
class abstractdrink
{
public:
	virtual void boil() = 0;   //���麯��
	virtual void brew() = 0;
	virtual void pourincup() = 0;
	virtual void putsoming() = 0;
	void makedrink()
	{
		boil();
		brew();
		pourincup();
		putsoming();
	}
};

class coffe :public abstractdrink
{
public:
	virtual void boil()
	{
		cout << "��ˮ" << endl;
	}
	virtual void brew()
	{
		cout << "�忧��" << endl;
	}
	virtual void pourincup()
	{
		cout << "���뱭��" << endl;
	}
	virtual void putsoming()
	{
		cout << "�����Ǻ�ţ��" << endl;
	}

};

class tea :public abstractdrink
{
public:
	virtual void boil()
	{
		cout << "��ˮ" << endl;
	}
	virtual void brew()
	{
		cout << "���" << endl;
	}
	virtual void pourincup()
	{
		cout << "���뱭��" << endl;
	}
	virtual void putsoming()
	{
		cout << "��������" << endl;
	}

};

void test56()
{
	abstractdrink* ab = new coffe;  //����ָ��ָ������
	ab->makedrink();
	delete ab;

	cout << "----------------------" << endl;
	ab = new tea;
	ab->makedrink();
	delete ab;
}

//�������ʹ�������
class animal1
{
public:
	virtual void speak() = 0;   //���麯��
	animal1()
	{
		cout << "animal1 �Ĺ��캯��" << endl;
	}
	//virtual ~animal1()         //������   �������ָ���ͷ��������Ĺ���
	//{
	//	cout << "animal1 ����������" << endl;
	//}

	virtual ~animal1() = 0;   //��������  �ڲ������ⲿʵ��    �������ָ���ͷ��������Ĺ���
};

//�ⲿ����
animal1::~animal1()
{
	cout << "animal1 ����������" << endl;
}

class cat1 :public animal1
{
public:
	string* st;
	cat1(string s)   //���캯��
	{
		cout << "cat1 �Ĺ��캯��" << endl;
		st = new string(s);  //new���ص���ָ��
	}
	virtual void speak()     //������д���麯��
	{
		cout << *st << " " << "cat is speaking" << endl;
	}
	~cat1()   //�������� �����ͷ�
	{
		if (st != NULL)
		{
			cout << "cat1 ����������" << endl;
			delete st;   //�ͷ� Ȼ���ÿ�
			st = NULL;
		}
	}
};

void test57()
{
	animal1* a = new cat1("Tom");    //�����ָ��ָ������
	a->speak();
	//����ָ���޷������������� ��Ҫ�ڸ��������м���virtual,�����Ϊ�������������Ϳ����ͷ�������
	//���ô�������Ҳ����ʵ���������ܣ��������ڴ���������Ҫ������ж���
	delete a;
}

//��̬����3-������װ
//����cpu
class cpu
{
public:
	virtual void calculate() = 0;   //���麯��
};

//����gpu
class gpu
{
public:
	virtual void display() = 0;   //���麯��
};

//����memory
class memory
{
public:
	virtual void storage() = 0;   //���麯��
};

class computer
{
public:
	computer(cpu* c1, gpu* g1, memory* m1)  //���캯��
	{
		c = c1;
		g = g1;
		m = m1;
	}
	void dowork()
	{
		c->calculate();   //����ָ���������
		g->display();
		m->storage();
	}

	~computer()   //�������� �ͷ�
	{
		if (c != NULL)
		{
			delete c;
			c = NULL;
		}
		if (g != NULL)
		{
			delete g;
			g = NULL;
		}
		if (m != NULL)
		{
			delete m;
			m = NULL;
		}
	}
private:
	cpu* c;
	gpu* g;
	memory* m;
};

//inter
class intercpu :public cpu
{
public:
	virtual void calculate()   //��д�麯��
	{
		cout << "inter cpu" << endl;
	}
};

class intergpu :public gpu
{
public:
	virtual void display()   //��д�麯��
	{
		cout << "inter gpu" << endl;
	}
};

class intermemory :public memory
{
public:
	virtual void storage()   //��д�麯��
	{
		cout << "inter memory" << endl;
	}
};

//amd
class amdcpu :public cpu
{
public:
	virtual void calculate()   //��д�麯��
	{
		cout << "amd cpu" << endl;
	}
};

class amdgpu :public gpu
{
public:
	virtual void display()   //��д�麯��
	{
		cout << "amd gpu" << endl;
	}
};

class amdmemory :public memory
{
public:
	virtual void storage()   //��д�麯��
	{
		cout << "amd memory" << endl;
	}
};

void test58()
{
	//�������
	cpu* c = new intercpu;   //����ָ��ָ������
	gpu* g = new intergpu;
	memory* m = new intermemory;

	//����һ������
	computer *cu = new computer(c, g, m);  //����ָ��
	cu->dowork();
	delete cu;

	cout << "-------------------------------" << endl;

	//�������
	cpu* c1 = new amdcpu;   //����ָ��ָ������
	gpu* g1 = new amdgpu;
	memory* m1 = new amdmemory;

	//����һ������
	computer* cu1 = new computer(c1, g1, m1);  //����ָ��
	cu1->dowork();
	delete cu1;

	cout << "-------------------------------" << endl;

	//�������
	cpu* c2 = new intercpu;   //����ָ��ָ������
	gpu* g2 = new amdgpu;
	memory* m2 = new intermemory;

	//����һ������
	computer* cu2 = new computer(c2, g2, m2);  //����ָ��
	cu2->dowork();
	delete cu2;

}

//int main()
//{
//	//test51();
//	//test52();
//	//test53();
//	//test54();
//	//test55();
//	//test56();
//	//test57();
//	test58();
//
//	system("pause");
//	return 0;
//}