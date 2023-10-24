# include<iostream>
using namespace std;
# include<fstream>
# include<string>

//�ı��ļ�
//д�ļ�
void test61()
{
	//1 ����ͷ�ļ�<fstream>
	
	//2 ����������
	ofstream ofs;   //д
	//3 ָ���򿪷�ʽ
	ofs.open("test.txt", ios::out);  //�򿪷�ʽ д ios::out
	//4 д����
	ofs << "����������" << endl;
	ofs << "����������" << endl;
	ofs << "����������" << endl;
	//5 �ر�
	ofs.close();
}

//���ļ�
void test62()
{
	//1 ����ͷ�ļ�<fstream>

	//2 ����������
	ifstream ifs;   //��
	//3 ���ļ� �����ж��Ƿ�ɹ���
	ifs.open("test.txt", ios::in);    //�򿪷�ʽ  ��ios::in
	
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//4 ������
	//��ʽһ
	//char b[1024] = { 0 };  
	//while (ifs >> b)
	//{
	//	cout << b << endl;
	//}
	
	//��ʽ��
	//char b[1024] = { 0 };
	//while (ifs.getline(b,sizeof(b)))
	//{
	//	cout << b << endl;
	//}

	//��ʽ��
	string b;
	while ( getline(ifs,b))
	{
		cout << b << endl;
	}

	//��ʽ��
	//char c;
	//while ((c = ifs.get()) != EOF)
	//{
	//	cout << c;
	//}

	//5 �ر�
	ifs.close();

}

//�������ļ�
//д�ļ�
class base5
{
public:
	char name[64];
	int age;
};

void test63()
{
	//1 ����ͷ�ļ�<fstream>

	//2 ����������
	ofstream ofs;   //д
	//3 ָ���򿪷�ʽ
	ofs.open("person.txt", ios::out|ios::binary);  //�򿪷�ʽ д ios::out   ������ ios::binary
	//4 д����
	base5 b = { "����",18 };
	ofs.write((const char*)&b, sizeof(b));
	//5 �ر�
	ofs.close();
}

//���ļ�
void test64()
{
	//1 ����ͷ�ļ�<fstream>

	//2 ����������
	ifstream ifs;   //��
	//3 ���ļ� �ж��Ƿ�򿪳ɹ�
	ifs.open("person.txt", ios::in | ios::binary);  //�򿪷�ʽ �� ios::in   ������ ios::binary
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//4 ������
	base5 b;
	ifs.read((char *)&b,sizeof(b));
	cout << "������"<< b.name << endl;
	cout << "���䣺"<< b.age << endl;
	//5 �ر�
	ifs.close();
}

//int main()
//{
//	//test61();
//	//test62();
//	//test63();
//	test64();
//
//	system("pause");
//	return 0;
//}